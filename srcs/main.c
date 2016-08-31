/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 10:02:10 by khansman          #+#    #+#             */
/*   Updated: 2016/08/31 15:37:24 by rojones          ###   ########.fr       */
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
	run_simulation(&env);//runs the corewar battle.
	free_env(&env);//frees all the malloced instructions.
}

/*static void get_arg_code(char_u encode, t_arg_code *arg_code)
  {
  arg_code->arg1 = (C_ARG1(encode));
  arg_code->arg2 = (C_ARG2(encode));
  arg_code->arg3 = (C_ARG3(encode));
  arg_code->total = get_arg_len(arg_code->arg1) +
  get_arg_len(arg_code->arg2) +  get_arg_len(arg_code->arg3);
  }

  int	main(int argc, char **argv)
  {
  t_env	env;
  t_process	pro;
  t_arg_code	acode;
  char_u temp[] = {0x03,0xa4,0xf0, 0x20, 0x0c, 0xff, 0x50, 0x03, 0x0b, 0xf0, 0xff};

  init_env(&env);
  manage_args(&env, argc, argv);
  read_programs(&env);
  pro = (t_process){&env.players[0], 5, 0, 0, 0, (reg_t*)malloc(sizeof(reg_t) * REG_NUMBER)};
  int	i = -1;
  while (++i < REG_NUMBER)
  bzero(pro.registers[i], REG_SIZE);

  i = MAX_PLAYERS;
  while(i--)
//		printf("i %d, init %d num %d %s\n", i, env.players[i].init,env.players[i].number, env.players[i].player_ref.prog_name);

memcpy(env.memory, temp, sizeof(temp));
//	memcpy(pro.registers[0], &((reg_t){0xf0, 0x20, 0x0c, 0xff}), REG_SIZE);
//	memcpy(pro.registers[2], &((reg_t){0x50, 0x03, 0x0b, 0xf0}), REG_SIZE);
get_arg_code(env.memory[pro.pi + 1], &acode);
//	acode = (t_arg_code){0,0,0,0};
puts("reg one before ft_load");
dump_memory(pro.registers[0], sizeof(reg_t),4);
puts("reg two before ft_load");
dump_memory(pro.registers[1], sizeof(reg_t),4);
puts("reg three before ft_load");
dump_memory(pro.registers[2], sizeof(reg_t), 4);
ft_and(&env, acode, &pro);
puts("reg one after ft_load");
dump_memory(pro.registers[0], sizeof(reg_t), 4);
puts("reg two after ft_load");
dump_memory(pro.registers[1], sizeof(reg_t), 4);
puts("reg three after ft_load");
dump_memory(pro.registers[2], sizeof(reg_t), 4);
//	dump_memory(env.memory, MEM_SIZE);
//		dump_memory(pro.carry, pro.carry, 4);
free(pro.registers);
free_env(&env);
}*/
