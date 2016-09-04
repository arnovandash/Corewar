/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:17:41 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 09:50:24 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char_u	*get_reg(t_env *env, t_process *pro, t_ulint offset)
{
	char_u	*temp;
	char_u	reg;

	if (!(temp = (char_u*)malloc(sizeof(u_char) * REG_SIZE)))
		return (NULL);
	ft_bzero(temp, REG_SIZE);
	reg = env->memory[loop_mem(offset)] - 1;
	if (reg < REG_NUMBER)
		ft_memcpy(temp, pro->registers[reg], REG_SIZE);
	return (temp);
}
