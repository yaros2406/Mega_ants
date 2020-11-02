/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhic <lkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:31:32 by lkuhic            #+#    #+#             */
/*   Updated: 2020/02/19 20:11:34 by lkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_p(t_input *p)
{
	ft_lstdel(&p->nodes, ft_delcontent);
	ft_lstdel(&p->x, ft_delcontent);
	ft_lstdel(&p->y, ft_delcontent);
	ft_lstdel(&p->from, ft_delcontent);
	ft_lstdel(&p->to, ft_delcontent);
	ft_lstdel(&p->file, ft_delcontent);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int8_t	parsing_error(t_input *p, char *line, char **tab)
{
	free_tab(tab);
	ft_strdel(&line);
	get_next_line(CLEANUP, NULL);
	if (p->ants > 0 && p->source > -1 && p->sink > -1
		&& p->nodes != NULL && p->from != NULL && p->to != NULL)
		return (STOP);
	free_p(p);
	ft_putendl_fd("ERROR", 2);
	return (FAILURE);
}
