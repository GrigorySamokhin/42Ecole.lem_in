/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				**ft_split_by_i(char *str, int numb, char c, int i)
{
	char		**str_two;
	int			k;

	k = 0;
	str_two = (char **)malloc(sizeof(char *) * 2);
	str_two[0] = (char *)malloc(sizeof(char) * ft_strlen(str));
	str_two[1] = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[++i])
	{
		(str[i] == c) ? i++ : 0;
		str_two[0][i] = str[i];
		if (i == numb - 1)
		{
			str_two[0][++i] = '\0';
			while (str[i])
			{
				(str[i] == c) ? ++i : 0;
				str_two[1][k++] = str[i++];
			}
			str_two[1][k] = '\0';
			break ;
		}
	}
	return (str_two);
}

int					ft_find_c(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			break ;
	return (i);
}

char				*ft_refactor_help(int rage, int len_dot,
						int ret, char **temp)
{
	if (rage)
	{
		temp[0][0] = temp[1][0];
		temp[0] = ft_strjoin(temp[0], &temp[1][1]);
	}
	else
		temp[0] = ft_strjoin(temp[0], temp[1]);
	temp[0] = ret == 1 ? ft_strjoin(temp[0], ft_strdup("e"))
		: ft_strjoin(temp[0], ft_strdup("E"));
	temp[0] = (rage) ? ft_strjoin(temp[0], ft_strdup("-"))
			: ft_strjoin(temp[0], ft_strdup("+"));
	if (len_dot < 10)
	{
		temp[0] = ft_strjoin(temp[0], ft_strdup("0"));
		temp[0] = !rage ? ft_strjoin(temp[0], ft_strdup(ft_itoa(len_dot)))
						: ft_strjoin(temp[0], ft_strdup("1"));
	}
	return (temp[0]);
}

void				ft_reafctor_e(t_print *list, int ret)
{
	int		len_dot;
	int		rage;
	char	**temp;

	if (!ft_strcmp(list->p_str, "nan"))
	{
		ft_putstr("0.000000e+00");
		exit(1);
	}
	len_dot = ft_find_c(list->p_str, '.');
	len_dot--;
	temp = ft_split_by_i(list->p_str, 1, '.', -1);
	if (temp[0][0] != '0')
		temp[1][6] = '\0';
	else
		temp[1][7] = '\0';
	rage = temp[0][0] == '0' ? 1 : 0;
	temp[0] = ft_strjoin(temp[0], ft_strdup("."));
	list->p_str = ft_refactor_help(rage, len_dot, ret, temp);
}

t_print				*ft_e(const char *restrict format, \
							t_print *list, va_list ap, int r)
{
	long double		numb;

	ft_set(format, list);
	numb = ft_set_f(list, ap);
	if (numb < 1)
		list->v = 7;
	list->p_str = ft_itoa_float(numb, list);
	ft_pos_neg(list);
	list->x = 1;
	(list->minus) ? list->zero = 0 : 0;
	ft_check_nan(list, numb);
	ft_reafctor_e(list, r);
	ft_printout(list);
	list->s_len = ft_strlen(list->p_str);
	list->field = list->num1 - list->num0 + 1;
	list->size = list->size + list->s_len - 1;
	list->i = list->field + list->i - 1;
	ft_set_free(list);
	return (list);
}
