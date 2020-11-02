/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:26:47 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:28:39 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ps;

	ps = (unsigned char*)s;
	while (ps && n-- > 0)
	{
		if (*ps == (unsigned char)c)
			return ((void*)ps);
		ps++;
	}
	return (NULL);
}
