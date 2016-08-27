/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 10:24:36 by khansman          #+#    #+#             */
/*   Updated: 2016/08/27 10:24:38 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_aff(t_env *env, t_arg_len arg_len, t_process *pro)
{
	int		k;
	char_u	reg;
	char_u	*s;

	if (C_ARG1(MEM_A(0)) != REG_CODE || 
				!(1 <= MEM_A(0) && MEM_A(0) <= REG_NUMBER))
		return (pro->carry);
	k = -1;
	reg = get_reg(env, pro, MEM_A(1));
	s = (char *)reg;
	ft_putstr("Program (");
	ft_putnbr(pro->player->number);
	ft_putstr(") register = ");
	while ((unsigned long)++k < sizeof(t_reg))
		ft_putchar((*s)++);
	ft_putchar('\n');
	return (pro->carry);
}
