/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:19:20 by rojones           #+#    #+#             */
/*   Updated: 2016/08/27 11:35:36 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char_u	*get_indir(char_u *mem, ul_int offset, t_process *pro)
{
	ul_int	temp_ind;
	char_u	*temp;
	ul_int	jump;
	int		i;

	jump = 0;
	i = -1;
	if (!(temp = (char_u*)malloc(sizeof(u_char) * REG_SIZE)))
		return (NULL);
	ft_bzero(temp, REG_SIZE);
	while (++i < IND_SIZE)
	{
		temp_ind = loop_mem(offset + i);
		jump = (jump << 8) + mem[temp_ind];
	}
	i = -1;
	jump = loop_mem(pro->pc + (jump % IDX_MOD));
	while (++i < REG_SIZE)
		temp[i] = mem[loop_mem(jump + i)];
	return (temp);
}
