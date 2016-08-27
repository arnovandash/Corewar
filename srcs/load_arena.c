/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 09:33:03 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/27 10:35:31 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		load_arena(t_env *env, int p_num)
{
	u_int	size_verify;
	ul_int	x;
	ul_int	start;
	char_u	buffer[env->players[p_num].player_ref.prog_size];
	char_u	c;

	size_verify = 0;
	x = 0;
	start = (MEM_SIZE / env->num_players) * p_num;
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
}
