/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:20:42 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:20:47 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	ft_count_params(int index, char **params)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (params[++i])
	{
		if (ft_gettype(params[i]) == T_REG)
			res += 1;
		else if (ft_gettype(params[i]) == T_DIR && params[i][1] != ':')
		{
			if (g_op_tab[index].is_index != 1)
				res += 4;
			else
				res += 2;
		}
		else if (ft_gettype(params[i]) == T_DIR && params[i][1] == ':')
			res += 2;
		else
			res += 2;
	}
	return (res);
}

static int	ft_count_line(char *cmd)
{
	char	**params;
	int		index;
	int		res;

	res = 0;
	if ((index = ft_getindex(cmd)) != -1)
		res += 1;
	if (g_op_tab[index].has_acb)
		res += 1;
	cmd = cmd + ft_strlen(g_op_tab[index].name);
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	params = ft_strsplit(cmd, SEPARATOR_CHAR);
	res += ft_count_params(index, params);
	ft_free_split(params);
	return (res);
}

static int	ft_look_up(char *lbl, t_cmd *cur)
{
	short int	res;

	res = 0;
	while (cur)
	{
		if (cur->cmd)
			res -= ft_count_line(cur->cmd);
		if (cur->label)
			if (ft_strncmp(cur->label, lbl, ft_strlen(cur->label)) == 0)
				return (res);
		cur = cur->prev;
	}
	return (0);
}

static int	ft_look_down(char *lbl, t_cmd *cur)
{
	short int	res;

	res = 0;
	while (cur)
	{
		if (cur->label)
			if (ft_strncmp(cur->label, lbl, ft_strlen(cur->label)) == 0 &&
					(ft_strlen(cur->label) == ft_strlen(lbl)))
				return (res);
		if (cur->cmd)
			res += ft_count_line(cur->cmd);
		cur = cur->next;
	}
	return (0);
}

int			ft_print_lbl(t_all *all, char *lbl, t_cmd *cmd)
{
	short int	res;

	res = 0;
	res = ft_look_down(lbl, cmd);
	if (res == 0)
		res = ft_look_up(lbl, cmd->prev);
	ft_reverse_bytes(&res, sizeof(res));
	write(all->fd, &res, sizeof(res));
	return (1);
}
