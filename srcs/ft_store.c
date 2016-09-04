/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 15:46:18 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 10:35:52 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_store_indir(t_env *env, t_process *pro, t_uchar reg_num)
{
	int		i;
	short	jump;

	i = -1;
	jump = 0;
	while (++i < IND_SIZE)
	{
		jump = (jump << 8) + env->memory[loop_mem(pro->pi + i + 3)];
	}
	jump = jump % IDX_MOD;
	i = -1;
	while (++i < REG_SIZE)
		env->memory[loop_mem(pro->pc + jump + i)] =
			pro->registers[reg_num][i];
}

int			ft_store(t_env *env, t_arg_code acode, t_process *pro)
{
	t_uchar	reg_num1;
	t_uchar	reg_num2;

	if (acode.arg1 != REG_CODE || acode.arg2 == DIR_CODE)
		return (pro->carry);
	reg_num1 = env->memory[loop_mem(pro->pi + 2)] - 1;
	if (reg_num1 > REG_NUMBER)
		return (pro->carry);
	if (acode.arg2 == REG_CODE)
	{
		reg_num2 = env->memory[loop_mem(pro->pi + 3)] - 1;
		if (reg_num2 < REG_NUMBER)
			ft_memcpy(pro->registers[reg_num2], pro->registers[reg_num1],
					REG_SIZE);
	}
	else
		ft_store_indir(env, pro, reg_num1);
	return (pro->carry);
}
