/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:44:02 by khansman          #+#    #+#             */
/*   Updated: 2016/09/03 12:17:28 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_save_value(char_u *reg, ul_int value)
{
	reg[0] = (value & 0b11111111000000000000000000000000) >> 24;
	reg[1] = (value & 0b00000000111111110000000000000000) >> 16;
	reg[2] = (value & 0b00000000000000001111111100000000) >> 8;
	reg[3] = (value & 0b00000000000000000000000011111111);
}

void		init_list(t_env *env)
{
	int			k;
	t_list		*element;
	t_process	process;

	k = -1;
	ft_bzero(&process, sizeof(process));
	while (++k < MAX_PLAYERS)
	{
		if (env->players[k].init == 1)
		{
			if (!(PRO_REG = (t_reg *)malloc(REG_NUMBER * REG_SIZ)))
				error_quit(0);
			process.player = &(env->players[k]);
			ft_bzero(process.registers, REG_NUMBER * sizeof(reg_t));
			ft_save_value(process.registers[0],
					((ul_int)(env->players[k].number)));
			process.cycle_to_next = 0;
			if (!(element = ft_lstnew(&process, sizeof(t_process))))
				error_quit(0);
			if (!env->processes)
				env->processes = element;
			else
				ft_lstadd(&env->processes, element);
		}
	}
}

void		manage_args(t_env *env, int argc, char **argv)
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
