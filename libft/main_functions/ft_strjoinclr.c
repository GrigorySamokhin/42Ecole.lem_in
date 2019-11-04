/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinclr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:57:17 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/12 15:05:08 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinclr(char *s1, char *s2, int b)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, s1);
	if (b == 0 || b == 1)
		free(s1);
	ft_strcat(str, s2);
	if (b == 0 || b == 2)
		free(s2);
	s1 = str;
	return (s1);
}

char			*ft_strnjoinclr(char *s1, char *s2, int len, int b)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	ft_strcpy(str, s1);
	if (b == 0 || b == 1)
		free(s1);
	ft_strncat(str, s2, len);
	if (b == 0 || b == 2)
		free(s2);
	s1 = str;
	return (s1);
}
