/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:48:58 by rojones           #+#    #+#             */
/*   Updated: 2016/08/24 17:55:20 by rojones          ###   ########.fr       */
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

static void init_arg_case(t_arg_case *arg_case)
{
	arg_case->arg1 = 0;
	arg_case->arg2 = 0;
	arg_case->arg3 = 0;
	arg_case->total = 0;
}

static void get_arg_case(char_u encode, t_arg_case *arg_case )
{   
	arg_case->arg1 = (C_ARG1(encode));
	arg_case->arg2 = (C_ARG2(encode));
	arg_case->arg3 = (C_ARG3(encode)); 
	arg_case->total = get_arg_len(arg_case->arg1) +
		get_arg_len(arg_case->arg2) +  get_arg_len(arg_case->arg3);
}

void	run_process(t_env *env, t_process *pro)
{
	char_u		opcode;
	t_arg_case	arg_case;

	if (pro->cycle_to_next == 0)
	{
		init_arg_case(&arg_case);
		opcode = env->memory[pro->pc];
		pro->pi = pro->pc;
		if (opcode > 0 && opcode < 17 && (opcode != 1 || opcode != 9 || opcode != 12
					|| opcode != 14 || opcode != 16))
		{
			get_arg_case(env->memory[opcode + 1], &arg_case);
			pro->pc = (pro->pc + arg_case.total > MEM_SIZE) ?
				pro->pc + arg_case.total - MEM_SIZE :
				pro->pc + arg_case.total;
		}
		else
			set_pc(pro, opcode);
		if (opcode < 17)
		{
			//set pro->cycle_to_next
			(*env->function[opcode])(env, arg_case, pro);
		}
	}
	else
		pro->cycle_to_next--;
}
