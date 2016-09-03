/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:39:40 by rojones           #+#    #+#             */
/*   Updated: 2016/09/03 17:58:56 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** dest = destroy
** pre = previous
** function links previus->next to destroy->next frees destroy then moves
** destroy the the next eliment of the original list.
*/

void	destroy_process(t_list **dest, t_list **pre, t_list **head)
{
	t_list		*next;
	t_process	*tmp;

	next = (*dest)->next;
	if (*pre)
		(*pre)->next = next;
	if (*dest == *head)
		*head = next;
	tmp = (t_process*)(*dest)->content;
	free(tmp->registers);
	tmp->registers = NULL;
	free((*dest)->content);
	if (*dest)
		free(*dest);
	*dest = next;
}
