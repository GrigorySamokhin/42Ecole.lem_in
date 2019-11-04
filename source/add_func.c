/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_n_cord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			i_free(t_info *info)
{
	free(info);
	return (1);
}

void		ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void		ft_free2(void **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char		**get_words(char **tab)
{
	char	**out;
	int		i;

	i = -1;
	while (tab[++i])
		;
	if (!(out = (char**)ft_memalloc((i + 1) * sizeof(char*))))
		return (NULL);
	i = -1;
	while (tab[++i])
		out[i] = ft_strdup(tab[i]);
	return (out);
}

void		ft_char_two_dem(char **array)
{
	int		i;

	i = -1;
	if (!array || !*array)
		return ;
	while (array[++i])
	{
		ft_putstr(array[i]);
		ft_putstr(" ");
	}
	ft_putstr("\n");
}
