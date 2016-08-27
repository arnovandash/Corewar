/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 09:45:12 by khansman          #+#    #+#             */
/*   Updated: 2016/08/27 07:44:45 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a prototype header file for the corewar vm.
*/

#ifndef COREWAR_H
# define COREWAR_H

/*
** ---------
** Includes:
** ---------
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# include "libft.h"
# include "op.h"

/*
** --------
** Defines:
** --------
*/

/*
**		Shorthand:
*/
# define L_STATE t_live_state
# define PROCESS t_process
# define PROCES2 struct s_process

# define C_ARG1(x) (x & 0b11000000) >> 6
# define C_ARG2(x) (x & 0b00110000) >> 4
# define C_ARG3(x) (x & 0b00001100) >> 2
# define C_ARG4(x) (x & 0b00000011)

/*
**		Instructions:
*/
# define LIVE  0x01
# define LD    0x02
# define ST    0x03
# define ADD   0x04
# define SUB   0x05
# define AND   0x06
# define OR    0x07
# define XOR   0x08
# define ZJMP  0x09
# define LDI   0x0a
# define STI   0x0b
# define FORK  0x0c
# define LLD   0x0d
# define LLDI  0x0e
# define LFORK 0x0f
# define AFF   0x10

/*
**		Colour codes:
*/
# define C_RED \e[31m

/*
**		Error Messages:
*/
# define ERR_MSG_00 "\e[31mError: Not enough memory avaliable.\n"
# define ERR_MSG_01 "\e[31mError: No arguments specified.\n"
# define ERR_MSG_02 "\e[31mError: Multiple definitions for dump cycles.\n"
# define ERR_MSG_03 "\e[31mError: Invalid dump cycle.\n"
# define ERR_MSG_04 "\e[31mError: Invalid player set.\n"
# define ERR_MSG_05 "\e[31mError: Player Number has already been set.\n"
# define ERR_MSG_06 "\e[31mError: Max players already reached.\n"

/*
**		Strings:
*/

/*
** -----------
** Structures:
** -----------
*/

typedef unsigned long int ul_int;
typedef unsigned int u_int;
typedef unsigned char char_u;
typedef unsigned char reg_t[REG_SIZE];

typedef struct	s_player
{
	char		*file_name; //passed in argv
	int			number; // if -n else the previous +1
	u_int		live;
	t_header	player_ref; // filled by Arno
}				t_player;

typedef struct	s_process
{
	t_player	*player;
	ul_int		pc;// program counter the next function to run
	ul_int		pi;// program index the current index of the program
	char		carry;
	int			cycle_to_next;
	reg_t		*registers; //malloc to REG_NUMBER
}				t_process;

typedef struct	s_arg_code
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	total;
}				t_arg_code;

typedef struct	s_env
{
	char_u		*memory; //malloc to MEM_SIZE
	int			num_players;
	t_player	players[MAX_PLAYERS];
	t_list		*processes;
	ul_int		cycle;
	unsigned long int		dump_cycle;
	int			check_for_mod;
	ul_int		cycles_to_die;
	t_player	*last_alive;
	int        (*function[17])(struct s_env *env, t_arg_code arg_code, t_process *process);
}				t_env;

/*
** --------------------
** Function prototypes:
** --------------------
*/

/*
**		destroy_process.c
*/
void			destroy_process(t_list *dest, t_list *pre);
int				get_arg_len(int arg_code);
void			dump_memory(char_u *mem, ul_int size);

/*
**		error_quit.c
*/
void			error_quit(int error);
/*
**		free_env.c
*/
void			free_data(void *data, size_t size);
void			free_env(t_env *env);
/*
**		init_env.c
*/
int				ft_set_player_number(t_env *env, char *s1, char *s2);
int				ft_set_dump_cycle(t_env *env, char *str);
void			init_env(t_env *env);
/*
**		init_functions.c
*/
void			init_functions(t_env *env);
/*
** loop_mem.c
*/
ul_int			loop_mem(ul_int check);
/*
**		manage_args.c
*/
void			init_list(t_env *env);
void			manage_args(t_env *env, int argc, char **argv);
/*
**		read_program.c
*/
void			read_programs(t_env *env);
/*
**		run_process.c
*/
void			run_process(t_env *env, t_process *pro);
/*
**		run_simulation.c
*/
void			run_simulation(t_env *env);
/*
**		get argument
*/
char_u			*get_dir(char_u *mem, ul_int offset);
char_u			*get_indir(char_u *mem, ul_int offset, t_process *pro);
char_u			*get_indir_long(char_u *mem, ul_int offset, t_process *pro);
char_u			*get_reg(t_env *env, t_process *pro, ul_int offset);
/*
**		game operations
*/
int				ft_load(t_env *env, t_arg_code a_case, t_process *pro);
int				ft_store(t_env *env, t_arg_code acode, t_process *pro);
int				ft_sub(t_env *env, t_arg_code arg_code, t_process *pro);
int				ft_xor(t_env *env, t_arg_code acode, t_process *pro);
#endif

/*
**	Kesh:  1,   4,  7   0 assembler
**	Rob :  2,   3,  5,  8 run_simulation
**	Arno:  9,  10, 11, 12 read_program
**	Lee : 13,  14, 15, 16 manage_args, init & free
*/

/*
**end
*/
