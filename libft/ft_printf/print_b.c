/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print				*ft_bin(const char *restrict format, \
								t_print *list, va_list ap)
{
	ft_set(format, list);
	if (list->ze)
		ft_width_check(format, list, ap);
	list->p_str = ft_itoa_intmax_base(ft_set_number(ap, list), 2);
	ft_pos_neg(list);
	if (list->p_str[0] == '0' && !list->v && list->dot)
	{
		ft_strdel(&list->p_str);
		list->p_str = ft_strdup("");
	}
	(list->v > list->w) ? list->w = list->v : 0;
	ft_printout(list);
	return (ret(list));
}

t_print				*ft_base(const char *restrict format, \
								t_print *list, va_list ap)
{
	int bas;

	ft_set(format, list);
	bas = list->w;
	list->w = 0;
	if (list->ze)
		ft_width_check(format, list, ap);
	list->p_str = ft_itoa_intmax_base(ft_set_number(ap, list), bas);
	ft_pos_neg(list);
	if (list->p_str[0] == '0' && !list->v && list->dot)
	{
		ft_strdel(&list->p_str);
		list->p_str = ft_strdup("");
	}
	(list->v > list->w) ? list->w = list->v : 0;
	ft_printout(list);
	return (ret(list));
}
