/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 11:04:33 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:16:22 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**check_params(char *str, int i, int len)
{
	int count;

	count = 0;
	while (str[len] != '\0')
	{
		if ((str[len] == '%') || ((str[len] == 'r') && (str[len] >= '0'
		&& str[len] <= '9')) || (str[len] >= '0' && str[len] <= '9'))
			(count == 0) ? count = 1 : 0;
		(str[len] == ',') ? count++ : 0;
		len++;
	}
	len = 0;
	while (str[len] != '\0')
	{
		if ((str[len] == '%') || ((str[len] == 'r') && (str[len + 1] >= '0' &&
		str[len + 1] <= '9')) || (str[len] >= '0' && str[len] <= '9'))
			break ;
		len++;
	}
	if (count != g_op_tab[i].no_args)
		return (NULL);
	return (ft_strsplit(&str[len], ' '));
}

int		check_file_size(t_all *a, int i, int check)
{
	int p;

	p = -1;
	if (check != 1)
		return (0);
	while (a->tab[++p] != '\0')
	{
		if ((a->tab[p][0] == 'r') && (check_digit(&a->tab[p][1]) == 1))
		{
			if (ft_atoi(a->tab[p]) > 16 && ft_atoi(a->tab[p]) <= 0)
				return (0);
			a->header.prog_size += 1;
		}
		else if (((a->tab[p][0]) == '%') && (check_digit(&a->tab[p][1]) == 1))
		{
			(g_op_tab[i].is_index != 1) ? a->header.prog_size += 4 : 0;
			(g_op_tab[i].is_index == 1) ? a->header.prog_size += 2 : 0;
		}
		else if (ft_atoi(a->tab[p]) != 0)
			a->header.prog_size += 2;
		else if (ft_strncmp(a->tab[p], "%:", 2) == 0)
			a->header.prog_size += 2;
	}
	return (1);
}

int		check(int test, int i)
{
	int k;

	k = 0;
	while (k < g_op_tab[i].no_args)
	{
		if (test == 2)
		{
			if (T_DIR & g_op_tab[i].type[k])
				return (1);
		}
		if (test == 1)
		{
			if (T_REG & g_op_tab[i].type[k])
				return (1);
		}
		if (test == 3)
		{
			if (T_IND & g_op_tab[i].type[k])
				return (1);
		}
		k++;
	}
	return (0);
}

int		valid_params(char **tab, int i)
{
	int j;
	int test;
	int conf;

	conf = 0;
	j = 0;
	test = 0;
	if (tab == NULL)
		return (0);
	while (tab[j] != '\0')
	{
		if (ft_strncmp(tab[j], "r", 1) == 0)
			conf = check(1, i);
		else if (ft_strncmp(tab[j], "%", 1) == 0)
			conf = check(2, i);
		else
			conf = check(3, i);
		if (conf == -1)
			return (0);
		j++;
	}
	return (1);
}

int		ft_is_valid(t_all *all, char *str, char *lbl)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	len = 0;
	all->multi = 0;
	tmp = ft_trimsp(str);
	ft_push_back_cmd(&all->cmd, ft_trimsp(str), lbl);
	while (i < 16 && all->multi != 1)
	{
		len = ft_strlen(g_op_tab[++i].name);
		if ((ft_strncmp(tmp, g_op_tab[i].name, len) == 0) && ((tmp[len] == 9)
					|| (tmp[len] == ' ')))
		{
			all->multi = 1;
			all->header.prog_size += 1;
			(g_op_tab[i].has_acb == 1) ? all->header.prog_size += 1 : 0;
		}
	}
	all->tab = check_params(tmp, i, len);
	all->multi = valid_params(all->tab, i);
	all->multi = check_file_size(all, i, all->multi);
	return (all->multi);
}
