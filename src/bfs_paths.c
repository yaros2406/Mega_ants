/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:31:02 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 19:59:24 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	on_path(size_t node, t_list *path, t_graph *graph)
{
	t_list	*curr;

	curr = path;
	while (curr != NULL && *(size_t *)curr->content != graph->sink)
	{
		if (*(size_t *)curr->content == node
				&& node != graph->source && node != graph->sink)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

size_t	path_pos(t_list **path, t_list *aug_paths, t_graph *graph)
{
	size_t	path_pos;
	t_list	*curr;

	path_pos = 0;
	curr = aug_paths;
	while (curr != *path)
	{
		if (*(size_t *)curr->content == graph->source)
			path_pos++;
		curr = curr->next;
	}
	return (path_pos);
}

t_list	*next_path(t_list *path, t_graph *graph)
{
	t_list	*next_path;

	next_path = path;
	while (next_path->next != NULL &&
			*(size_t *)next_path->next->content != graph->source)
		next_path = next_path->next;
	next_path = next_path->next;
	return (next_path);
}

void	change_cap(t_graph *graph, t_list *u, t_list *v, int8_t order)
{
	t_edge	*neighbours;

	neighbours = graph->nodes[*(size_t *)u->content].head;
	while (neighbours->dest != *(size_t *)v->content)
		neighbours = neighbours->next;
	if (neighbours->dest == *(size_t *)v->content)
	{
		if (order == INCREASE)
			neighbours->capacity++;
		if (order == DECREASE)
			neighbours->capacity--;
	}
}

void	update_capacities(t_bfs *new_bfs, t_graph *graph, int8_t order)
{
	t_list	*curr;

	curr = new_bfs->shortest_path;
	while (curr->next != NULL)
	{
		if (order == INCREASE)
		{
			change_cap(graph, curr, curr->next, DECREASE);
			change_cap(graph, curr->next, curr, INCREASE);
		}
		else
		{
			change_cap(graph, curr, curr->next, INCREASE);
			change_cap(graph, curr->next, curr, DECREASE);
		}
		curr = curr->next;
	}
	graph->paths_count += order;
}
