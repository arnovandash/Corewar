/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_load_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 08:32:31 by khansman          #+#    #+#             */
/*   Updated: 2016/08/27 10:23:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Need to rewrite this function to take into consideration the variable
**	address size.
*/

int ft_long_load_index(t_env *env, t_arg_len arg_len, t_process *pro)
{
	char_u	*value;

	if (!(1 <= MEM_ARG(3) && MEM_ARG(3) <= REG_NUMBER))
		return (0);
	if (C_ARG1(MEM_ARG(1)) == REG_CODE)
		value = get_reg(env, pro, MEM_ARG(1));
	else if (C_ARG1(MEM_ARG(1)) == DIR_CODE)
		value = get_dir(MEM, MEM_ARG(1));
	else if (C_ARG1(MEM_ARG(1)) == IND_CODE)
		value = get_indir_long(MEM, MEM_ARG(1));
	else
		return (0);
	if (C_ARG2(MEM_ARG(2)) == REG_CODE)
		value += get_reg(env, pro, MEM_ARG(2));
	else if (C_ARG2(MEM_ARG(2)) == DIR_CODE)
		value += get_dir(MEM, MEM_ARG(2));
	else if (C_ARG2(MEM_ARG(2)) == IND_CODE)
		value += get_indir_long(MEM, MEM_ARG(2));
	else
		return (0);
	pro->registers[MEM_ARG(3)][0] = *value;
	return (1);
}
