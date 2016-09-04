/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:19:09 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/03 12:19:10 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_arg_type	ft_gettype(char *param)
{
	while (*param == ' ' || *param == '\t')
		param++;
	if (*param == 'r')
		return (T_REG);
	else if (*param == '%')
		return (T_DIR);
	return (T_IND);
}
