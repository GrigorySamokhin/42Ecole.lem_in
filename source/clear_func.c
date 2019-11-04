/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_del_lst_links(t_links **del)
{
	t_links		**tmp;

	tmp = del;
	while ((*tmp)->next_links)
		ft_del_lst_links(&(*tmp)->next_links);
	if (del)
	{
		free(*del);
		*del = NULL;
	}
}

void			ft_del_lst_adjlst(t_adjlst **del)
{
	t_adjlst	**tmp;

	tmp = del;
	if (*del != NULL)
	{
		while ((*tmp)->next_adj)
			ft_del_lst_adjlst(&(*tmp)->next_adj);
		ft_del_lst_links(&(*tmp)->links);
		if (del)
		{
			ft_strdel(&(*del)->name);
			free(*del);
			*del = NULL;
		}
	}
}

void			ft_del_lst_ways(t_way **del)
{
	t_way		**tmp;

	tmp = del;
	if (*del != NULL)
	{
		while ((*tmp)->next_way)
			ft_del_lst_ways(&(*tmp)->next_way);
		if (del)
		{
			free(*del);
			*del = NULL;
		}
	}
}

void			ft_del_lst_path(t_paths **del)
{
	t_paths	**tmp;

	tmp = del;
	if (*del != NULL)
	{
		while ((*tmp)->next_paths)
			ft_del_lst_path(&(*tmp)->next_paths);
		ft_del_lst_ways(&(*tmp)->link);
		free((*tmp)->link);
		if (del)
		{
			free(*del);
			*del = NULL;
		}
	}
}

void			ft_clean_pos(char **pos_1, char **pos_2, char **pos_3)
{
	*pos_1 != NULL ? free(*pos_1) : 0;
	*pos_2 != NULL ? free(*pos_2) : 0;
	*pos_3 != NULL ? free(*pos_3) : 0;
}
