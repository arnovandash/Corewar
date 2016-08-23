/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:48:58 by rojones           #+#    #+#             */
/*   Updated: 2016/08/23 18:06:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_arg_len(t_arg_len *arg_len)
{
	arg_lem->arg1 = 0;
	arg_lem->arg2 = 0;
	arg_lem->arg3 = 0;
}

static void	get_arg_len(char_u encod, t_arg_len *arg_len)
{
	arg_lem->arg1 = encode & C_ARG1;
	arg_lem->arg2 = encode & C_ARG2;
	arg_lem->arg3 = encode & C_ARG3;
}
void	run_process(t_env *env, t_process *pro)
{
	int			opcode;
	t_arg_len	arg_len;

	init_arg_len(&ar_glen);
	if (pro->pc > MEM_SIZE)
		pro->pc = pro->pc - MEM_SIZE;
	opcode = env->memory[pro->pc];
	if (opcode != 1 || opcode != 9 || opcode != 13 || opcode != 14 ||
			opcode != 16)
		get_arg_len(env->memory[opcode + 1], &arg_len);
	if (opcod < 17)
		(*env->function[opcode])(env, arg_len, pro)
}
