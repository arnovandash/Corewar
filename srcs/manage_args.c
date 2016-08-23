/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:44:02 by khansman          #+#    #+#             */
/*   Updated: 2016/08/23 11:17:14 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	manage_args(t_env *env, int argc, char **argv)
{
	int		k;

	k = 0;
	if (argc <= 1)
		error_quit(1);
	while (argv[++k])
	{
		if (!ft_strcmp(argv[k], "-dump"))
			k += ft_set_dump_cycle(env, argv[k + 1]);
		else if (!ft_strcmp(argv[k], "-n"))
			k += ft_set_player_number(env, argv[k + 1], argv[k + 2]);
		else
			ft_set_player_number(env, NULL, argv[k]);
	}
}
