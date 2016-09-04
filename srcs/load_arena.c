/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 09:33:03 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/04 10:09:05 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_pc(t_list *processes, int p_num, unsigned long int start)
{
	t_list		*ls;
	t_process	*pro;

	ls = processes;
	while (ls)
	{
		pro = (t_process*)ls->content;
		if (pro->player->number == p_num)
		{
			pro->pc = start;
			ls = NULL;
		}
		else
			ls = ls->next;
	}
}

void		load_arena(t_env *env, int p_num, int p_check)
{
	u_int	size_verify;
	t_ulint	x;
	t_ulint	start;
	t_uchar	buffer[env->players[p_num].player_ref.prog_size];
	t_uchar	c;

	size_verify = 0;
	x = 0;
	start = (MEM_SIZE / env->num_players) * p_check;
	while (read(env->fd, &c, 1) > 0)
	{
		buffer[size_verify] = c;
		size_verify++;
	}
	if (env->players[p_num].player_ref.prog_size != size_verify)
		error_quit(10);
	while (x < env->players[p_num].player_ref.prog_size)
	{
		env->memory[x + start] = buffer[x];
		x++;
	}
	set_pc(env->processes, p_num, start);
}
