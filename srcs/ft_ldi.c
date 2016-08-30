/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:11:44 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/30 17:54:39 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
 * This operation modifies the carry. return 1 or 0
 * ldi 3,%4,r1 reads IND_SIZE bytes at address: 
 * (PC + (3 % IDX_MOD)), adds 4 to this value. 
 *
 * We will name this sum S.
 * Read REG_SIZE bytes at address (PC + (S % IDX_MOD)), 
 * which are copied to r1. Parameters 1 and 2 are indexes.
 *
 * ldi,its code is 0x0a. 
 * it will use 2 indexes and 1 registry
 * add the first two, treating that like an address, 
 * reading a value of a registry’s size and putting it on the third.
 */

int		ft_load_index(t_env *env, t_arg_code acode, t_process *pro)
{
	int i;
	ul_int	value1;
	ul_int	value2;

	i = 0;
	value1 = 0;
	value2 = 0;
	if (acode.arg1 == REG_CODE || acode.arg2 == REG_CODE ||
			acode.arg3 != REG_CODE)
		return (0);
	while (++i < IND_SIZE)
	{
		value1 = (value1 << 8) + env->memory[loop_mem(pro->pi + 2 + i)];
		value2 = (value2 << 8) +
			env->memory[loop_mem(pro->pi + 2 + i + IND_SIZE)];
	}

	i = 0;

	printf("value 1 in loop%lx\n", value1);
	printf("value 2 in loop%lx\n", value2);
	printf("\n\nvalue 1 before%lx\n", value1);
	value1 = (pro->pc + (value1 % IDX_MOD)) + value2 ;
	printf("value 1 after%lx\n", value1);
	printf("value 2 %lx\n\n", value2);


	printf("IND SIZE%d\n\n", IND_SIZE);

















	return (1);
}







/*
static void		store_result(char_u reg, 


static char_u	*get_arg(t_env *env, t_process *pro, int acode, ul_int value)
{
	char_u *ret;

	ret = NULL;
	if (acode == DIR_CODE)
		ret == get_dir(env->memory, pro->pi + value);
	else if (acode == IND_CODE)
		ret = get_indir(env->memory, pro->pi + value, pro);
	return (ret);
}


	
	
	
	
	
	
	//////////////////////////////CRAP
		printf("fdfdsf %i\n", env->num_players);
		printf("pro->pi %lx\n", pro->pi);
		printf("acode1 %i\n", acode.arg1);
		printf("acode2 %i\n", acode.arg2);
		printf("acode3 %i\n", acode.arg3);
		printf("asdasdasdas %i\n", env->num_players);
	//////////////////////////////////////////////////

	ul_int	index;
	char_u	*value1;
	char_u	*value2;
	char_u	*reg;

	index = 0;
	value1 = NULL;
	value2 = NULL;
	
	if (acode.arg1 == REG_CODE || acode.arg2 == REG_CODE)
		return (0);
	value1 = get_arg(env, pro, acode.arg1, pro->pi + 2);
	
	value2 = (pro->pc + (arg1 % IDX_MOD))
	
	while (

*/

/*
	read IND_SIZE at  address (pro->pc + (arg1 % IDX_MOD))
	add read value with acode.arg2;

	read REG_SIZE at address (PC + ("sum" % IDX_MOD))
*/
