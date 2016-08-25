/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:17:13 by rojones           #+#    #+#             */
/*   Updated: 2016/08/25 12:32:28 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_memory(char_u *mem)
{
	ul_int	i;
	int		line;

	i = -1;
	while (++i < MEM_SIZE)
	{
		line = 32;
		while (line--)
		{
			ft_print_hex(mem[i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
