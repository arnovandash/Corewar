/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:18:34 by rojones           #+#    #+#             */
/*   Updated: 2016/08/27 10:55:29 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char_u	*get_dir(char_u *mem, ul_int offset)
{
	char_u	*temp;
	int		i;

	if (!(temp = (char_u*)malloc(sizeof(u_char) * REG_SIZE)))
		return (NULL);
	ft_bzero(temp, REG_SIZE);
	i = -1;
	while (++i < REG_SIZE)
		temp[i] = mem[loop_mem(offset + i)];
	return (temp);
}
