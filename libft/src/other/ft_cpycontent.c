/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpycontent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:23:53 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/16 23:28:39 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cpycontent(void *dst, void *src)
{
	*(int *)dst = *(int *)src;
	return (0);
}