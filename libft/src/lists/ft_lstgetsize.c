/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:54 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:24 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstgetsize(t_list *list)
{
	t_list *curr;
	size_t size;

	size = 0;
	curr = list;
	while (curr)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}
