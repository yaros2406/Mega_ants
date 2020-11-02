/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:21:51 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:22:24 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsorted(t_list *list, int size, int (*cmp)(void *, void *))
{
	if (!list || !list->next || size == 0)
		return (1);
	if (cmp(list->content, list->next->content) > 0)
		return (ft_lstsorted(list->next, size - 1, cmp));
	return (0);
}
