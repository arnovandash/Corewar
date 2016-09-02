/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:48:58 by rojones           #+#    #+#             */
/*   Updated: 2016/09/02 11:10:54 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_pc(t_process *pro, char_u opcode, int total)
{
	if (opcode == 1)
		pro->pc = loop_mem(pro->pc + 5);
	else if (opcode == 9 || opcode == 12 || opcode == 14 || opcode == 15)
		pro->pc = loop_mem(pro->pc + IND_SIZE + 1);
	else
		pro->pc = loop_mem(pro->pi + 2 + total);
}

static void	init_arg_code(t_arg_code *arg_code)
{
	arg_code->arg1 = 0;
	arg_code->arg2 = 0;
	arg_code->arg3 = 0;
	arg_code->total = 0;
}

static void	get_arg_code(char_u encode, t_arg_code *arg_code, int opcode)
{
	arg_code->arg1 = (C_ARG1(encode));
	arg_code->arg2 = (C_ARG2(encode));
	arg_code->arg3 = (C_ARG3(encode));
	arg_code->total = get_arg_len(arg_code->arg1, g_op_tab[opcode - 1].is_index) +
		get_arg_len(arg_code->arg2, g_op_tab[opcode - 1].is_index) +
		get_arg_len(arg_code->arg3, g_op_tab[opcode - 1].is_index);
}

void		run_process(t_env *env, t_process *pro)
{
	char_u		opcode;
	t_arg_code	arg_code;
	static int	init;

	if (init == 0 && ++init)
	{
		opcode = env->memory[pro->pc];
		pro->cycle_to_next = g_op_tab[opcode - 1].no_cycles;
	}
	if (pro->cycle_to_next == 0)
	{
		init_arg_code(&arg_code);
		opcode = env->memory[pro->pc];
		pro->pi = pro->pc;
		if (opcode > 0 && opcode < 17 && (opcode != 1 && opcode != 9 &&
					opcode != 12 && opcode != 14 && opcode != 15))
		{
			get_arg_code(env->memory[pro->pi + 1], &arg_code, opcode);
		}
		if (opcode < 17 && opcode > 0)
		{
			printf ("cycle %lu call ",env->cycle);
			pro->carry = (*function[opcode])(env, arg_code, pro);
			puts("");
			if (opcode != 9)
				set_pc(pro, opcode, arg_code.total);
			pro->cycle_to_next = g_op_tab[env->memory[pro->pc] - 1].no_cycles;
		}
	}
	pro->cycle_to_next--;
}
