/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:38:03 by rojones           #+#    #+#             */
/*   Updated: 2016/08/25 14:48:48 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_load_reg(t_env *env, t_process *pro, char_u reg_arg2)
{
	char_u	reg_arg1;

	reg_arg1 = 0;
	reg_arg1 = (pro->pi + 2 < MEM_SIZE) ? env->memory[pro->pi + 2] - 1:
		env->memory[pro->pi + 2 - MEM_SIZE] - 1;
   	puts("regnumber");
	ft_print_hex(reg_arg1);
	if (reg_arg1 < REG_NUMBER)
		ft_memcpy(pro->registers[reg_arg2], pro->registers[reg_arg1], REG_SIZE);
}

static void	ft_load_dir(t_env *env, reg_t regarg2, ul_int index)
{
	int	i;
	
	i = -1;
	while (++i < REG_SIZE)
		regarg2[i] = (index + i < MEM_SIZE) ? env->memory[index + i] :
			env->memory[index + i - MEM_SIZE];
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
	start = (pro->pc + (jump % IDX_MOD) < MEM_SIZE) ?
		pro->pc + (jump % IDX_MOD) :
		pro->pc + (jump % IDX_MOD) - MEM_SIZE;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg_arg2][i] = ((start + i) > MEM_SIZE) ?
			env->memory[(start + i) - MEM_SIZE] : env->memory[start + i];
}

void	ft_load(t_env *env, t_arg_code a_case, t_process *pro)
{
	char_u	reg_num;

	pro->carry = (pro->carry == 0) ? 1 : 0;
	if (a_case.arg2 != REG_CODE)
		return ;
	reg_num = (pro->pi + 2 + get_arg_len(a_case.arg1) < MEM_SIZE) ?
		env->memory[pro->pi + 2 + get_arg_len(a_case.arg1)] - 1 :
		env->memory[pro->pi + 2 + get_arg_len(a_case.arg1) - MEM_SIZE] - 1;
	if (reg_num < REG_NUMBER)
	{
		if (a_case.arg1 == REG_CODE)
			ft_load_reg(env, pro, reg_num);
		else if (a_case.arg1 == DIR_CODE)
			ft_load_dir(env, pro->registers[reg_num], pro->pi + 2);
		else if (a_case.arg1 == IND_CODE)
			ft_load_indir(env, pro, reg_num);
	}
}
