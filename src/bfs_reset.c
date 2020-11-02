/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:30:31 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 19:34:50 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			reset_marks_fail(t_graph *graph, t_bfs *bfs)
{
	size_t	i;
	ssize_t	j;

	i = 0;
	while (i < graph->size)
	{
		j = 0;
		while (bfs->queue[j] != -1)
		{
			if (i == (size_t)bfs->queue[j])
				graph->nodes[i].visited = FALSE;
			j++;
		}
		graph->nodes[i].enqueued = FALSE;
		graph->nodes[i].enqueued_backward = FALSE;
		i++;
	}
}

static int8_t	find_neighbour(t_graph *graph, size_t i, int8_t found)
{
	t_edge	*neighbours;

	neighbours = graph->nodes[i].head;
	while (neighbours)
	{
		if (neighbours->capacity == 2)
			return (TRUE);
		neighbours = neighbours->next;
	}
	return (found);
}

int8_t			sink_link_source(t_graph *graph)
{
	t_edge *curr;

	curr = graph->nodes[graph->source].head;
	while (curr != NULL)
	{
		if (curr->dest == graph->sink)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

void			reset_marks(t_graph *graph, t_bfs *bfs)
{
	size_t	i;
	int8_t	found;
	t_list	*curr;

	i = 0;
	while (i < graph->size)
	{
		found = FALSE;
		curr = bfs->shortest_path;
		while (curr != NULL)
		{
			if (i == *(size_t *)curr->content)
				found = TRUE;
			curr = curr->next;
		}
		found = find_neighbour(graph, i, found);
		if (found == FALSE || ((graph->nodes[i].sink == TRUE
			|| graph->nodes[i].source == TRUE)
			&& sink_link_source(graph) == FALSE))
			graph->nodes[i].visited = FALSE;
		graph->nodes[i].enqueued = FALSE;
		graph->nodes[i].enqueued_backward = FALSE;
		i++;
	}
}
