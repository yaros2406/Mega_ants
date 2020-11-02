/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:32:26 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/18 22:49:33 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t	ants_val(char *line)
{
	int	i;

	if (line == NULL)
		return (FAILURE);
	i = 0;
	while (line[i] != '\0')
		if (line[0] == '0' || !ft_isdigit(line[i++]))
			return (FAILURE);
	return (SUCCESS);
}

int8_t	node_val(char *line)
{
	int	i;

	if (line == NULL)
		return (FAILURE);
	i = 0;
	if (line[i] == 'L')
		return (FAILURE);
	while (line[i] != '\0' && line[i] != ' ')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (FAILURE);
		i++;
	}
	if (line[i++] != ' ')
		return (FAILURE);
	while (line[i] != '\0' && line[i] != ' ')
		if (!ft_isdigit(line[i++]))
			return (FAILURE);
	if (line[i++] != ' ')
		return (FAILURE);
	while (line[i] != '\0')
		if (!ft_isdigit(line[i++]))
			return (FAILURE);
	return (SUCCESS);
}

int8_t	edge_val(char *line)
{
	int	i;

	if (line == NULL)
		return (FAILURE);
	i = 0;
	while (line[i] != '\0' && line[i] != '-')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (FAILURE);
		i++;
	}
	if (line[i++] != '-')
		return (FAILURE);
	while (line[i] != '\0')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int8_t	comment_val(char *line)
{
	if (line == NULL)
		return (FAILURE);
	if (line[0] == '#' && (line[1] != '#'
				|| !ft_strequ(line, "##start")
				|| !ft_strequ(line, "##end")))
		return (SUCCESS);
	else
		return (FAILURE);
}

int8_t	command_val(char *line)
{
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (SUCCESS);
	else
		return (FAILURE);
}
