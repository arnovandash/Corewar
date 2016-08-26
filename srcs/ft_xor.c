/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:05:50 by rojones           #+#    #+#             */
/*   Updated: 2016/08/26 17:03:04 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		store_result(char_u reg3, reg_t reg1, reg_t reg2, t_process *pro)
{
	int	i;

	if (reg3 > REG_NUMBER)
		return ;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg3][i] = reg1[i] ^ reg2[i];
}

int	ft_xor(t_env *env, t_arg_code acode, t_process *pro)
{
	char_u	*temp1;
	char_u	*temp2;
	ul_int	arg3;

	temp1 = NULL;
	temp2 = NULL;
	if (acode.arg3 != REG_CODE)
		return (0);
	puts("arg check passed");
	if (acode.arg1 == REG_CODE)
		temp1 = get_reg(env, pro, pro->pi + 2);
	else if(acode.arg1 == DIR_CODE)
		temp1 = get_dir(env->memory, pro->pi + 2);
	else if(acode.arg1 == IND_CODE)
		temp1 = get_indir(env->memory, pro->pi + 2, pro);
	if (acode.arg2 == REG_CODE)
		temp2 = get_reg(env, pro, pro->pi + 2 + get_arg_len(acode.arg1));
	else if(acode.arg2 == DIR_CODE)
		temp2 = get_dir(env->memory, pro->pi + 2 + get_arg_len(acode.arg1));
	else if(acode.arg2 == IND_CODE)
		temp2 = get_indir(env->memory, pro->pi + 2 + get_arg_len(acode.arg1), pro);
	arg3 = loop_mem(pro->pi + 2 + get_arg_len(acode.arg1) +  get_arg_len(acode.arg2));
	store_result(env->memory[arg3] - 1, temp1, temp2, pro);
	ft_strdel((char**)&temp1);
	ft_strdel((char**)&temp2);
	return (1);
}
