/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:42:22 by oexall            #+#    #+#             */
/*   Updated: 2016/08/27 10:02:04 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	ft_init(t_all *all)
{
	all->header.magic = COREWAR_EXEC_MAGIC;
	all->header.prog_size = 0;
	all->data = NULL;
	all->cmd = NULL;
	all->tab = NULL;
	all->multi = 0;
	all->filename = NULL;
}

static void	ft_free(t_all *all)
{
	all->header.magic = 0;
	all->filename = NULL;
	//all->header.prog_size = 0;
	ft_free_data(&all->data);
	ft_free_cmd(&all->cmd);
	//free(&all->tab);
}

static void	ft_print_details(t_all *all)
{
	ft_putstr("Assembling ");
	ft_putendl(all->filename);
	ft_putstr("\t");
	ft_putendl(all->header.prog_name);
	ft_putstr("\t");
	ft_putendl(all->header.comment);
}

int			main(int argc, char **argv)
{
	t_all	all;
	int		i;

	ft_init(&all);
	if (argc < 2)
		return (ft_error(&all, "Invalid parameters.\nUsage: ./asm [*.s] ..."));
	i = 0;
	while (argv[++i])
	{
		all.filename = argv[i];
		if (!ft_read_check(&all))
			break ;
		if (!ft_read_file(&all))
			break ;
		if (!ft_validate(&all))
			break ;
		if (!ft_print(&all))
			break ;
		ft_print_details(&all);
		ft_free(&all);
	}
	return (0);
}
