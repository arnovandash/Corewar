/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:18:34 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 10:01:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_uchar	*get_dir(t_uchar *mem, t_ulint offset)
{
	t_uchar	*temp;
	int		i;

	if (!(temp = (t_uchar*)malloc(sizeof(t_uchar) * REG_SIZE)))
		return (NULL);
	ft_bzero(temp, REG_SIZE);
	i = -1;
	while (++i < REG_SIZE)
		temp[i] = mem[loop_mem(offset + i)];
	return (temp);
}
