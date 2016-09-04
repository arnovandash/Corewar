/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:53:22 by khansman          #+#    #+#             */
/*   Updated: 2016/09/04 12:23:07 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The functions in this file are for initialising the enviroment variables.
*/

static int	ft_auto_set(t_env *env)
{
	int num;
	int	k;

	k = 0;
	num = -1;
	while (k == 0 && ++num < MAX_PLAYERS)
	{
		if (env->players[num].init == 0)
		{
			env->players[num].number = num;
			k = 1;
		}
	}
	return (num);
}

int			ft_set_player_number(t_env *env, char *s1, char *s2)
{
	int		num;
	int		k;

	num = (s1) ? ft_atoi(s1) : -1;
	k = 0;
	if (!s2 || (s1 && !ft_are_all_digits(s1)) || (num >= MAX_PLAYERS))
		error_quit(4);
	else if (env->num_players >= MAX_PLAYERS)
		error_quit(6);
	else if (s1 != NULL)
	{
		if (env->players[num].init == 1)
			error_quit(5);
		env->players[num].number = num;
	}
	else
		num = ft_auto_set(env);
	env->players[num].file_name = ft_strdup(s2);
	env->players[num].init = 1;
	env->num_players++;
	return ((s1 == NULL) ? 1 : 2);
}

int			ft_set_dump_cycle(t_env *env, char *str)
{
	static int	set;

	if (set)
		error_quit(2);
	else if (!str || !ft_are_all_digits(str))
		error_quit(3);
	else
		env->dump_cycle = ft_atoi(str);
	return (1);
}

void		init_env(t_env *env)
{
	int	i;

	i = MAX_PLAYERS;
	if (!(env->memory = malloc(MEM_SIZE)))
		error_quit(0);
	ft_bzero(env->memory, (MEM_SIZE));
	while (i--)
		env->players[i].init = 0;
	env->n_processes = 0;
	env->num_players = 0;
	env->cycle = 0;
	env->cycles_to_die = CYCLE_TO_DIE;
	env->dump_cycle = LONG_MAX;
	env->last_alive = NULL;
	env->processes = NULL;
}
