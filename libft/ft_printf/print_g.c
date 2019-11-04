/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*del_zero(char *str, int len)
{
	while (len--)
	{
		if (str[len] != '0')
			break ;
		if (str[len] == '0')
			str[len] = '\0';
	}
	return (str);
}

char				*refactor_six(char *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	if (str[0] == '0')
		count--;
	while (str[++i])
	{
		ft_isdigit(str[i]) ? count++ : 0;
		if (count == 6)
			break ;
	}
	str[++i] = '\0';
	return (str);
}

char				*ft_size_f(t_print *list, long double numb)
{
	list->p_str = ft_itoa_float(numb, list);
	list->v == 6 ? list->v = 0 : 0;
	ft_pos_neg(list);
	list->x = 1;
	(list->minus) ? list->zero = 0 : 0;
	ft_check_nan(list, numb);
	if (list->v == 0 && list->w == 0 && numb < 10)
		list->p_str = refactor_six(list->p_str);
	if (list->v == 0 && list->w == 0
			&& list->p_str[ft_strlen(list->p_str) - 1] == '0')
		list->p_str = del_zero(list->p_str, ft_strlen(list->p_str));
	return (list->p_str);
}

char				*ft_size_e(t_print *list, long double numb)
{
	int r;

	r = 0;
	list->p_str = ft_itoa_float(numb, list);
	ft_pos_neg(list);
	list->x = 1;
	(list->minus) ? list->zero = 0 : 0;
	ft_check_nan(list, numb);
	ft_reafctor_e(list, r);
	return (list->p_str);
}

t_print				*ft_g(const char *restrict format, \
							t_print *list, va_list ap)
{
	char			*one;
	char			*two;
	long double		numb;

	ft_set(format, list);
	numb = ft_set_f(list, ap);
	one = ft_size_f(list, numb);
	two = ft_size_e(list, numb);
	if (ft_strlen(one) > ft_strlen(two))
		ft_putstr(list->p_str = two);
	else
		ft_putstr(list->p_str = one);
	list->s_len = ft_strlen(list->p_str);
	list->field = list->num1 - list->num0 + 1;
	list->size = list->size + list->s_len - 1;
	list->i = list->field + list->i - 1;
	ft_set_free(list);
	return (list);
}
