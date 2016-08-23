/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_programs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:09:11 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/23 10:17:02 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_programs(t_env *env)
{
	int 	fd;
	char	*cursor;

//	int balls = 0;
	printf("dfsfsdf");
	cursor = NULL;
	fd = open(env->file_name, O_RDONLY);
	while (get_next_line(fd, &cursor))
	{
		while (*cursor != '\0')
		{
		//	printf("cursod : %c\n", cursor[balls]);
		}
		cursor = NULL;
	}
	close(fd);
}
