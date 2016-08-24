/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:48:58 by rojones           #+#    #+#             */
/*   Updated: 2016/08/24 12:22:02 by rojones          ###   ########.fr       */
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

static void init_arg_len(t_arg_len *arg_len)
{
	arg_len->arg1 = 0;
	arg_len->arg2 = 0;
	arg_len->arg3 = 0;
	arg_len->total = 0;
}

static int arg_case(char_u code)
{
	if (code == 1)
		return (1);
	if (code == 2)
		return (DIR_SIZE);
	if (code == 3)
		return (IND_SIZE);
	return (0);
}

static void get_arg_len(char_u encode, t_arg_len *arg_len )
{   
	arg_len->arg1 = arg_case(C_ARG1(encode));
	arg_len->arg2 = arg_case(C_ARG2(encode));
	arg_len->arg3 = arg_case(C_ARG3(encode)); 
	arg_len->total = arg_len->arg1 + arg_len->arg2 + arg_len->arg3;
}

void	run_process(t_env *env, t_process *pro)
{
	char_u		opcode;
	t_arg_len	arg_len;

	init_arg_len(&arg_len);
	opcode = env->memory[pro->pc];
	pro->pi = pro->pc;
	if (opcode > 0 && opcode < 17 && (opcode != 1 || opcode != 9 || opcode != 12
				|| opcode != 14 || opcode != 16))
	{
		get_arg_len(env->memory[opcode + 1], &arg_len);
		pro->pc = (pro->pc + arg_len.total > MEM_SIZE) ?
			pro->pc + arg_len.total - MEM_SIZE :
			pro->pc + arg_len.total;
	}
	else
		set_pc(pro, opcode);
	if (opcode < 17)
		(*env->function[opcode])(env, arg_len, pro);
}
