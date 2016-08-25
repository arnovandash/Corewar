/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:07:12 by khansman          #+#    #+#             */
/*   Updated: 2016/08/22 14:07:15 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The functions in this file are for freeing the enviroment variables.
*/

void	free_data(void *data, size_t size)
{
	if (data == NULL || size <= 0)
		return ;
	free(data);
	(void)size;
}

void	free_env(t_env *env)
{
	int		k;

	k = -1;
	free(env->memory);
	while (++k < env->num_players)
		if (env->players[k].file_name != NULL)
			free(env->players[k].file_name);
	if (env->processes != NULL)
		ft_lstdel(&(env->processes), free_data);
}
