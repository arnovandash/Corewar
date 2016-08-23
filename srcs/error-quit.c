/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:59:13 by khansman          #+#    #+#             */
/*   Updated: 2016/08/22 13:59:14 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The functions in this program are supposed to display the appropiate
**	error message, before exitting the program. 
*/

void	error_quit(int error)
{
	if (error == 0)
		ft_putstr(ERR_MSG_00);
	exit(0);
}
