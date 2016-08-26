/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:43:33 by rojones           #+#    #+#             */
/*   Updated: 2016/08/26 08:45:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sub(t_env *env, t_arg_code code, t_process *pro)
{
	char_u	reg1;
	char_u	reg2;
	char_u	reg3;
	int		i;

	pro->carry = (pro->carry == 1) ? 0 : 1;
	if (code.arg1 != REG_CODE || code.arg2 != REG_CODE ||
			code.arg3 != REG_CODE )
		return ;
	reg1 = env->memory[loop_mem(pro->pi + 2)] - 1;
	reg2 = env->memory[loop_mem(pro->pi + 3)] - 1;
	reg3 = env->memory[loop_mem(pro->pi + 4)] - 1;
	if (reg1 > REG_NUMBER || reg2 > REG_NUMBER || reg2 > REG_NUMBER)
		return ;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg3][i] = pro->registers[reg1][i] -
			pro->registers[reg2][i];
}
