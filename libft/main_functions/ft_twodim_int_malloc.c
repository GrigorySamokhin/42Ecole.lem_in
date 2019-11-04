/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodim_int_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:46:38 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/08 15:50:02 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_int2alloc(size_t size, size_t len)
{
	int			**t;
	size_t		i;

	i = -1;
	if (size < 1 || len < 1)
		return (NULL);
	if (!(t = (int**)ft_memalloc((size + 1) * sizeof(int*))))
		return (NULL);
	while (++i < size)
		if (!(t[i] = (int*)ft_memalloc(len * sizeof(int))))
			return (NULL);
	return (t);
}
