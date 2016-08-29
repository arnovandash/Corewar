/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 10:02:10 by khansman          #+#    #+#             */
/*   Updated: 2016/08/29 13:30:07 by arnovan-         ###   ########.fr       */
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
		puts("ERROR: no processes ?????????????????????\n");

	//////////////////////// PRINT MEMORY FOR TESTING ////////////
	ul_int snoop = 0;
	while (snoop < MEM_SIZE)
	{
		printf("%02x", env.memory[snoop]);
		if ((snoop + 1) % 40 == 0)
			printf("\n");
		snoop++;
	}
		printf("\n");
	///////////////////////////////////////////////////////////////
		
	run_simulation(&env);//runs the corewar battle.
	free_env(&env);//frees all the malloced instructions.
}
