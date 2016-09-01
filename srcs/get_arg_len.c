/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:49:41 by rojones           #+#    #+#             */
/*   Updated: 2016/09/01 14:41:27 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_arg_len(int arg_code, int is_index)
{
	if (arg_code == REG_CODE)
		return (1);
	if (arg_code == DIR_CODE && is_index == 0)
		return (DIR_SIZE);
	if (arg_code == DIR_CODE && is_index == 1)
		return (IND_SIZE);
	if (arg_code == IND_CODE)
		return (IND_SIZE);
	return (0);
}
