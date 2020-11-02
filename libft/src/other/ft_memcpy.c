/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:27:14 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:28:39 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	while (n-- > 0)
		*dst_cp++ = *src_cp++;
	return (dst);
}
