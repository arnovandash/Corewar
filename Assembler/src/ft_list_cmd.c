/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 10:19:44 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:16:57 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_cmd		*ft_new_cmd(char *cmd, char *lbl)
{
	t_cmd	*tmp;

	tmp = NULL;
	tmp = (t_cmd *)malloc(sizeof(t_cmd));
	tmp->cmd = NULL;
	if (cmd != NULL)
		tmp->cmd = ft_strdup(cmd);
	tmp->label = NULL;
	if (lbl != NULL)
		tmp->label = ft_strdup(lbl);
	tmp->next = NULL;
	return (tmp);
}

void		ft_push_back_cmd(t_cmd **begin, char *cmd, char *lbl)
{
	t_cmd	*list;

	list = NULL;
	list = *begin;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_cmd(cmd, lbl);
		list->next->prev = list;
	}
	else
		*begin = ft_new_cmd(cmd, lbl);
}

void		ft_free_cmd(t_cmd **begin)
{
	t_cmd	*list;
	t_cmd	*tmp;

	list = NULL;
	tmp = NULL;
	list = *begin;
	if (list)
	{
		while (list)
		{
			tmp = list;
			list = list->next;
			if (tmp->cmd)
				free(tmp->cmd);
			if (tmp->label)
				free(tmp->label);
			free(tmp);
		}
		*begin = NULL;
	}
}
