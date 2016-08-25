/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:05:50 by rojones           #+#    #+#             */
/*   Updated: 2016/08/25 10:06:52 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static reg_t	get_reg(t_env *env, t_process *pro, ul_int offset)
{
	reg_t	temp;
	char_u	reg;

	ft_bezero(temp, REG_SIZE);
	reg = (offset < MEM_SIZE) ?
		env->memory[offset] - 1 : env->memory[offset - MEM_SIZE] - 1;
	if (reg < REG_NUMBER)
			ft_memcpy(temp, pro->registers[reg], REG_SIZE);
	return (temp);
}

static reg_t	get_dir(char_u *mem, ul_int offset)
{
	reg_t	temp;
	int		i;

	ft_bezero(temp, REG_SIZE);
	i = -1;
	while (++i)
		temp[i] = (offset + i < MEM_SIZE) ? mem[offset] :
			mem[offset - MEM_SIZE];
	return (remp);
}

static reg_t	get_inder(char_u *mem, ul_int offset)
{
	reg_t	temp;
	ul_int	jump;
	int		i;

	jump = 0;
	i = -1;
	ft_bezero(temp, REG_SIZE);
	while (++i < IND_SIZE)
		jump = (offset + i < MEM_SIZE) ? (jump << 8) + mem[offset + i] :
			(jump << 8) + mem[offset + i - MEM_SIZE];
	i = -1;
	jump = (pro->pc + (jump % MOD_IND) < MEMSIZE) ? pro->pc + (jump % MOD_IND) :
		pro->pc + (jump % MOD_IND) - MEM_SIZE;
	while (++i < REG_SIZE)
		temp[i] = (jump + i < MEM_SIZE) ? mem[jump + i] : mem[jump + i - MEM_SIZE];
	return (temp);
}

static void		store_result(char_u reg3, t_reg reg1, t_reg reg2, t_process *pro)
{
	int	i;

	if (reg3 > REG_NUMBER)
		return ;
	i = -1;
	while (++i < REG_SIZE)
		pro->registers[reg3][i] = reg1[i] ^ reg2[i];
}

void	ft_xor(t_env *env, t_arg_code acode, t_process *pro)
{
	t_reg	temp1;
	t_reg	temp2;
	ul_int	arg3;

	pro->carry = (pro->carry == 1) ? 0 : 1;
	if (acode.arg3 != REG_CODE)
		return ;
	if (acode.arg1 == REG_CODE)
		temp1 = get_reg(env, pro, pro->pi + 2);
	else if(acode.arg1 == DIR_CODE)
		temp1 = get_dir(env->memory, pro->pi + 2);
	else if(acode.arg1 == IND_CODE)
		temp1 = get_inder(env->memory, pro->pi + 2);
	if (acode.arg2 == REG_CODE)
		temp2 = get_reg(env, pro, pro->pi + 2 + get_arg_len(acode.arg1));
	else if(acode.arg2 == DIR_CODE)
		temp2 = get_dir(env->memory, pro->pi + 2 + get_arg_len(acode.arg1));
	else if(acode.arg2 == IND_CODE)
		temp2 = get_inder(env->memory, pro->pi + 2 + get_arg_len(acode.arg1));
	arg3 = (pro->pi + 2 + get_arg_len(acode.arg1) +  get_arg_len(acode.arg2) < MEM_SIZE) ?
		pro->pi + 2 + get_arg_len(acode.arg1) +  get_arg_len(acode.arg2):
		pro->pi + 2 + get_arg_len(acode.arg1) +  get_arg_len(acode.arg2) - MEM_SIZE;
	store_result(env->memory[arg3] - 1, temp1, temp2, pro);
}
