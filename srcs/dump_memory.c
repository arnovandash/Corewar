/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:17:13 by rojones           #+#    #+#             */
/*   Updated: 2016/09/02 14:53:02 by rojones          ###   ########.fr       */
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
	char temp[80];
	sprintf(temp, "0x%04lx : ", i);
	ft_putstr(temp);
		while (temp_line-- && i < size)
		{
			ft_print_hex(mem[i]);
			/*if (temp_line)
				ft_putchar(' ');
			else
				ft_putchar('\n');*/
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}
