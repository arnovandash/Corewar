/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 09:45:12 by khansman          #+#    #+#             */
/*   Updated: 2016/08/24 10:59:44 by rojones          ###   ########.fr       */
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
**		Error Messages:
*/
# define ERR_MSG_00 "Error: Not enough memory avaliable."

/*
** -----------
** Structures:
** -----------
*/

typedef unsigned long int ul_int;
typedef unsigned int u_int;
typedef unsigned char char_u;
typedef unsigned char reg[REG_SIZE] ;

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
	u_int		live;
	char		carry;
	int			cycle_to_next;
	reg			*reg; //malloc to REG_NUMBER
}				t_process;

typedef struct	s_arg_len
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	total;
}				t_arg_len;

typedef struct	s_env
{
	char_u		*memory; //malloc to MEM_SIZE
	int			num_players;
	t_player	players[MAX_PLAYERS];
	t_list		*processes;
	ul_int		cycle;
	ul_int		dump_cycle;
	int			check_from_mod;
	ul_int		cycles_to_die;
	t_player	*last_alive;
	void        (*function[17])(struct s_env *env, t_arg_len arg_len, t_process *process);
}				t_env;

/*
** --------------------
** Function Prototypes:
** --------------------
*/

/*
**		Preprogramming prototypes:
*/
void			manage_args(t_env *env, int argc, char **argv);
void			read_program(t_env *env);
void			run_simulation(t_env *env);

/*
**		error_quit.c
*/
void			error_quit(int error);
/*
**		free_env.c
*/
void			free_env(t_env *env);
/*
**		init_env.c
*/
void			init_env(t_env *env);

#endif

/*
** register = 1 byite code 01
** direct = 4 code 10 define in op.h '%' else if index  byte = 2
** indirect = 2 code 11
*/

/*
**	Kesh:  1,   4,  7   0 assembler
**	Rob :  2,   3,  5,  8 run_simulation
**	Arno:  9,  10, 11, 12 read_program
**	Lee : 13,  14, 15, 16 manage_args, init & free
*/

/*
**end
*/
