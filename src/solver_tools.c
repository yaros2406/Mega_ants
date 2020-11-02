/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:33:33 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/18 21:36:48 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		update_n(t_graph *graph, t_paths *paths, size_t tmp[])
{
	size_t	i;

	i = 0;
	while (i < graph->paths_count)
	{
		paths->n[i] = paths->n[i] - tmp[i];
		i++;
	}
	reset_availability(graph, paths, paths->n);
}

static size_t	update_index(t_graph *graph, t_paths *paths, size_t tmp[],
								size_t j)
{
	if (j == graph->paths_count - 1 && paths->available[j] == FALSE)
	{
		reset_availability(graph, paths, tmp);
		j = 0;
	}
	else
		j++;
	return (j);
}

static void		all_paths_used(t_graph *graph, t_paths *paths, size_t tmp[])
{
	size_t	i;

	i = 0;
	while (i < graph->paths_count)
	{
		if (paths->n[i] > 0 && paths->available[i] == TRUE)
			return ;
		i++;
	}
	reset_availability(graph, paths, tmp);
}

void			assign_ants_to_paths(t_graph *graph, t_paths *paths,
								size_t tmp[])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < graph->ants)
	{
		all_paths_used(graph, paths, tmp);
		j = 0;
		while (j < graph->paths_count)
		{
			if (tmp[j] == 0)
				paths->available[j] = FALSE;
			if (paths->available[j] == TRUE && tmp[j] > 0)
			{
				paths->ants_to_paths[i] = j;
				tmp[j]--;
				paths->available[j] = FALSE;
				break ;
			}
			j = update_index(graph, paths, tmp, j);
		}
		i++;
	}
	update_n(graph, paths, tmp);
}
