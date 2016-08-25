/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:34:36 by rojones           #+#    #+#             */
/*   Updated: 2016/08/25 12:31:22 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	loop_processes(t_env *env, int check)
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
		pro = (t_process *)mv->content;
		if (check == 1)
		{
			if (pro->player->live == 0)
				destroy_process(mv, pre);
			else 
			{
				if (pro->player->live >= NBR_LIVE)
					mod = 1;
				run_process(env, pro);
				env->last_alive = pro->player;
				pre = mv;
				mv = mv->next;
			}
			pro->player->live = 0;
		}
		else
		{
			run_process(env, pro);
			pre = mv;
			mv = mv->next;
		}
	}
	return (mod);
}

static void	print_last_alive(t_player *player)
{
	ft_putstr("Player ");
	ft_putnbr(player->number);
	ft_putstr(" (");
	ft_putstr(player->player_ref.prog_name);
	ft_putstr(") won");
}

void	run_simulation(t_env *env)
{
	int			check;
	int			mod;
	
	while (env->processes && env->cycle <= env->dump_cycle && env->cycles_to_die > 0)
	{
		check = 0;
		mod = 0;
		if (env->cycle && env->cycle % env->cycles_to_die == 0)
			check = 1;
		mod += loop_processes(env, check);
		if(check == 1 && mod == 0)
			env->check_for_mod++;
		if (env->check_for_mod == MAX_CHECKS || mod > 0)
		{
			env->cycles_to_die = env->cycles_to_die - CYCLE_DELTA;
			env->check_for_mod = 0;
		}
		env->cycle++;
	}
	if (env->cycle == env->dump_cycle)
		dump_memory(env->memory);
	else
		print_last_alive(env->last_alive);
}
