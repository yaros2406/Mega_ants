/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:37:33 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/18 19:38:11 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;

	if (!s)
		return (NULL);
	i = 0;
	while (s && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	while (s && j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if (j == 0)
		return (ft_strdup(""));
	return ((char *)ft_strsub((const char *)s, (unsigned int)i,
			(size_t)(j - i + 1)));
}
