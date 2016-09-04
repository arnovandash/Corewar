/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:43:33 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 10:37:28 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned long int	get_value(unsigned char *reg)
{
	int					i;
	unsigned long int	re;

	re = 0;
	i = -1;
	while (++i < REG_SIZE)
		re = (re << 8) + reg[i];
	return (re);
}

static void					save_value(t_uchar *reg, t_ulint value)
{
	reg[0] = (value & 0b11111111000000000000000000000000) >> 24;
	reg[1] = (value & 0b00000000111111110000000000000000) >> 16;
	reg[2] = (value & 0b00000000000000001111111100000000) >> 8;
	reg[3] = (value & 0b00000000000000000000000011111111);
}

int							ft_sub(t_env *env, t_arg_code code,
		t_process *pro)
{
	t_uchar	reg1;
	t_uchar	reg2;
	t_uchar	reg3;

	if (code.arg1 != REG_CODE || code.arg2 != REG_CODE ||
			code.arg3 != REG_CODE)
		return (0);
	reg1 = env->memory[loop_mem(pro->pi + 2)] - 1;
	reg2 = env->memory[loop_mem(pro->pi + 3)] - 1;
	reg3 = env->memory[loop_mem(pro->pi + 4)] - 1;
	if (reg1 > REG_NUMBER || reg2 > REG_NUMBER || reg3 > REG_NUMBER)
		return (0);
	save_value(pro->registers[reg3], get_value(pro->registers[reg1]) -
			get_value(pro->registers[reg2]));
	return (1);
}
