/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:24:07 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:26:35 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_prog(t_all *all, char *prog)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strchr(prog, '\"');
	if (!tmp)
		return (ft_error(all, "Name missing from .name line."));
	if (tmp == ft_strrchr(prog, '\"'))
		return (ft_error(all, "Missing end/start quotation mark on .name"));
	tmp = ft_trimqu(tmp);
	if ((4 + ft_strlen(tmp)) > PROG_NAME_LENGTH)
		return (ft_error(all, "Program Name is too long."));
	ft_strncpy(all->header.prog_name, tmp, PROG_NAME_LENGTH);
	return (1);
}

int		ft_val_comment(t_all *all, char *comment)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strchr(comment, '\"');
	if (!tmp)
		return (ft_error(all, "Comment missing from .comment line."));
	if (tmp == ft_strrchr(comment, '\"'))
		return (ft_error(all, "Missing start/end quotation mark on .comment"));
	tmp = ft_trimqu(tmp);
	if ((4 + ft_strlen(tmp)) > COMMENT_LENGTH)
		return (ft_error(all, "Program Comment is too long."));
	ft_strncpy(all->header.comment, tmp, COMMENT_LENGTH);
	return (1);
}

int		ft_validate(t_all *all)
{
	t_data	*data;
	int		res;

	res = 1;
	data = NULL;
	data = all->data;
	while (res && data)
	{
		if (res && ft_strstr(data->line, ".name") != NULL)
			res = ft_val_prog(all, data->line);
		else if (res && ft_strstr(data->line, ".comment") != NULL)
			res = ft_val_comment(all, data->line);
		else if (res && ft_oneof(LABEL_CHAR, data->line) > -1 &&
				data->line[ft_oneof(LABEL_CHAR, data->line) - 1] != DIRECT_CHAR)
			res = ft_val_label(all, data->line);
		else
			res = ft_is_valid(all, data->line, NULL);
		if (res == 0)
			ft_putstr("Error-> Syntax..\n");
		data = data->next;
	}
	return (res);
}
