/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:25:44 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:28:39 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;

	if (!(s = ft_strnew(ft_intlen(n))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		if (n == -2147483648)
		{
			s[i++] = '2';
			n = -147483648;
		}
		n = -n;
	}
	if (n == 0)
		s[i++] = '0';
	while (n > 0)
	{
		s[(ft_intlen(n)) + i - 1] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
