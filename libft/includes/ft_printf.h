/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:53:33 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:53:35 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"

typedef struct			s_printf_list
{
	char				*p_str;
	char				*f_str;
	int					s_len;
	int					field;
	int					minus;
	int					space;
	intmax_t			numb;
	int					flag;
	int					grid;
	int					zero;
	int					color;
	int					pos;
	int					neg;
	int					dot;
	int					w;
	int					v;
	int					x;
	int					i;
	int					num0;
	int					num1;
	int					size;
	char				sign;
	char				*add;
	int					p;
	int					ze;
}						t_print;

t_print					*ft_base(const char *restrict format, \
								t_print *list, va_list ap);
t_print					*ft_bin(const char *restrict format, \
								t_print *list, va_list ap);
intmax_t				ft_set_number(va_list ap, t_print *list);
void					ft_reafctor_e(t_print *list, int ret);
t_print					*ft_g(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_e(const char *restrict format, \
							t_print *list, va_list ap, int r);
long double				ft_set_f(t_print *list, va_list ap);
void					ft_zero_nspace(t_print *list);
void					ft_check_nan(t_print *list, double numb);
void					ft_helper_itoa(t_print *list, char **dem_flo, int *arr);
int						re(t_print *list, int size);
void					ft_set_free(t_print *list);
void					ft_str_flags(t_print *list, \
							const char *restrict format);
void					ft_width_check(const char *format, \
							t_print *list, va_list ap);
void					ft_vi_check(const char *format, \
							t_print *list, va_list ap);
void					ft_dot_vi_w(t_print *list);
void					ft_set(const char *restrict format, t_print *list);
t_print					*ft_b(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_x(const char *restrict format, \
							t_print *list, va_list ap, int pos);
t_print					*ft_ch(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_per(const char *restrict format, \
							t_print *list);
t_print					*ft_s(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ret(t_print *list);
t_print					*ft_di(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_disp(const char *restrict format, \
							t_print *list, va_list ap);
void					ft_set_zero(t_print *list);
void					get_str(t_print *list);
intmax_t				ft_set_number_x(va_list ap, t_print *list);
t_print					*ft_o(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_u(const char *restrict format, \
								t_print *list, va_list ap, int r);
int						ft_printf(const char *restrict format, ...);
void					ft_pvalue(t_print *list);
void					ft_pos_neg(t_print	*list);
void					ft_printout(t_print *list);
void					ft_pvalue(t_print *list);
int						ft_isspec(char c);
char					*ft_c(char c, t_print *list);
char					*ft_cv(char c, t_print *list);
int						ft_itoa_float_set(long double *nbr, char **dem_flo, \
							int *dot_index, t_print *list);
int						ft_zero_set(char **dem_flo, int i, int *y);
char					*ft_itoa_float(long double nbr, t_print *list);
t_print					*ft_f(const char *restrict format, t_print *list, \
							va_list ap);

#endif
