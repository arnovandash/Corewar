/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:59:18 by rojones           #+#    #+#             */
/*   Updated: 2016/08/30 13:41:55 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*int	*function[17] = 
{
	env->function[0] = NULL,
	env->function[1] = ft_live,
	env->function[2] = ft_load,
	env->function[3] = ft_store,
	env->function[4] = ft_add,
	env->function[5] = ft_sub,
	env->function[6] = ft_add,
	env->function[7] = ft_or,
	env->function[8] = ft_xor,
	env->function[9] = ft_zjump,
	env->function[10] = ft_load_index,
	env->function[11] = ft_store_index,
	env->function[12] = ft_fork,
	env->function[13] = ft_long_load,
	env->function[14] = ft_long_load_index,
	env->function[15] = ft_long_fork,
	env->function[16] = ft_aff,
}*/

int	(*function[17])(struct s_env *env, t_arg_code arg_code, t_process *process) = 
{
	NULL,
	ft_live,
	ft_load,
	ft_store,
	0,//ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	ft_zjmp,
	ft_load_index,
	0,//ft_store_index,
	0,//ft_fork,
	0,//ft_long_load,
	0,//ft_long_load_index,
	0,//ft_long_fork,
	0//ft_aff
};
