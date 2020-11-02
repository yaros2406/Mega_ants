/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:29 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:24 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrevrotate(t_list **alst)
{
	t_list	*first;
	t_list	*current;
	t_list	*before_last;

	first = *alst;
	current = first;
	before_last = NULL;
	while (current->next)
	{
		before_last = current;
		current = current->next;
	}
	current->next = first;
	*alst = current;
	if (before_last && before_last->next)
		before_last->next = NULL;
}
