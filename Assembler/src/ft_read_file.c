/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:23:40 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:23:42 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		checks(t_data *data)
{
	t_data	*tmp;
	int		name;
	int		comment;

	name = 0;
	comment = 0;
	tmp = data;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->line, ".name", 5) == 0)
			name = 1;
		if (ft_strncmp(tmp->line, ".comment", 8) == 0 && name == 1)
			comment = 1;
		tmp = tmp->next;
	}
	if (name == 1 && comment == 1)
		return (1);
	else
	{
		(name == 0) ? ft_putstr("Error-> Missing .name\n") : 0;
		(comment == 0) ? ft_putstr("Error-> Missing .comment\n") : 0;
		return (-1);
	}
}

int		ft_read_file(t_all *all)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	all->fd = open(all->filename, O_RDONLY);
	while (get_next_line(all->fd, &line))
	{
		if (line != NULL)
		{
			if (ft_strlen(line) > 0 && line[0] != COMMENT_CHAR
					&& !ft_iswhiteonly(line))
			{
				if (ft_oneof(';', line) > -1)
					line[ft_oneof(';', line)] = '\0';
				ft_push_back_data(&all->data, line, ++i);
				free(line);
				line = NULL;
			}
		}
	}
	close(all->fd);
	i = checks(all->data);
	return (i);
}
