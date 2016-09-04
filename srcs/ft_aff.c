/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 10:24:36 by khansman          #+#    #+#             */
/*   Updated: 2016/09/04 10:32:26 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_aff(t_env *env, t_arg_code acode, t_process *pro)
{
	int			i;
	t_uchar		reg;
	int32_t		value;

	if (acode.arg1 != REG_CODE)
		return (pro->carry);
	reg = env->memory[pro->pi + 2] - 1;
	if (reg > REG_NUMBER)
		return (pro->carry);
	ft_putstr("Program (");
	ft_putnbr(pro->player->number);
	ft_putstr(") register = ");
	i = -1;
	value = 0;
	while (++i < REG_SIZE)
		value = (value << 8) + pro->registers[reg][i];
	value = value % 256;
	ft_putchar(value);
	ft_putchar('\n');
	return (pro->carry);
}
