/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:38:03 by rojones           #+#    #+#             */
/*   Updated: 2016/09/03 11:34:05 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_load_reg(t_env *env, t_process *pro, char_u reg_arg2)
{
	char_u	reg_arg1;

	reg_arg1 = 0;
	reg_arg1 = env->memory[loop_mem(pro->pi + 2)] - 1;
	if (reg_arg1 < REG_NUMBER)
	{
		ft_memcpy(pro->registers[reg_arg2], pro->registers[reg_arg1], REG_SIZE);
		return (1);
	}
	return (0);
}

static int	ft_load_dir(t_env *env, reg_t regarg2, ul_int index)
{
	int	i;

	i = -1;
	while (++i < REG_SIZE)
		regarg2[i] = env->memory[loop_mem(index + i)];
	return (1);
}

static int	ft_load_indir(t_env *env, t_process *pro, u_char reg_arg2)
{
	int		i;
	short	jump;
	ul_int	start;

	i = -1;
	jump = 0;
	while (++i < IND_SIZE)
		jump = (jump << 8) + env->memory[pro->pi + 2 + i];
	start = loop_mem(pro->pc + (jump % IDX_MOD));
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg_arg2][i] = env->memory[loop_mem(start + i)];
	return (1);
}

int			ft_load(t_env *env, t_arg_code a_case, t_process *pro)
{
	char_u	reg_num;

	if (a_case.arg2 != REG_CODE)
		return (0);
	reg_num = env->memory[loop_mem(pro->pi + 2 +
			get_arg_len(a_case.arg1, g_op_tab[1].is_index))] - 1;
	if (reg_num < REG_NUMBER)
	{
		if (a_case.arg1 == REG_CODE)
			return (ft_load_reg(env, pro, reg_num));
		if (a_case.arg1 == DIR_CODE)
			return (ft_load_dir(env, pro->registers[reg_num], pro->pi + 2));
		if (a_case.arg1 == IND_CODE)
			return (ft_load_indir(env, pro, reg_num));
	}
	return (0);
}
