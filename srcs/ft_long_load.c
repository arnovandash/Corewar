/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 09:19:28 by khansman          #+#    #+#             */
/*   Updated: 2016/08/27 10:23:08 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	If the operation was successful the carry should be changed to 1, else
**	it should be set to 0;
*/

int		ft_long_load(t_env *env, t_arg_len arg_len, t_process *pro)
{
	reg_t		value;

	if (C_ARG2(MEM_A(0)) != REG_CODE) || !(1 <= MEM_A(2) < REG_NUMBER))
		return (0);
	if (C_ARG1(MEM_A(0)) == REG_CODE)
		value = get_reg(env, pro, MEM_A(2));
	else if (C_ARG1(MEM_A(0)) == DIR_CODE)
		value = get_dir(env->memory, MEM_A(2));
	else if (C_ARG1(MEM_A(0)) == IND_CODE)
		value = get_indir_long(env->memory, MEM_A(2));
	else
		return (0);
	pro->registers[MEM_A(1)] = value;
	return (1);
}
