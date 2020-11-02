/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:37:21 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/18 19:38:11 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (!(result = ft_strnew(len)))
		return (NULL);
	result = ft_strncpy(result, (s + start), len);
	return (result);
}
