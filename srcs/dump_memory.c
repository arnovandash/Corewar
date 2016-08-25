/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:17:13 by rojones           #+#    #+#             */
/*   Updated: 2016/08/25 12:49:09 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_memory(char_u *mem, unsigned long size)
{
	ul_int	i;
	int		line;

	i = -1;
	while (++i < size)
	{
		line = 32;
		while (line-- && i < size)
		{
			ft_print_hex(mem[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}
