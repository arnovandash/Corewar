/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 10:21:20 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:21:49 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_padding(int fd, int padding)
{
	while (padding % 4 != 0)
	{
		write(fd, "\0", 1);
		padding++;
	}
}

void			ft_reverse_bytes(void *mem, size_t size)
{
	int		j;
	int		i;
	char	*tmp;
	char	*ptr;

	i = size - 1;
	j = 0;
	ptr = (char *)mem;
	tmp = malloc(size);
	ft_memcpy(tmp, mem, size);
	while (i >= 0)
	{
		ptr[j] = tmp[i];
		j++;
		i--;
	}
	free(tmp);
}

int				ft_print_header(t_all *all)
{
	int	pad;

	pad = sizeof(all->header.magic);
	ft_reverse_bytes(&all->header.magic, sizeof(all->header.magic));
	write(all->fd, &all->header.magic, sizeof(all->header.magic));
	ft_padding(all->fd, pad);
	pad = sizeof(all->header.prog_name);
	write(all->fd, &all->header.prog_name, sizeof(all->header.prog_name));
	ft_padding(all->fd, pad);
	pad = sizeof(all->header.prog_size);
	ft_reverse_bytes(&all->header.prog_size, sizeof(all->header.prog_size));
	write(all->fd, &all->header.prog_size, sizeof(all->header.prog_size));
	ft_padding(all->fd, pad);
	pad = sizeof(all->header.comment);
	write(all->fd, &all->header.comment, sizeof(all->header.comment));
	ft_padding(all->fd, pad);
	return (1);
}
