/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:59:18 by rojones           #+#    #+#             */
/*   Updated: 2016/08/24 10:56:22 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_functions(t_env *env)
{
	env->function[0] = NULL;
	env->function[1] = ft_live;
	env->function[2] = ft_load;
	env->function[3] = ft_store;
	env->function[4] = ft_add;
	env->function[5] = ft_sub;
	env->function[6] = ft_add;
	env->function[7] = ft_or;
	env->function[8] = ft_xor;
	env->function[9] = ft_zjump;
	env->function[10] = ft_load_index;
	env->function[11] = ft_store_index;
	env->function[12] = ft_fork;
	env->function[13] = ft_long_load;
	env->function[14] = ft_long_load_index;
	env->function[15] = ft_long_fork;
	env->function[16] = ft_aff;
}
