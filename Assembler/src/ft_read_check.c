/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:37:05 by oexall            #+#    #+#             */
/*   Updated: 2016/08/27 09:47:05 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_read_check(t_all *all)
{
	char	*tmp;
	int		fd;

	tmp = ft_strrchr(all->filename, '.');
	if (tmp == NULL)
		return (ft_error(all, FILE_ERR_1));
	else if (!(tmp[0] == '.' && tmp[1] == 's' && tmp[2] == '\0'))
		return (ft_error(all, FILE_ERR_1));
	else if ((fd = open(all->filename, O_RDONLY)) == -1)
		return (ft_error(all, "Permission Denied to file"));
	if (fd > -1 && close(fd) == -1)
		return (ft_error(all, "Failed to close file"));
	return (1);
}
