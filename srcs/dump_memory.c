/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:17:13 by rojones           #+#    #+#             */
/*   Updated: 2016/08/30 08:20:32 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_memory(char_u *mem, unsigned long size, int line)
{
	ul_int	i;
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
