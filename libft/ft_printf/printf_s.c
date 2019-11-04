/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_c(char c, t_print *list)
{
	char	*str;
	int		size;
	int		i;

	i = -1;
	size = list->w;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		str[i] = c;
	str[i] = '\0';
	return (str);
}

char			*ft_cv(char c, t_print *list)
{
	char	*str;
	int		size;
	int		i;

	i = -1;
	size = list->v - list->s_len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		str[i] = c;
	str[i] = '\0';
	list->s_len = 0;
	return (str);
}

void			get_str(t_print *list)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(str) * list->v);
	while (++i < list->v)
		str[i] = list->p_str[i];
	str[i] = '\0';
	if (list->s_len > list->v)
		list->s_len = list->v;
	list->p_str = str;
}

int				color(const char *restrict format, t_print *list)
{
	if (!ft_strncmp(&format[1], "{red}", (list->num1 = 5)))
		list->p_str = ft_strjoin(PF_RED, list->p_str);
	else if (!ft_strncmp(&format[1], "{green}", (list->num1 = 7)))
		list->p_str = ft_strjoin(PF_GREEN, list->p_str);
	else if (!ft_strncmp(&format[1], "{yellow}", (list->num1 = 8)))
		list->p_str = ft_strjoin(PF_YELLOW, list->p_str);
	else if (!ft_strncmp(&format[1], "{blue}", (list->num1 = 6)))
		list->p_str = ft_strjoin(PF_BLUE, list->p_str);
	else if (!ft_strncmp(&format[1], "{purple}", (list->num1 = 8)))
		list->p_str = ft_strjoin(PF_PURPLE, list->p_str);
	else if (!ft_strncmp(&format[1], "{cyan}", (list->num1 = 6)))
		list->p_str = ft_strjoin(PF_CYAN, list->p_str);
	list->num1++;
	return (0);
}

t_print			*ft_s(const char *restrict format, t_print *list, va_list ap)
{
	char *str;

	ft_set(format, list);
	if (list->ze)
		ft_width_check(format, list, ap);
	str = va_arg(ap, char *);
	list->p_str = (!str) ? ft_strdup("(null)") : ft_strdup(str);
	ft_pos_neg(list);
	(list->p_str[0] == 0) ? list->v = 0 : 0;
	if ((!list->v && list->dot && list->x != 11) || list->p_str == '\0')
	{
		list->p_str = ft_strdup("");
		list->s_len = 0;
	}
	(list->dot && list->v > list->s_len) ? list->v = 0 : 0;
	(list->v < list->s_len && list->v) ? get_str(list) : 0;
	format[1] == '{' ? color(format, list) : 0;
	ft_printout(list);
	return (ret(list));
}
