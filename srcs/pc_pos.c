/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 08:26:16 by khansman          #+#    #+#             */
/*   Updated: 2016/08/27 08:26:17 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

ul_int	ft_pc_pos(t_arg_len arg_len, char arg, unsigned long pc)
{
	if (arg == -1)
		return (pc % MEM_SIZE);
	else if (arg == 0)
		return ((1 + pc) % MEM_SIZE);
	else if (arg == 1)
		return ((2 + pc) % MEM_SIZE);
	else if (arg == 2)
		return ((2 + arg_len.arg1 + pc) % MEM_SIZE);
	else if (arg == 3)
		return ((2 + arg_len.arg1 + arg_len.arg2 + pc) % MEM_SIZE);
	return (0);
}
