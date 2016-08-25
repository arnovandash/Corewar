/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_programs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:09:11 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/24 11:43:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_programs(t_env *env)
{
	int 	fd;
	int		p_num;
	char	*cursor;

				printf("num players %i\n", env->num_players);
	p_num = 0;
	while (p_num < env->num_players)
	{
		fd = open(env->players[p_num].file_name, O_RDONLY);

		printf("filename: %s\n", env->players[p_num].file_name);
		while (get_next_line(fd, &cursor))
		{
			while (*cursor != '\0')
			{
				printf("Blah: %s\n", cursor);
			}
			cursor = NULL;
			cursor++;
		}
		close(fd);
		p_num++;
	}
}
