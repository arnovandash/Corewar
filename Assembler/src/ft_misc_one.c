/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:17:30 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:17:32 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*ft_trimsp(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;
	*(end + 1) = '\0';
	return (str);
}

char	*ft_trimqu(char *str)
{
	char	*end;

	while (*str == '\"')
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && *end == '\"')
		end--;
	*(end + 1) = '\0';
	return (str);
}

int		ft_oneof(char c, char *in)
{
	int	i;

	i = -1;
	while (in[++i])
		if (c == in[i])
			return (i);
	return (-1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int		ft_getindex(char *src)
{
	int	i;
	int	len;

	i = 0;
	while (i < 16)
	{
		len = ft_strlen(g_op_tab[i].name);
		if (ft_strncmp(src, g_op_tab[i].name, len) == 0 &&
				(src[len] == 9 || src[len] == ' '))
			return (i);
		i++;
	}
	return (-1);
}
