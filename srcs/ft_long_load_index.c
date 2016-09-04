/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_load_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:11:44 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/04 10:06:23 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	t_ulint	arg_fetch(t_uchar *mem, t_ulint offset)
{
	t_ulint	ret;
	int		i;

	i = -1;
	ret = 0;
	while (++i < IND_SIZE)
		ret = (ret << 8) + mem[loop_mem(offset + i)];
	return (ret);
}

static t_ulint	getarg(t_uchar *mem, int acode, t_process *pro, t_ulint offset)
{
	t_ulint	ret;
	t_uchar	reg;
	int		i;

	i = -1;
	ret = 0;
	if (acode == REG_CODE)
	{
		reg = mem[loop_mem(offset)] - 1;
		if (reg < REG_NUMBER)
			while (++i < REG_SIZE)
				ret = (ret << 8) + pro->registers[reg][i];
	}
	else if (acode == IND_CODE)
		ret = arg_fetch(mem, pro->pc + arg_fetch(mem, offset));
	else if (acode == DIR_CODE)
		ret = arg_fetch(mem, offset);
	return (ret);
}

static int		arg_len_ind(int acode)
{
	if (acode == REG_CODE)
		return (1);
	else
		return (2);
}

int				ft_long_load_index(t_env *env, t_arg_code acode, t_process *pro)
{
	int		i;
	u_char	reg_num;
	t_ulint	arg1;
	t_ulint	arg2;
	t_ulint	offset;

	if (acode.arg3 != REG_CODE)
		return (0);
	arg1 = getarg(env->memory, acode.arg1, pro, pro->pi + 2);
	arg2 = getarg(env->memory, acode.arg2, pro, pro->pi + 2 +
			arg_len_ind(acode.arg1));
	reg_num = env->memory[loop_mem(pro->pi + arg_len_ind(acode.arg1) +
			arg_len_ind(acode.arg2) + 2)] - 1;
	offset = arg1 + arg2;
	offset = loop_mem(pro->pc + (offset));
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg_num][i] = env->memory[loop_mem(offset + i)];
	return (1);
}
