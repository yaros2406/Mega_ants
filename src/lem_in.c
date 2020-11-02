/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:46:18 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 20:12:08 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_options(t_options *opt)
{
	opt->help = FALSE;
	opt->visual = FALSE;
	opt->graph = FALSE;
	opt->paths = FALSE;
}

static void		parse_options(t_options *opt, int ac, char **av)
{
	int	i;

	init_options(opt);
	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-h") || ft_strequ(av[i], "--help"))
			opt->help = TRUE;
		if (ft_strequ(av[i], "-v") || ft_strequ(av[i], "--visual"))
			opt->visual = TRUE;
		if (ft_strequ(av[i], "-a") || ft_strequ(av[i], "--anthill"))
			opt->graph = TRUE;
		if (ft_strequ(av[i], "-p") || ft_strequ(av[i], "--paths"))
			opt->paths = TRUE;
		if (!ft_strequ(av[i], "-h") && !ft_strequ(av[i], "--help")
			&& !ft_strequ(av[i], "-v") && !ft_strequ(av[i], "--visual")
			&& !ft_strequ(av[i], "-a") && !ft_strequ(av[i], "--anthill")
			&& !ft_strequ(av[i], "-p") && !ft_strequ(av[i], "--paths"))
		{
			opt->help = TRUE;
			return ;
		}
		i++;
	}
}

static void		init_parsing(t_input *p)
{
	p->index = 0;
	p->ants = 0;
	p->prev_cmd = FALSE;
	p->source = -1;
	p->sink = -1;
	p->nodes = NULL;
	p->x = NULL;
	p->y = NULL;
	p->from = NULL;
	p->to = NULL;
	p->file = NULL;
}

int				main(int ac, char **av)
{
	t_options	o;
	t_input		p;
	t_graph		*graph;
	t_list		*aug_paths;

	parse_options(&o, ac, av);
	if (o.help == TRUE)
	{
		ft_putstr("Usage:\n./lem-in [-h --help] [-a --anthill] ");
		ft_putendl("[-p --paths] [-v --visual] < [path/map_name]");
		return (EXIT_SUCCESS);
	}
	init_parsing(&p);
	if (parse_file(&p) == FAILURE)
		return (EXIT_FAILURE);
	if ((graph = build_graph(&p)) == NULL)
		return (EXIT_FAILURE);
	if ((aug_paths = find_paths(graph)) == NULL)
		return (search_error(&p, graph));
	print_file(&p);
	if (solver(graph, aug_paths, &o) == FAILURE)
		return (EXIT_FAILURE);
	ft_lstdel(&aug_paths, ft_delcontent);
	return (EXIT_SUCCESS);
}
