/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:34:36 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 12:42:54 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_process(t_list **mv, t_list **pre, t_env *env,
		t_process *pro)
{
	int mod;

	mod = 0;
	if (pro->player->live == 0)
		destroy_process(mv, pre, &env->processes);
	else
	{
		if (pro->player->live >= NBR_LIVE)
			mod = 1;
		run_process(env, pro);
		env->last_alive = pro->player;
		*pre = *mv;
		*mv = (*mv)->next;
	}
	return (mod);
}

static void	reset_live(t_env *env)
{
	int	i;

	i = -1;
	while (++i < MAX_PLAYERS)
		env->players[i].live = 0;
}

static int	loop_processes(t_env *env, int *check)
{
	t_list		*mv;
	t_list		*pre;
	t_process	*pro;
	int			mod;

	mv = env->processes;
	pre = NULL;
	mod = 0;
	while (mv)
	{
		pro = (t_process *)(mv)->content;
		if (*check == 1)
			mod += check_process(&mv, &pre, env, pro);
		else
		{
			run_process(env, pro);
			pre = mv;
			(mv) = (mv)->next;
		}
	}
	if (*check == 1)
		reset_live(env);
	*check = 0;
	return (mod);
}

static void	print_last_alive(t_player *player)
{
	if (player)
	{
		ft_putstr("Player ");
		ft_putnbr(player->number);
		ft_putstr(" (");
		ft_putstr(player->player_ref.prog_name);
		ft_putstr(") won\n");
	}
	else
		ft_putstr("no one reported alive\n");
}

void		run_simulation(t_env *env)
{
	int			check;
	int			mod;
	int			dump;
	t_ulint		cycle_to_check;

	dump = 0;
	cycle_to_check = 0;
	check = 0;
	while (env->processes && dump == 0 && env->cycles_to_die > 0)
	{
		mod = 0;
		mod = loop_processes(env, &check);
		if (env->cycle != 0 && cycle_to_check == env->cycles_to_die &&
				(check = 1))
			cycle_to_check = 0;
		(check == 1 && mod == 0) ? env->check_for_mod++ : 0;
		if ((env->check_for_mod == MAX_CHECKS || mod > 0) &&
				(env->check_for_mod = 0) == 0)
			env->cycles_to_die = (env->cycles_to_die > CYCLE_DELTA) ?
				env->cycles_to_die - CYCLE_DELTA : 0;
		cycle_to_check++;
		(env->cycle++ == env->dump_cycle) ? (dump = 1) : 0;
	}
	(dump == 1) ? dump_memory(env->memory, MEM_SIZE, 32) :
		print_last_alive(env->last_alive);
}
