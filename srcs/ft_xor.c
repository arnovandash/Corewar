/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:05:50 by rojones           #+#    #+#             */
/*   Updated: 2016/08/27 11:27:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		store_result(char_u reg3, reg_t reg1, reg_t reg2,
		t_process *pro)
{
	int	i;

	if (reg3 > REG_NUMBER)
		return ;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg3][i] = reg1[i] ^ reg2[i];
}

static char_u	*get_arg(t_env *env, t_process *pro, int acode,
		ul_int offset)
{
	char_u *re;

	re = NULL;
	if (acode == REG_CODE)
		re = get_reg(env, pro, pro->pi + offset);
	else if (acode == DIR_CODE)
		re = get_dir(env->memory, pro->pi + offset);
	else if (acode == IND_CODE)
		re = get_indir(env->memory, pro->pi + offset, pro);
	return (re);
}

int				ft_xor(t_env *env, t_arg_code acode, t_process *pro)
{
	char_u	*temp1;
	char_u	*temp2;
	ul_int	arg3;

	temp1 = NULL;
	temp2 = NULL;
	if (acode.arg3 != REG_CODE)
		return (0);
	temp1 = get_arg(env, pro, acode.arg1, pro->pi + 2);
	temp2 = get_arg(env, pro, acode.arg2, pro->pi + 2 +
			get_arg_len(acode.arg1));
	arg3 = loop_mem(pro->pi + 2 + get_arg_len(acode.arg1) +
			get_arg_len(acode.arg2));
	store_result(env->memory[arg3] - 1, temp1, temp2, pro);
	ft_strdel((char**)&temp1);
	ft_strdel((char**)&temp2);
	return (1);
}
