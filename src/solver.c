/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:33:40 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 19:11:51 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t	reset_availability(t_graph *graph, t_paths *paths, size_t *ants2paths)
{
	size_t	i;

	i = 0;
	while (i < graph->paths_count)
	{
		if (ants2paths[i] > 0)
			paths->available[i] = TRUE;
		else
			paths->available[i] = FALSE;
		i++;
	}
	return (SUCCESS);
}

int8_t	solution_found(t_paths *paths, t_graph *graph)
{
	size_t	i;
	size_t	sum;

	i = 0;
	while (i < graph->paths_count)
	{
		if (paths->output_lines < paths->len[i] - 1)
			paths->n[i] = 0;
		else if (paths->len[i] == 1)
			paths->n[i] = graph->ants;
		else
			paths->n[i] = paths->output_lines - paths->len[i] + 1;
		i++;
	}
	i = 0;
	sum = 0;
	while (i < graph->paths_count)
		sum = sum + paths->n[i++];
	if (sum >= graph->ants)
		return (TRUE);
	return (FALSE);
}

t_paths	*find_solution(t_graph *graph, t_list *aug_paths)
{
	size_t	i;
	t_paths	*paths;

	if ((paths = init_output(graph, aug_paths)) == NULL)
		return (NULL);
	init_lines(paths, graph);
	while (solution_found(paths, graph) == FALSE)
	{
		i = 0;
		while (i < graph->paths_count)
			paths->n[i++] = 0;
		paths->output_lines++;
	}
	if (graph->paths_count
		&& !(paths->available = malloc(sizeof(int8_t) * graph->paths_count)))
		return (NULL);
	return (paths);
}

void	print_options(t_graph *graph, t_paths *paths, t_options *o)
{
	size_t i;

	if (o->graph == TRUE)
		print_graph(graph);
	if (o->paths == TRUE)
	{
		ft_putendl("\n*** Paths ***");
		i = 0;
		while (i < graph->paths_count)
		{
			ft_printf("path %d: ", i);
			print_ssize_t(paths->array[i++], graph);
		}
		ft_putchar('\n');
	}
}

int8_t	solver(t_graph *graph, t_list *aug_paths, t_options *o)
{
	t_paths	*paths;
	size_t	i;
	size_t	tmp[graph->paths_count];

	if ((paths = find_solution(graph, aug_paths)) == NULL)
		return (FAILURE);
	i = 0;
	while (i < graph->paths_count)
	{
		tmp[i] = paths->n[i];
		i++;
	}
	reset_availability(graph, paths, paths->n);
	assign_ants_to_paths(graph, paths, tmp);
	if (o->visual == TRUE)
		visualizer(graph, paths);
	print_lines(paths, graph);
	print_options(graph, paths, o);
	free_paths(paths, graph);
	free_graph(graph);
	return (SUCCESS);
}
