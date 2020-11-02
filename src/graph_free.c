/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:31:39 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 19:28:33 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths	*free_paths(t_paths *paths, t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i < graph->paths_count)
	{
		ft_lstdel(&paths->array[i], ft_delcontent);
		i++;
	}
	paths->array ? free(paths->array) : 0;
	paths->n ? free(paths->n) : 0;
	paths->len ? free(paths->len) : 0;
	paths->available ? free(paths->available) : 0;
	paths->ants_to_paths ? free(paths->ants_to_paths) : 0;
	free(paths);
	return (NULL);
}

int		search_error(t_input *p, t_graph *graph)
{
	free_p(p);
	free_graph(graph);
	ft_putendl_fd("ERROR", 2);
	return (EXIT_SUCCESS);
}

void	edge_del(t_edge **edge)
{
	if (*edge)
	{
		edge_del(&(*edge)->next);
		if (edge)
		{
			free(*edge);
			*edge = NULL;
		}
	}
}

void	free_graph(t_graph *graph)
{
	size_t	i;

	if (graph == NULL)
		return ;
	i = 0;
	while (i < graph->size)
	{
		ft_strdel(&graph->nodes[i].name);
		edge_del(&graph->nodes[i].head);
		i++;
	}
	free(graph->nodes);
	free(graph);
	graph = NULL;
}

t_bfs	*free_bfs(t_bfs *bfs)
{
	free(bfs->prev);
	free(bfs->queue);
	free(bfs);
	return (NULL);
}
