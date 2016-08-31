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

int		ft_long_load(t_env *env, t_arg_code arg_len, t_process *pro)
{
	int			value;
	ul_int		k;

	if ((C_ARG2(MEM_ARG(0)) != REG_CODE) ||
				!(1 <= MEM_ARG(2) && MEM_ARG(2) < REG_NUMBER))
		return (0);
	k = C_ARG1(MEM_ARG(0));
	if (k != REG_CODE && k != DIR_CODE && k != IND_CODE)
		return (0);
	value = get_param_value(env, MEM_ARG(1), pro, k);
	set_reg_value(pro, value, C_ARG2(MEM_ARG(2)));
	return (1);
}
