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

void	init_env(t_env *env)
{
	if (!(env->core = malloc(CORESIZE * sizeof(int))) ||
			!(env->processes = malloc((MAX_PROCESS + 2) * sizeof(t_process))))
		error_quit(0);
	ft_bzero(env->core, (CORESIZE * sizeof(int)));
	ft_bzero(env->processes, ((MAX_PROCESS + 2) * SIZEOF(t_process)));
}
