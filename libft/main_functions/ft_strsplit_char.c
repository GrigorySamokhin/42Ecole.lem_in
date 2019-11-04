/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:59:10 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/11 19:17:32 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsplit_char(char *line, char ch)
{
	char	*str;
	int		i;
	int		size_str;

	i = -1;
	size_str = 0;
	while (line[++i])
	{
		size_str++;
		if (line[i] == ch)
			break ;
	}
	str = (char *)malloc(sizeof(char) * (size_str + 1));
	i = -1;
	while (line[++i])
	{
		if (line[i] == ch)
			break ;
		str[i] = line[i];
	}
	str[i] = '\0';
	return (str);
}
