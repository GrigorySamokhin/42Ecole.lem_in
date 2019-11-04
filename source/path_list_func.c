/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_path_end(t_paths **lst, t_paths *new)
{
	t_paths		*tmp;

	tmp = *lst;
	if (tmp == NULL)
		*lst = new;
	else
	{
		while (tmp->next_paths)
		{
			if (tmp->next_paths)
				tmp = tmp->next_paths;
		}
		tmp->next_paths = new;
	}
}

void			ft_clear_way_pos(t_way *way, int len)
{
	t_way		*temp;
	int			i;

	temp = way;
	i = 0;
	while (temp)
	{
		temp->node->path = 0;
		if (i + 2 == len)
			temp->node->path = 1;
		temp = temp->next_way;
		i++;
	}
}

t_paths			*ft_get_path(t_way *new, t_info *info)
{
	t_paths		*path;
	int			len;

	len = ft_len_way(new);
	if (len > info->max_pos + info->max_pos)
	{
		ft_clear_way_pos(new, len);
		new = NULL;
	}
	if (new == NULL)
		return (NULL);
	path = (t_paths *)malloc(sizeof(t_paths));
	path->link = new;
	path->next_paths = NULL;
	return (path);
}

t_way			*ft_get_way_one(t_adjlst *new)
{
	t_way		*link;

	link = (t_way *)malloc(sizeof(t_way));
	link->node = new;
	link->next_way = NULL;
	return (link);
}

t_way			*ft_way_end(t_way **link, t_way *new)
{
	t_way		*temp;

	temp = *link;
	if (new == NULL)
	{
		ft_del_lst_ways(link);
		return (NULL);
	}
	if (*link == NULL)
		new = *link;
	else
		new->next_way = temp;
	return (new);
}
