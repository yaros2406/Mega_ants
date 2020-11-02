/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:30:40 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 20:21:53 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t			queue_add(size_t node, size_t neigh, t_graph *graph, t_bfs *bfs)
{
	if (bfs->queue_size == bfs->queue_capacity)
		return (FAILURE);
	bfs->queue_rear = bfs->queue_rear + 1;
	bfs->queue[bfs->queue_rear] = neigh;
	bfs->queue_size = bfs->queue_size + 1;
	bfs->prev[neigh] = node;
	graph->nodes[neigh].visited = TRUE;
	graph->nodes[neigh].enqueued = TRUE;
	return (SUCCESS);
}

size_t			queue_rm(t_bfs *bfs)
{
	size_t	index;

	if (bfs->queue_size == 0)
		return (FAILURE);
	index = bfs->queue[bfs->queue_front];
	bfs->queue_front = bfs->queue_front + 1;
	bfs->queue_size = bfs->queue_size - 1;
	return (index);
}

static t_bfs	*init_bfs2(t_bfs *bfs, t_graph *graph)
{
	bfs->queue_front = 0;
	bfs->queue_size = 0;
	bfs->queue_rear = 0;
	bfs->queue_capacity = graph->size * 2;
	bfs->node = 0;
	bfs->shortest_path = NULL;
	if (!(bfs->queue = malloc(bfs->queue_capacity * sizeof(ssize_t))))
		return (NULL);
	if (!(bfs->prev = malloc(graph->size * sizeof(ssize_t))))
		return (NULL);
	return (bfs);
}

t_bfs			*init_bfs(t_graph *graph)
{
	size_t	i;
	t_bfs	*bfs;

	if ((bfs = (t_bfs *)malloc(sizeof(t_bfs))) == NULL)
		return (NULL);
	if (init_bfs2(bfs, graph) == NULL)
		return (free_bfs(bfs));
	i = 0;
	while (i < graph->size)
	{
		bfs->prev[i] = -1;
		bfs->queue[i] = -1;
		if (graph->nodes[i].source == TRUE)
		{
			bfs->queue[0] = i;
			bfs->queue_size = 1;
			graph->nodes[i].visited = TRUE;
			graph->nodes[i].enqueued = TRUE;
			graph->nodes[i].enqueued_backward = TRUE;
		}
		i++;
	}
	return (bfs);
}
