/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:17:13 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 10:31:48 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_memory(t_uchar *mem, unsigned long size, int line)
{
	t_ulint	i;
	int		temp_line;

	i = 0;
	while (i < size)
	{
		temp_line = line;
		while (temp_line-- && i < size)
		{
			ft_print_hex(mem[i]);
			if (temp_line)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			i++;
		}
	}
}
