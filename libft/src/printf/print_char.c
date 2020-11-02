/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:20:59 by bshaquan          #+#    #+#             */
/*   Updated: 2020/02/18 19:22:56 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_char(t_sp *sp)
{
	char c;

	c = va_arg(sp->ap, int);
	if (!sp->left_align && sp->zero)
		sp->zeros = sp->min_width - 1;
	if (sp->left_align)
		sp->right_spaces = sp->min_width - sp->zeros - 1;
	else
		sp->left_spaces = sp->min_width - sp->zeros - 1;
	ft_print_left_spaces(sp);
	ft_print_zeros(sp);
	ft_buffer(sp, &c, 1);
	ft_print_right_spaces(sp);
}
