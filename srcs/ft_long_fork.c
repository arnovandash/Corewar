/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 16:20:14 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 12:29:28 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	add_list(t_process *pro_new, t_env *env)
{
	t_list		*ls;

	ls = ft_lstnew(pro_new, sizeof(t_process));
	if (ls)
	{
		if (env->processes)
			ft_lstadd(&env->processes, ls);
		else
			env->processes = ls;
	}
	else
		error_quit(0);
}

int			ft_long_fork(t_env *env, t_arg_code arg_code, t_process *pro)
{
	short		jump;
	int			i;
	t_process	pro_new;

	jump = 0;
	i = -1;
	arg_code.total++;
	while (++i < IND_SIZE)
		jump = (jump << 8) + env->memory[loop_mem(pro->pi + 1 + i)];
	ft_memcpy(&pro_new, pro, sizeof(t_process));
	if (!(pro_new.registers = (t_reg *)malloc(REG_NUMBER * REG_SIZE)))
		error_quit(0);
	pro_new.pc = loop_mem(pro->pc + (jump));
	pro_new.pi = pro_new.pc;
	pro_new.num = ++env->n_processes;
	pro_new.cycle_to_next +=
		g_op_tab[env->memory[pro_new.pc] - 1].no_cycles - 1;
	ft_memcpy(pro_new.registers, pro->registers, REG_NUMBER * REG_SIZE);
	add_list(&pro_new, env);
	return (pro->carry);
}
