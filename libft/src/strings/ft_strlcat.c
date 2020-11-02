/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:31:25 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/18 19:38:11 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*odst;
	const char	*osrc;
	size_t		bytes_left;
	size_t		dlen;

	odst = dst;
	osrc = src;
	bytes_left = size;
	while (bytes_left-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	bytes_left = size - dlen;
	if (bytes_left-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (bytes_left != 0)
		{
			*dst++ = *src;
			bytes_left--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
