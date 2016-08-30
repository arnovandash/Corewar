/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 08:16:50 by khansman          #+#    #+#             */
/*   Updated: 2016/08/30 08:18:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		set_reg_value(t_process *pro, nt value, unsigned int reg)
{
	if (pro == NULL)
		return (-1);
	if ((reg % REG_NUMBER) == 0)
		return (0);
	ft_memcpy(&(pro->registers[(reg % REG_NUMBER)]), &value, REG_SIZ);
	return (1);
}

int		set_indir_value(t_env *env, int pi, int value)
{
	char	*temp;

	temp = (char *)&value;
	temp += 2;
	ft_memcpy(MEM[loop_mem(pi)], temp, 2);
}
