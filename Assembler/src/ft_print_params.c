/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 13:44:59 by oexall            #+#    #+#             */
/*   Updated: 2016/08/22 10:40:16 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_print_reg(t_all *all, char *reg)
{
	char	val;

	while (*reg == ' ' || *reg == 'r')
		reg++;
	val = ft_atoi(reg);
	write(all->fd, &val, sizeof(val));
	return (1);
}

int		ft_print_dir(t_all *all, char *dir, int index, t_cmd *cmd)
{
	short int	sival;
	int			ival;

	sival = 0;
	ival = 0;
	while (*dir == ' ' || *dir == '\t')
		dir++;
	if (dir[0] == '%' && dir[1] != ':')
	{
		if (!index)
		{
			ival = ft_atoi(&dir[1]);
			ft_reverse_bytes(&ival, sizeof(ival));
			write(all->fd, &ival, sizeof(ival));
		}
		else
		{
			sival = ft_atoi(&dir[1]);
			ft_reverse_bytes(&sival, sizeof(sival));
			write(all->fd, &sival, sizeof(sival));
		}
	}
	else if (dir[0] == '%' && dir[1] == ':')
		ft_print_lbl(all, &dir[2], cmd);
	return (1);
}

int		ft_print_ind(t_all *all, char *ind)
{
	short int	val;

	val = ft_atoi(ind);
	ft_reverse_bytes(&val, sizeof(val));
	write(all->fd, &val, sizeof(val));
	return (1);
}
