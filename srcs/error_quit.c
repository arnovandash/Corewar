/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:59:13 by khansman          #+#    #+#             */
/*   Updated: 2016/08/22 13:59:14 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The functions in this file are supposed to display the appropiate
**	error message, before exitting the program. 
*/

void	error_quit(int error)
{
	if (error == 0)
		ft_putstr(ERR_MSG_00);
	else if (error == 1)
		ft_putstr(ERR_MSG_01);
	else if (error == 2)
		ft_putstr(ERR_MSG_02);
	else if (error == 3)
		ft_putstr(ERR_MSG_03);
	else if (error == 4)
		ft_putstr(ERR_MSG_04);
	else if (error == 5)
		ft_putstr(ERR_MSG_05);
	else if (error == 6)
		ft_putstr(ERR_MSG_06);
	exit(0);
}
