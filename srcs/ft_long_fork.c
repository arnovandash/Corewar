/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 09:43:14 by khansman          #+#    #+#             */
/*   Updated: 2016/08/27 10:22:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_long_fork(t_env *env, t_arg_len arg_len, t_process *pro)
{
	t_list		*new;
	t_list		*temp;

	if (!(new = ft_lstnew(pro, sizeof(t_process))) || !(new->content->registers
				= (reg_t *)malloc(sizeof(reg_t) * REG_NUMBER)))
		error_quit(0);
	ft_memcpy(new->content->registers, pro->registers, 
			sizeof(reg_t) * REG_NUMBER);
	(t_process)new->content->pc += MEM_A(0);
	temp = env->processes;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	(void)arg_len;
	return (1);
}
