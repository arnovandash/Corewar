/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:45:27 by oexall            #+#    #+#             */
/*   Updated: 2016/08/27 09:42:12 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define FILE_ERR_1 "Invalid File Name.\nusage: ./asm [*.s] ..."

# include <op.h>
# include <stdio.h>
# include <libft.h>
# include <fcntl.h>

typedef struct		s_data
{
	int				line_no;
	char			*line;
	struct s_data	*next;
}					t_data;

typedef struct		s_cmd
{
	char			*label;
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct		s_all
{
	t_header		header;
	t_data			*data;
	t_cmd			*cmd;
	int				fd;
	int				multi;
	char			**tab;
	char			*filename;
}					t_all;

int					ft_error(t_all *all, char *str);
char				*ft_trimqu(char *str);
char				*ft_trimsp(char *str);
int					ft_oneof(char c, char *in);
void				ft_free_split(char **split);
void				ft_reverse_bytes(void *mem, size_t size);
int					ft_getindex(char *src);
t_arg_type			ft_gettype(char *param);
int					ft_iswhiteonly(char *str);

t_data				*ft_new_data(char *line, int line_no);
void				ft_push_back_data(t_data **begin, char *line, int line_no);
void				ft_free_data(t_data **begin);

t_cmd				*ft_new_cmd(char *cmd, char *lbl);
void				ft_push_back_cmd(t_cmd **begin, char *cmd, char *lbl);
void				ft_free_cmd(t_cmd **begin);

int					ft_read_check(t_all *all);
int					ft_read_file(t_all *all);

int					ft_val_prog(t_all *all, char *prog);
int					ft_val_comment(t_all *all, char *comment);
int					ft_val_label(t_all *all, char *label);
int					ft_is_valid(t_all *all, char *str, char *lbl);
int					ft_validate(t_all *all);

int					ft_print(t_all *all);
int					ft_print_header(t_all *all);
int					ft_print_cmds(t_all *all);
int					ft_print_reg(t_all *all, char *reg);
int					ft_print_dir(t_all *all, char *dir, int index, t_cmd *cmd);
int					ft_print_ind(t_all *all, char *ind);
int					ft_print_lbl(t_all *all, char *lbl, t_cmd *cmd);

int					check_digit(char *str);
#endif
