/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 14:22:36 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 12:31:09 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_live(t_env *env, t_arg_code code, t_process *pro)
{
	int32_t	index;
	int		i;

	index = 0;
	code.total = 4;
	i = -1;
	code.total++;
	while (++i < 4)
		index = (index << 8) + env->memory[loop_mem(pro->pi + 1 + i)];
	if (index >= 0 && index < MAX_PLAYERS && env->players[index].init == 1)
	{
		env->players[index].live++;
		ft_putstr("A process shows that player ");
		ft_putnbr(env->players[index].number);
		ft_putstr(" (");
		ft_putstr(env->players[index].player_ref.prog_name);
		ft_putstr(") is alive\n");
	}
	return (pro->carry);
}
