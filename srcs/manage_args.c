/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:44:02 by khansman          #+#    #+#             */
/*   Updated: 2016/08/24 11:29:13 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_list(t_env *env)
{
	int		k;
	t_list		*list;
	t_list		*element;
	t_process	process;

	k = -1;
	ft_bzero(&process, sizeof(process));
	while (++k < env->num_players)
	{
		process.player = &(env->players[k]);
		if (!(process.registers = (reg_t *)malloc(REG_NUMBER)))
			error_quit(0);
		ft_bzero(process.registers, REG_NUMBER);
		if (!(element = ft_lstnew(&process, sizeof(t_process))))
			error_quit(0);
		if (!env->processes)
		{
			env->processes = element;
			list = env->processes;
		}
		else
		{
			list->next = element;
			list = list->next;
		}
	}
}

void	manage_args(t_env *env, int argc, char **argv)
{
	int		k;

	k = 0;
	if (argc <= 1)
		error_quit(1);
	while (++k < argc)
	{
		if (!ft_strcmp(argv[k], "-dump"))
			k += ft_set_dump_cycle(env, argv[k + 1]);
		else if (!ft_strcmp(argv[k], "-n") && argv[k + 1] && argv[k + 2])
			k += ft_set_player_number(env, argv[k + 1], argv[k + 2]);
		else if (!ft_strcmp(argv[k], "-n") && (!argv[k + 1] || !argv[k + 2]))
			error_quit(4);
		else
			ft_set_player_number(env, NULL, argv[k]);
	}
	init_list(env);
}
