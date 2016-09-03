/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:23:28 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:23:29 by kchetty          ###   ########.fr       */
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
