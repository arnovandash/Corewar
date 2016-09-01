/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 09:45:12 by khansman          #+#    #+#             */
/*   Updated: 2016/09/01 09:06:05 by rojones          ###   ########.fr       */
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
# define R_SP(x) x % (REG_SIZE * sizeof(t_reg))
# define MEM env->memory
# define PC_P(x) ft_pc_pos(arg_len, x, pro->pc)
# define MEM_ARG(x) env->memory[ft_pc_pos(arg_len, x, pro->pc)]

# define PRO_REG process.registers
# define PRO_PLA process.player
# define REG_SIZ sizeof(t_reg)

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
# define ERR_MSG_04 "\e[31mError: Invalid player set. Expecting player 0 - 3\n"
# define ERR_MSG_05 "\e[31mError: Player Number has already been set.\n"
# define ERR_MSG_06 "\e[31mError: Max players already reached.\n"
# define ERR_MSG_07 "\e[31mError: Unable to open champion file.\n"
# define ERR_MSG_08 "\e[31mError: Invalid champion file.\n"
# define ERR_MSG_09 "\e[31mError: Champion too large for memory space.\n"
# define ERR_MSG_10 "\e[31mError: Program size mismatch.\n"

/*
**		Strings:
*/

/*
** -----------
** Structures:
** -----------
*/

typedef unsigned long int	ul_int;
typedef unsigned int		u_int;
typedef unsigned char		char_u;
typedef unsigned char		reg_t[REG_SIZE];
typedef unsigned char		t_reg[REG_SIZE];

typedef struct	s_player
{
	char		*file_name; //passed in argv
	int			number; // if -n else the previous +1
	int			init;
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
	t_reg		*registers; //malloc to REG_NUMBER
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
	int			fd;
	ul_int		dump_cycle;
	int			check_for_mod;
	ul_int		cycles_to_die;
	t_player	*last_alive;
}				t_env;

extern int        (*function[])(struct s_env *env, t_arg_code arg_code, t_process *process);
/*
** --------------------
** Function prototypes:
** --------------------
*/

void			destroy_process(t_list **dest, t_list **pre, t_list **head);
int				get_arg_len(int arg_code);
void			dump_memory(char_u *mem, ul_int size, int line);

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
**		ft_aff.c
*/
int				ft_aff(t_env *env, t_arg_code arg_len, t_process *pro);
/*
**		ft_long_fork.c
*/
int				ft_long_fork(t_env *env, t_arg_code arg_len, t_process *pro);
/*
**		ft_long_load.c
*/
int				ft_long_load(t_env *env, t_arg_code arg_len, t_process *pro);
/*
**		ft_long_load_index.c
*/
int 			ft_long_load_index(t_env *env, t_arg_code arg_len, t_process *pro);
/*
**		get_param_value.c
*/
int		get_param_value(t_env *env, ul_int pi, t_process *pro, char type);
/*
**		init_env.c
*/
void			init_player_struct(t_env *env, int player_num);
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
**		load_arena.c
*/
void			load_arena(t_env *env, int p_num);
/*
**		manage_args.c
*/
void			init_list(t_env *env);
void			manage_args(t_env *env, int argc, char **argv);
/*
**		pc_pos.c
*/
int				ft_pc_pos(t_arg_code arg_len, char arg, unsigned long pc);
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
**		set_param_value.c
*/
int				set_reg_value(t_process *pro, int value, unsigned int reg);
int				set_indir_value(t_env *env, int pi, int value);
int				set_dir_value(t_env *env, int pi, int value);


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
int				ft_live(t_env *env, t_arg_code code, t_process *pro);
int				ft_load(t_env *env, t_arg_code code, t_process *pro);
int				ft_store(t_env *env, t_arg_code code, t_process *pro);
int				ft_add(t_env *env, t_arg_code code, t_process *pro);
int				ft_sub(t_env *env, t_arg_code code, t_process *pro);
int				ft_and(t_env *env, t_arg_code code, t_process *pro);
int				ft_or(t_env *env, t_arg_code code, t_process *pro);
int				ft_xor(t_env *env, t_arg_code code, t_process *pro);
int				ft_zjump(t_env *env, t_arg_code code, t_process *pro);
int				ft_load_index(t_env *env, t_arg_code code, t_process *pro);
int				ft_store_index(t_env *env, t_arg_code code, t_process *pro);
int				ft_fork(t_env *env, t_arg_code code, t_process *pro);
int				ft_long_load(t_env *env, t_arg_code code, t_process *pro);
int				ft_long_load_index(t_env *env, t_arg_code code, t_process *pro);
int				ft_long_fork(t_env *env, t_arg_code code, t_process *pro);
int				ft_aff(t_env *env, t_arg_code code, t_process *pro);

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
