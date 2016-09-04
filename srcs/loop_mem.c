/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 08:41:39 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 09:50:41 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long int	loop_mem(t_ulint check)
{
	return ((check < MEM_SIZE) ? check : check - MEM_SIZE);
}
