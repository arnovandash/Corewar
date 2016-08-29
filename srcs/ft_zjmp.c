/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 11:52:24 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/29 18:03:58 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char_u	*get_arg(t_env *env, t_process *pro, int acode, ul_int offset)
{
	char_u *re;

	re = NULL;
	if (acode == REG_CODE)
		re = get_reg(env, pro, pro->pi + offset);
	else if (acode == DIR_CODE)
		re = get_dir(env->memory, pro->pi + offset);
	else if (acode == IND_CODE)
		re = get_indir(env->memory, pro->pi + offset, pro);
	return (re);
}

int		ft_zjmp(t_env *env, t_arg_code acode, t_process *pro)
{
	char_u index;

	index = 0;
	printf ("arg code1: %x\n", acode.arg1);
	printf ("arg code2: %x\n", acode.arg2);
	printf ("arg code3: %x\n", acode.arg3);
	if (pro->carry == 1)// && acode.arg1 == IND_CODE)
	{
		pro->pc = (pro->pc + ( % IDX_MOD));
			  printf ("NEW PC POSITION%04lx:\n",pro->pc);
			  printf ("get arg str%c:\n",*get_arg(env, pro, acode.arg1, pro->pi + 2));
		index = *get_arg(env, pro, acode.arg1, pro->pi + 2);
			  printf ("arg codeindex: %x\n", index);
		pro->pc = (pro->pc + (index % IDX_MOD));
	}
	return (pro->carry);
}
