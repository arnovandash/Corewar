/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:39:40 by rojones           #+#    #+#             */
/*   Updated: 2016/08/23 10:46:49 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** dest = destroy
** pre = previous
** function links previus->next to destroy->next frees destroy then moves 
** destroy the the next eliment of the original list.
*/

void	destroy_process(t_list *dest, t_list *pre)
{
	t_list	*next;

	next = dest->next;
	if (pre)
		pre->next = dest->next;
	free(dest->registers);
	dest->registers = NULL;
	free(dest);
	dest = NULL;
	dest = next;
}
