/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_programs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:09:11 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/04 12:21:57 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	make_magic(t_env *env, int p_num)
{
	t_uchar	buffer[4];

	if (read(env->fd, buffer, 4) > 0)
	{
		if ((buffer[1] == 0xea) && (buffer[2] == 0x83) && (buffer[3] == 0xf3))
			env->players[p_num].player_ref.magic = COREWAR_EXEC_MAGIC;
		else
			error_quit(8);
	}
	else
		error_quit(8);
}

static void	read_name(t_env *env, int p_num)
{
	t_uchar	buffer[PROG_NAME_LENGTH + 4];
	int		x;

	x = 0;
	if (read(env->fd, buffer, PROG_NAME_LENGTH + 4) > 0)
	{
		while (buffer[x] != 0x00 && x < PROG_NAME_LENGTH)
		{
			env->players[p_num].player_ref.prog_name[x] = buffer[x];
			x++;
		}
		env->players[p_num].player_ref.prog_name[x] = '\0';
	}
}

static void	read_size(t_env *env, int p_num)
{
	t_uchar		buffer[4];
	t_ulint		result;
	int			x;

	x = 0;
	result = 0;
	if (read(env->fd, buffer, 4) > 0)
	{
		while (x < 4)
		{
			result = (result << 8) + buffer[x];
			x++;
		}
		if (result > CHAMP_MAX_SIZE)
			error_quit(9);
		env->players[p_num].player_ref.prog_size = result;
	}
}

static void	read_comment(t_env *env, int p_num)
{
	t_uchar	buffer[COMMENT_LENGTH + 4];
	int		x;

	x = 0;
	if (read(env->fd, buffer, COMMENT_LENGTH + 4) > 0)
	{
		while (buffer[x] != 0x00 && x < COMMENT_LENGTH)
		{
			env->players[p_num].player_ref.comment[x] = buffer[x];
			x++;
		}
		env->players[p_num].player_ref.comment[x] = '\0';
	}
}

void		read_programs(t_env *env)
{
	int				p_num;
	int				p_check;

	p_num = 0;
	p_check = 0;
	while (p_num < MAX_PLAYERS)
	{
		if (env->players[p_num].init == 1)
		{
			if ((env->fd = open(env->players[p_num].file_name, O_RDONLY)) == -1)
				error_quit(7);
			make_magic(env, p_num);
			read_name(env, p_num);
			read_size(env, p_num);
			read_comment(env, p_num);
			load_arena(env, p_num, p_check);
			close(env->fd);
			p_check++;
		}
		p_num++;
	}
}
