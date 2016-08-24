/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 10:02:10 by khansman          #+#    #+#             */
/*   Updated: 2016/08/24 11:32:26 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** The main has been made as simple as possible to make the code easy 
**	to understand, and it easy to delegate parts of the program to different
**	programers. In order for the main to remain simplified each section will
**	have to manage it's own error quiet options separatly. Please keep in mind
**	that the error quit option should free everything that has been malloced
**	prior to the functions call. As a result the free env function must be
**	carefull to never free something which hasn't been malloced yet.
*/

int		main(int argc, char **argv)
{
	static t_env	env;

	init_env(&env);//initialise all the enviroment variables.
	manage_args(&env, argc, argv);//setup the flag details.
	read_programs(&env);//reads from the .cor files into memory.
	if (env.processes == NULL)
		puts("ERROR: no processes ?????????????????????");
//	run_simulation(&env);//runs the corewar battle.
	free_env(&env);//frees all the malloced instructions.
}
