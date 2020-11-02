/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:26:34 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:28:39 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_memcpy(dst, src, p - src + 1) + (p - src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}
