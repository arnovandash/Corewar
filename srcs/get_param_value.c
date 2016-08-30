/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 12:20:09 by khansman          #+#    #+#             */
/*   Updated: 2016/08/28 12:20:11 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static long int	get_reg_val(t_process *pro, long int ret)
{
	long int	k;
	long int	ret2;

	k = -1;
	ret2 = 0;
	while ((ul_int)++k < REG_SIZ)
		ret2 = (ret2 << 8) + pro->registers[ret % NUMBER_REG][k];
	return (ret2);
}

long int		get_param_value(t_env *env, ul_int pi, t_process *pro, \
		char type)
{
	long int	k;
	long int	l;
	long int	ret;

	ret = 0;
	l = -1;
	k = (type == REG_CODE) ? REG_SIZE : 0;
	k = (type == DIR_CODE) ? DIR_SIZE : k;
	k = (type == IND_CODE) ? IND_SIZE : k;
	while (++l < k)
		ret = (ret << 8) + (unsigned char)MEM[loop_mem(pi + l)];
	if (type == REG_CODE)
		return (get_reg_val(pro, ret));
	return (ret);
}
