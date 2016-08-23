/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:53:22 by khansman          #+#    #+#             */
/*   Updated: 2016/08/22 14:10:47 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The functions in this file are for initialising the enviroment variables.
*/

void	init_env(t_env *env)
{
	if (!(env->memory = malloc(MEM_SIZE))
		error_quit(0);
	ft_bzero(env->memory, (MEM_SIZE));
}
