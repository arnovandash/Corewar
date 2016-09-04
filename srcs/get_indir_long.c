/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indir_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:19:59 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 10:03:33 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_uchar	*get_indir_long(t_uchar *mem, t_ulint offset, t_process *pro)
{
	t_ulint	temp_ind;
	t_uchar	*temp;
	t_ulint	jump;
	int		i;

	jump = 0;
	i = -1;
	if (!(temp = (t_uchar*)malloc(sizeof(u_char) * REG_SIZE)))
		return (NULL);
	ft_bzero(temp, REG_SIZE);
	while (++i < IND_SIZE)
	{
		temp_ind = loop_mem(offset + i);
		jump = (jump << 8) + mem[temp_ind];
	}
	i = -1;
	jump = loop_mem(pro->pc + (jump));
	while (++i < REG_SIZE)
		temp[i] = mem[loop_mem(jump + i)];
	return (temp);
}
