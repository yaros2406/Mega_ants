/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:32:56 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 20:14:02 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int8_t	get_commands(char *line, t_input *p)
{
	if (p->prev_cmd == TRUE
			|| (ft_strequ("##start", line) && p->source != -1)
			|| (ft_strequ("##end", line) && p->sink != -1))
		return (parsing_error(p, line, NULL));
	p->prev_cmd = TRUE;
	if (ft_strequ("##start", line))
		p->source = p->index;
	if (ft_strequ("##end", line))
		p->sink = p->index;
	return (SUCCESS);
}

static int8_t	process_node(char *line, t_input *p)
{
	if (p->ants == 0 || p->from != NULL || p->to != NULL)
		return (parsing_error(p, line, NULL));
	if (p->prev_cmd == TRUE)
		p->prev_cmd = FALSE;
	p->index++;
	return (save_node(p, line));
}

static int8_t	process_edge(char *line, t_input *p)
{
	if (p->prev_cmd == TRUE || p->nodes == NULL
			|| p->source == -1 || p->sink == -1 || p->ants == 0)
		return (parsing_error(p, line, NULL));
	return (save_edge(p, line));
}

static int8_t	process_line(char *line, t_input *p)
{
	if (line == NULL)
		return (parsing_error(p, line, NULL));
	if (ants_val(line) == SUCCESS)
	{
		if (p->ants != 0 || check_int(line, TRUE) == FAILURE)
			return (parsing_error(p, line, NULL));
		p->ants = ft_atoi(line);
		return (SUCCESS);
	}
	if (command_val(line) == SUCCESS)
		return (get_commands(line, p));
	if (comment_val(line) == SUCCESS
			&& p->prev_cmd == TRUE)
		return (parsing_error(p, line, NULL));
	if (comment_val(line) == SUCCESS
			&& p->prev_cmd == FALSE)
		return (SUCCESS);
	if (node_val(line) == SUCCESS)
		return (process_node(line, p));
	if (edge_val(line) == SUCCESS)
		return (process_edge(line, p));
	return (parsing_error(p, line, NULL));
}

int8_t			parse_file(t_input *p)
{
	int			ret_gnl;
	int			ret_process;
	char		*line;
	t_list		*new_line;

	line = NULL;
	new_line = NULL;
	while ((ret_gnl = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		ret_process = process_line(line, p);
		if (ret_process == FAILURE)
			return (FAILURE);
		else if (ret_process == STOP)
			return (SUCCESS);
		if (!(new_line = ft_lstnew(line, ft_strlen(line) * sizeof(char) + 1)))
			return (parsing_error(p, line, NULL));
		ft_lstappend(&p->file, new_line);
		ft_strdel(&line);
	}
	if (ret_gnl == FAILURE || p->ants <= 0 || p->source < 0 || p->sink < 0
		|| !p->nodes || !p->from || !p->to)
		return (parsing_error(p, line, NULL));
	ft_strdel(&line);
	get_next_line(CLEANUP, NULL);
	return (SUCCESS);
}
