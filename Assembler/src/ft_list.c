/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 10:19:16 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:16:47 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_data	*ft_new_data(char *line, int line_no)
{
	t_data	*tmp;

	tmp = NULL;
	tmp = (t_data *)malloc(sizeof(t_data));
	tmp->line_no = line_no;
	tmp->line = ft_strdup(line);
	tmp->next = NULL;
	return (tmp);
}

void	ft_push_back_data(t_data **begin, char *line, int line_no)
{
	t_data	*list;

	list = NULL;
	list = *begin;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_data(line, line_no);
	}
	else
		*begin = ft_new_data(line, line_no);
}

void	ft_free_data(t_data **begin)
{
	t_data	*data;
	t_data	*tmp;

	data = *begin;
	if (data)
	{
		while (data)
		{
			tmp = data;
			data = data->next;
			tmp->next = NULL;
			free(tmp->line);
			free(tmp);
		}
		*begin = NULL;
	}
}
