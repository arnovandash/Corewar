/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 16:20:14 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 11:58:24 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_long_fork(t_env *env, t_arg_code arg_code, t_process *pro)
{
	short		jump;
	int			i;
	t_process	pro_new;
	t_list		*ls;

	jump = 0;
	i = -1;
	arg_code.total++;
	while (++i < IND_SIZE)
		jump = (jump << 8) + env->memory[loop_mem(pro->pi + 1 + i)];
	ft_memcpy(&pro_new, pro, sizeof(t_process));
	if (!(pro_new.registers = (t_reg *)malloc(REG_NUMBER * REG_SIZE)))
		error_quit(0);
	pro_new.pc = loop_mem(pro->pc + jump);
	pro_new.pi = pro_new.pc;
	ft_memcpy(pro_new.registers, pro->registers, REG_NUMBER * REG_SIZE);
	ls = ft_lstnew(&pro_new, sizeof(pro_new));
	if (ls)
		ft_lstadd(&env->processes, ls);
	else
		error_quit(0);
	return (pro->carry);
}
