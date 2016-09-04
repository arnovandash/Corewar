/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:19:20 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 12:23:51 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_uchar	*get_indir(t_uchar *mem, t_ulint offset, t_process *pro)
{
	t_ulint	temp_ind;
	t_uchar	*temp;
	short	jump;
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
	temp_ind = loop_mem(pro->pc + (jump % IDX_MOD));
	while (++i < REG_SIZE)
		temp[i] = mem[loop_mem(temp_ind + i)];
	return (temp);
}
