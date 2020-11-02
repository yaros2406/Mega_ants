/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:18:50 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:24 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*holder;

	if (!new)
		return ;
	holder = (*alst == NULL) ? NULL : *alst;
	if (holder)
	{
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
		return ;
	}
	*alst = new;
}
