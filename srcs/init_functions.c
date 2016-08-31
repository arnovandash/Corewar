/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:59:18 by rojones           #+#    #+#             */
/*   Updated: 2016/08/29 12:00:02 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	(*function[17])(struct s_env *env, t_arg_code arg_code, t_process *process) = 
{
	NULL,
	ft_live,
	ft_load,
	ft_store,
	ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	0,//ft_zjump,
	0,//ft_load_index,
	0,//ft_store_index,
	0,//ft_fork,
	0,//ft_long_load,
	0,//ft_long_load_index,
	0,//ft_long_fork,
	0//ft_aff
};
