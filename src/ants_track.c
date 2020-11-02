/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:33:18 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 20:21:51 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	paths_occupied(t_graph *graph, t_paths *paths)
{
	size_t	i;
	size_t	paths_occupied;

	i = 0;
	paths_occupied = graph->paths_count;
	while (i < graph->paths_count)
	{
		if (paths->available[i] == TRUE)
			paths_occupied--;
		i++;
	}
	return (paths_occupied);
}

static int8_t	all_launched(t_graph *graph, t_paths *paths)
{
	size_t	i;

	i = 0;
	while (i < graph->paths_count)
	{
		if (paths->n[i] > 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int8_t			all_moved(t_list **pos, ssize_t *tmp,
							t_graph *graph, t_paths *paths)
{
	size_t	i;
	size_t	occupied;

	occupied = paths_occupied(graph, paths);
	if (occupied < graph->paths_count
		&& all_launched(graph, paths) == FALSE)
	{
		ft_putchar(' ');
		return (TRUE);
	}
	i = 0;
	while (i < graph->ants)
	{
		if (pos[i] != NULL && *(ssize_t *)pos[i]->content == tmp[i]
			&& pos[i] != paths->array[paths->ants_to_paths[i]])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
