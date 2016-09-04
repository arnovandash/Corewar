/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:59:18 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 12:22:49 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	(*g_function[17])(struct s_env *env, t_arg_code arg_code,
		t_process *process) =
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
	ft_zjmp,
	ft_load_index,
	ft_store_index,
	ft_fork,
	ft_long_load,
	ft_long_load_index,
	ft_long_fork,
	ft_aff
};
