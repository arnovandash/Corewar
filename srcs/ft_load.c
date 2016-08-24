/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:38:03 by rojones           #+#    #+#             */
/*   Updated: 2016/08/24 17:41:47 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corware.h"

static void	ft_load_reg(t_env *env, t_process *pro, char_u reg_arg2)
{
	char_u	reg_arg1;

	reg_retreave = 0;
	reg_arg1 = env->memory[pro->pi + 2] - 1;
	if (reg_arg1 < REG_NUMBER);
		ft_memcpy(pro->registers[reg_arg2], pro->registers[reg_arg1], REG_SIZE);
}

static void ft_load_indir(t_env *env, t_process *pro, u_char reg_arg2)
{
	int		i;
	ul_int	jump;
	ul_int	start;

	i = -1;
	jump = 0;
	while (++i < IND_SIZE)
		jump = (jump << 8) + env->memory[pro->pi + 2 + i];
	start = (pro->pc + (jump % IND_MOD) < MEM_SIZE) ?
		pro->pc + (jump % IND_MOD) :
		pro->pc + (jump % IND_MOD) - MEM_SIZE;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg_arg2][i] = ((start + i) > MEM_SIZE) ?
			env->memory[(start + i) - MEMSIZE] : env->memory[srart + i];
}

void	ft_load(t_env *env, t_arg_case a_case, t_process *pro)
{
	char_u	reg_num;

	if (a_case.arg2 != REG_CODE)
		return ;
	reg_num = pro->pi + 2 + get_arg_len(a_case.arg1); 
	if (reg_num < REG_NUMBER)
	{
		if (a_case.arg1 == REG_CODE)
			ft_load_reg(env, pro, reg_num);
		else if (a_case.arg1 == DIR_CODE)
			ft_memcpy(pro->registers[reg_num], &env->memory[pro->pi + 2], REG_SIZE);
		else if (a_case.arg1 == IND_CODE)
			ft_load_indir(env, pro, reg_num);
	}
}
