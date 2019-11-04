/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodim_char_malloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:46:38 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/08 15:50:02 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_twodim_char_malloc(size_t size, size_t len)
{
	char		**t;
	size_t		i;

	i = -1;
	if (size < 1 || len < 1)
		return (NULL);
	if (!(t = (char**)ft_memalloc((size + 1) * sizeof(char*))))
		return (NULL);
	while (++i < size)
		if (!(t[i] = (char*)ft_memalloc((len + 1) * sizeof(char))))
			return (NULL);
	return (t);
}
