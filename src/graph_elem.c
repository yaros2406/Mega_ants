/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:33:04 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 19:28:18 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static ssize_t	node_index(char *name, t_list *nodes)
{
	ssize_t	index;
	t_list	*curr;

	index = 0;
	curr = nodes;
	while (curr)
	{
		if (ft_strequ((char *)curr->content, name))
			return (index);
		curr = curr->next;
		index++;
	}
	return (FAILURE);
}

int8_t			save_edge(t_input *p, char *line)
{
	char	**tab;
	t_list	*new_from;
	t_list	*new_to;
	ssize_t	from_index;
	ssize_t	to_index;

	if ((tab = ft_strsplit(line, '-')) == NULL)
		return (parsing_error(p, line, tab));
	if ((from_index = node_index(tab[0], p->nodes)) == FAILURE)
		return (parsing_error(p, line, tab));
	if ((to_index = node_index(tab[1], p->nodes)) == FAILURE)
		return (parsing_error(p, line, tab));
	if ((new_from = ft_lstnew(&from_index, sizeof(ssize_t))) == NULL)
		return (parsing_error(p, line, tab));
	if ((new_to = ft_lstnew(&to_index, sizeof(ssize_t))) == NULL
		|| new_from == new_to || edge_dup(p, new_from, new_to))
		return (parsing_error(p, line, tab));
	ft_lstappend(&p->from, new_from);
	ft_lstappend(&p->to, new_to);
	free_tab(tab);
	return (SUCCESS);
}

static int8_t	node_name(char **tab, t_input *p)
{
	t_list	*new_name;

	if (name_dup(p, tab[0]) == TRUE)
		return (FAILURE);
	if ((new_name = ft_lstnew(tab[0], (ft_strlen(tab[0]) + 1)
					* sizeof(char))) == NULL)
		return (FAILURE);
	ft_lstappend(&p->nodes, new_name);
	return (SUCCESS);
}

int8_t			save_node(t_input *p, char *line)
{
	char	**tab;
	t_list	*new_x_coord;
	t_list	*new_y_coord;
	int		x;
	int		y;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (parsing_error(p, line, tab));
	if (node_name(tab, p) == FAILURE)
		return (parsing_error(p, line, tab));
	if (!tab[1] || check_int(tab[1], FALSE) == FAILURE
		|| !tab[2] || check_int(tab[2], FALSE) == FAILURE)
		return (parsing_error(p, line, tab));
	x = ft_atol(tab[1]);
	y = ft_atol(tab[2]);
	if (coord_dup(p, x, y) == TRUE)
		return (parsing_error(p, line, tab));
	if ((new_x_coord = ft_lstnew(&x, sizeof(int))) == NULL)
		return (parsing_error(p, line, tab));
	if ((new_y_coord = ft_lstnew(&y, sizeof(int))) == NULL)
		return (parsing_error(p, line, tab));
	ft_lstappend(&p->x, new_x_coord);
	ft_lstappend(&p->y, new_y_coord);
	free_tab(tab);
	return (SUCCESS);
}
