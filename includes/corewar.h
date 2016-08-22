/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 09:45:12 by khansman          #+#    #+#             */
/*   Updated: 2016/08/21 09:45:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a prototype header file for the corewar vm.
*/

#ifndef COREWAR_H
# define COREWAR_H

/*
** Includes:
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

/*
** Defines:
*/

/*
**		Set_up:
*/
# define CORESIZE     4096
# define REG_SIZE     4
# define REG_NUMBER   CORESIZE
# define CYCLE_DELTA  1000
# define CYCLE_TO_DIE CYCLE_DELTA
# define NBR_LIVE     1
# define MAX_PLAYERS  2

/*
**		Shorthand:
*/
# define L_STATE t_live_state
# define PROCESS t_process
# define PROCES2 struct s_process

# define C_TYPE 0b11110000000000000000000000000000 >> 28
# define C_MO_A 0b00001100000000000000000000000000 >> 26
# define C_MO_B 0b00000011000000000000000000000000 >> 24
# define C_FI_A 0b00000000111111111111000000000000 >> 12
# define C_FI_B 0b00000000000000000000111111111111 >> 00

/*
**		Modes:
*/
# define IMMIDIAT 0
# define RELATIVE 1
# define INDIRECT 2

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
** Structures:
*/

typedef struct	s_live_state
{
	int			l_count_p1;
	int			l_count_p2;
	int			cycles_to_die;
	char		last_call;
}				t_live_state;

typedef struct	s_process
{
	char		player;
	int			address;
	PROCES2		*next;
}				t_process;

typedef struct	s_settings
{
	int			dump_cycle;
	int			pc;
}				t_settings;

typedef struct	s_env
{
	L_STATE		live;
	t_settings	settings;
	t_process	*processes;
	int			*core;
}				t_env;

/*
** Function Prototypes:
*/

/*
**		Preprogramming prototypes:
*/
void			init_env(t_env *env);
void			manage_args(t_env *env, int argc, char **argv);
void			read_program(t_env *env);
void			run_simulation(t_env *env);
void			free_env(t_env *env);

/*
**				main.c
*/
int				main(int argc, char **argc);

#endif

/*
**	Kesh:  1,   4,  7   0
**	Rob :  2,   3,  5,  8
**	Arno:  9,  10, 11, 12
**	Lee : 13,  14, 15, 16
*/

/*
**end
*/
