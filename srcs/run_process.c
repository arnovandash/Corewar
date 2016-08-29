/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:48:58 by rojones           #+#    #+#             */
/*   Updated: 2016/08/29 12:02:11 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_pc(t_process *pro, char_u opcode)
{
	if (opcode == 0)
		pro->pc = (pro->pc + 5 > MEM_SIZE) ?
			pro->pc + 5 - MEM_SIZE : pro->pc + 5;
	if (opcode == 9 || opcode == 12 || opcode == 15)
		pro->pc = (pro->pc + IND_SIZE + 1 > MEM_SIZE) ?
			pro->pc + IND_SIZE + 1 - MEM_SIZE : pro->pc + IND_SIZE + 1;
}

static void	init_arg_code(t_arg_code *arg_code)
{
	arg_code->arg1 = 0;
	arg_code->arg2 = 0;
	arg_code->arg3 = 0;
	arg_code->total = 0;
}

static void	get_arg_code(char_u encode, t_arg_code *arg_code)
{
	arg_code->arg1 = (C_ARG1(encode));
	arg_code->arg2 = (C_ARG2(encode));
	arg_code->arg3 = (C_ARG3(encode));
	arg_code->total = get_arg_len(arg_code->arg1) +
		get_arg_len(arg_code->arg2) + get_arg_len(arg_code->arg3);
}

void		run_process(t_env *env, t_process *pro)
{
	char_u		opcode;
	t_arg_code	arg_code;

	if (pro->cycle_to_next == 0)
	{
		init_arg_code(&arg_code);
		opcode = env->memory[pro->pc];
		pro->pi = pro->pc;
		if (opcode > 0 && opcode < 17 && (opcode != 1 || opcode != 9 ||
					opcode != 12 || opcode != 14 || opcode != 15))
		{
			get_arg_code(env->memory[pro->pi + 1], &arg_code);
			pro->pc = loop_mem(pro->pc + 1 + arg_code.total);
		}
		else
			set_pc(pro, opcode);
		if (opcode < 17 && opcode > 0)
		{
			pro->cycle_to_next = g_op_tab[opcode - 1].no_cycles;
//			pro->carry = (*function[opcode])(env, arg_code, pro);
		}
	}
	else
		pro->cycle_to_next--;
}
