/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:23:52 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:23:53 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_iswhiteonly(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	return (1);
}

int			ft_val_label(t_all *all, char *label)
{
	char	*lbl;
	char	*cmd;
	int		i;
	int		res;

	res = 1;
	i = ft_oneof(LABEL_CHAR, label);
	lbl = ft_strsub(label, 0, i);
	cmd = ft_strdup(&label[i + 1]);
	i = -1;
	while (lbl[++i])
		if (ft_oneof(lbl[i], LABEL_CHARS) < 0)
			res = ft_error(all, "Invalid Character in Label.");
	if (res && (ft_strlen(cmd) <= 0 || ft_iswhiteonly(cmd)))
		ft_push_back_cmd(&all->cmd, NULL, lbl);
	else if (res && ft_strlen(cmd) > 0 && !ft_iswhiteonly(cmd))
		if (!(ft_is_valid(all, ft_trimsp(cmd), lbl)))
			res = ft_error(all, "Invalid Command.");
	free(lbl);
	free(cmd);
	return (res);
}
