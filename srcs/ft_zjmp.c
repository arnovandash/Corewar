/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 11:52:24 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/01 16:31:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_zjmp(t_env *env, t_arg_code acode, t_process *pro)
{
//puts("zjump called");
	short	offset;
	int		i;

	offset = 0;
	i = -1;
	acode.total++;
	if (pro->carry == 1)
	{
		while (++i < IND_SIZE)
			offset = (offset << 8) + env->memory[loop_mem(pro->pi + 1 + i)];
		pro->pc = loop_mem(pro->pc + (offset % IDX_MOD));
	}
	return (pro->carry);
}
