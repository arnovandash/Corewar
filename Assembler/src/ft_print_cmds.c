/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:19:59 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:20:00 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	ft_getacb(char *str)
{
	int		i;
	char	acb;
	char	**params;

	params = NULL;
	str = str + ft_strlen(g_op_tab[ft_getindex(str)].name);
	while (*str == ' ' || *str == '\t')
		str++;
	params = ft_strsplit(str, SEPARATOR_CHAR);
	i = -1;
	acb = 0;
	while (params[++i])
	{
		if (ft_gettype(params[i]) == T_REG)
			acb |= REG_CODE;
		else if (ft_gettype(params[i]) == T_DIR)
			acb |= DIR_CODE;
		else if (ft_gettype(params[i]) == T_IND)
			acb |= IND_CODE;
		acb = (acb << 2);
	}
	while (++i < 4)
		acb = (acb << 2);
	ft_free_split(params);
	return (acb);
}

static int	ft_print_params(t_all *all, char *str, t_cmd *cmd)
{
	int		i;
	int		index;
	char	**params;

	params = NULL;
	index = ft_getindex(str);
	str = str + ft_strlen(g_op_tab[index].name);
	while (*str == ' ' || *str == '\t')
		str++;
	i = -1;
	params = ft_strsplit(str, SEPARATOR_CHAR);
	while (params[++i])
	{
		if (ft_gettype(params[i]) == T_REG)
			ft_print_reg(all, params[i]);
		else if (ft_gettype(params[i]) == T_DIR)
			ft_print_dir(all, params[i], g_op_tab[index].is_index, cmd);
		else if (ft_gettype(params[i]) == T_IND)
			ft_print_ind(all, params[i]);
	}
	ft_free_split(params);
	return (1);
}

int			ft_print_cmds(t_all *all)
{
	char	code;
	int		index;
	t_cmd	*cmd;

	cmd = NULL;
	cmd = all->cmd;
	while (cmd)
	{
		if ((cmd->cmd || (cmd->cmd && cmd->label)) && !ft_iswhiteonly(cmd->cmd))
		{
			index = ft_getindex(cmd->cmd);
			write(all->fd, &g_op_tab[index].id, sizeof(g_op_tab[index].id));
			if (g_op_tab[index].has_acb)
			{
				code = ft_getacb(cmd->cmd);
				write(all->fd, &code, sizeof(code));
			}
			if (!ft_print_params(all, cmd->cmd, cmd))
				return (ft_error(all, "Failed to print parameters"));
		}
		cmd = cmd->next;
	}
	return (1);
}
