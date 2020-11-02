/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:47 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:24 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstgetmin(t_list *list, int size)
{
	int min;

	min = *(int *)list->content;
	while (list && size--)
	{
		if (*(int *)list->content < min)
			min = *(int *)list->content;
		list = list->next;
	}
	return (min);
}
