/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 10:02:10 by khansman          #+#    #+#             */
/*   Updated: 2016/09/01 12:53:53 by rojones          ###   ########.fr       */
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

/*int		main(int argc, char **argv)
  {
  static t_env	env;

  init_env(&env);//initialise all the enviroment variables.
  manage_args(&env, argc, argv);//setup the flag details.
  read_programs(&env);//reads from the .cor files into memory.
  run_simulation(&env);//runs the corewar battle.
  free_env(&env);//frees all the malloced instructions.
  }*/

/*static void get_arg_code(char_u encode, t_arg_code *arg_code)
  {
  arg_code->arg1 = (C_ARG1(encode));
  arg_code->arg2 = (C_ARG2(encode));
  arg_code->arg3 = (C_ARG3(encode));
  arg_code->total = get_arg_len(arg_code->arg1) +
  get_arg_len(arg_code->arg2) +  get_arg_len(arg_code->arg3);
  }*/

/*static void	print_process(t_process *pro)
{
	int	i;

	i = -1;
	printf("player %s pc %lu, pi %lu, carry %d, cycle to next %d \n", pro->player->file_name,
			pro->pc, pro->pi, pro->carry, pro->cycle_to_next);
	while (++i < REG_NUMBER)
	{
		printf("register %d\n", i + 1);
		dump_memory(pro->registers[i], REG_SIZE, REG_SIZE);
	}
	puts("");
}*/

int	main(int argc, char **argv)
{
	t_env	env;
//	t_process	pro;
//	t_arg_code	acode;
	t_list		*ls;
//	char_u temp[] = {0x03,0x00,0x05, 0x20, 0x0c, 0xff, 0x50, 0x03, 0x0b, 0xf0, 0xff};

	init_env(&env);
	manage_args(&env, argc, argv);
	read_programs(&env);
//	pro = (t_process){&env.players[0], MEM_SIZE - 10, MEM_SIZE - 15, 0, 0, (reg_t*)malloc(sizeof(reg_t) * REG_NUMBER)};
//	int	i = -1;
//	while (++i < REG_NUMBER)
//		bzero(pro.registers[i], REG_SIZE);

//	i = MAX_PLAYERS;
//	while(i--)
//		printf("i %d, init %d num %d %s\n", i, env.players[i].init,env.players[i].number, env.players[i].player_ref.prog_name);

//		memcpy(&env.memory[MEM_SIZE - 15], temp, sizeof(temp));
//		memcpy(pro.registers[0], &((reg_t){0xf0, 0x20, 0x0c, 0xff}), REG_SIZE);
//		memcpy(pro.registers[2], &((reg_t){0x50, 0x03, 0x0b, 0xf0}), REG_SIZE);
	//get_arg_code(env.memory[pro.pi + 1], &acode);
//	acode = (t_arg_code){0,0,0,0};
/*	puts("reg one before ft_load");
	dump_memory(pro.registers[0], sizeof(reg_t),4);
	puts("reg two before ft_load");
	dump_memory(pro.registers[1], sizeof(reg_t),4);
	puts("reg three before ft_load");
	dump_memory(pro.registers[2], sizeof(reg_t), 4);*/
//	puts("actule father");
//	print_process(&pro);
//	puts("befor fork");
	ls = env.processes;
	while(ls)
	{
//		print_process((t_process *)ls->content);
		ls = ls->next;
	}
	dump_memory(env.memory, MEM_SIZE, 32);
/*	ft_fork(&env, acode, &pro);
	puts("\nafter fork");
	ls = env.processes;
	while(ls)
	{
		print_process((t_process *)ls->content);
		ls = ls->next;
	}*/
/*	puts("reg one after ft_load");
	dump_memory(pro.registers[0], sizeof(reg_t), 4);
	puts("reg two after ft_load");
	dump_memory(pro.registers[1], sizeof(reg_t), 4);
	puts("reg three after ft_load");
	dump_memory(pro.registers[2], sizeof(reg_t), 4);
	//	dump_memory(env.memory, MEM_SIZE);
	//		dump_memory(pro.carry, pro.carry, 4);*/
//	free(pro.registers);
	free_env(&env);
}
