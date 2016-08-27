/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:04:08 by oexall            #+#    #+#             */
/*   Updated: 2016/08/27 10:01:21 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
	return (1);
}
