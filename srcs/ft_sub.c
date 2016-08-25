/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:43:33 by rojones           #+#    #+#             */
/*   Updated: 2016/08/25 08:04:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sub(t_env *env, t_arg_code arg_code, t_process *pro)
{
	char_u	reg1;
	char_u	reg2;
	char_u	reg3;
	int		i;

	pro->carry = (pro->carry == 1) ? 0 : 1;
	if (arg_code.arg1 != REG_CODE || arg_code.arg2 != REG_CODE ||
			arg_code.arg3 != REG_CODE )
		return ;
	reg1 = env->memory[pro->pi + 2] - 1;
	reg2 = env->memory[pro->pi + 2 + get_arg_len(arg_code.arg1)] - 1;
	reg3 = env->memory[pro->pi + 2 + get_arg_len(arg_code.arg1) + 
		get_arg_len(arg_code.arg2)] - 1;
	if (reg1 > REG_NUMBER || reg2 > REG_NUMBER || reg2 > REG_NUMBER)
		return ;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg3][i] = pro->registers[reg1][i] -
			pro->registers[reg2][i];
}
