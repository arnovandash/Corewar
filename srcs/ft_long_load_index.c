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

int ft_long_load_index(t_env *env, t_arg_len arg_len, t_process *pro)
{
	int		value;
	int		k;

	if (!(1 <= MEM_ARG(3) && MEM_ARG(3) <= REG_NUMBER) || 
				!(C_ARG3(MEM_ARG(0))) == REG_CODE)
		return (0);
	k = C_ARG1(MEM_ARG(1));
	if (k != REG_CODE && k != DIR_CODE && k != IND_CODE)
		return (0);
	value = get_param_value(env, MEM_ARG(1), pro, k);
	k = C_ARG2(MEM_ARG(0));
	if (k != REG_CODE && k != DIR_CODE && k != IND_CODE)
		return (0);
	value += get_param_value(env, MEM_ARG(2), pro, k);
	set_reg_value(pro, value, MEM_ARG(3));
	return (1);
}
