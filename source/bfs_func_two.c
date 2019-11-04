/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adjlst		*ft_path_adder_way(t_adjlst *list,
										t_adjlst *to_go, t_info *info)
{
	t_links			*temp_link;
	int				pos_link;
	int				i;

	i = 0;
	temp_link = list->links;
	pos_link = to_go->pos + 2;
	while (i++ < list->link)
	{
		if (temp_link->link->pos == pos_link && !temp_link->link->path)
			if (ft_choose_way(temp_link->link, info)
					<= ft_choose_way(to_go, info))
				to_go = temp_link->link;
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	if (to_go->path)
		return (NULL);
	else
		to_go != info->start ? to_go->path = 1 : 0;
	return (to_go);
}

t_way			*ft_path_second_way(t_adjlst *list, t_info *info)
{
	t_links		*temp_link;
	t_adjlst	*to_go;
	int			i;

	i = 0;
	temp_link = list->links;
	to_go = list->links->link;
	if (list->link == 1)
		return (NULL);
	if (to_go->path && list->link > 1 && list != info->end)
		to_go = list->links->next_links->link;
	while (i++ < list->link)
	{
		if (to_go->pos >= temp_link->link->pos && !temp_link->link->path
			&& temp_link->link != info->end && temp_link->link->link > 1)
			to_go = temp_link->link;
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	if (list->links->next_links->link->path == 1)
		return (NULL);
	if (!ft_valid_way(to_go, info))
		if (!(to_go = ft_path_adder_way(list, to_go, info)))
			return (NULL);
	return (ft_get_way_one(to_go));
}

int				ft_valid_way(t_adjlst *node, t_info *info)
{
	t_way		*path_one;

	path_one = ft_get_way_one(node);
	while (path_one->node != info->start)
	{
		path_one = ft_way_end(&path_one, ft_path_test(path_one->node, info));
		if (path_one == NULL)
			return (0);
	}
	ft_del_lst_ways(&path_one);
	return (1);
}

t_way			*ft_path_adder1(t_adjlst *list, t_links *link_reserve)
{
	int i;

	i = 0;
	while (i++ < list->link)
	{
		if (link_reserve->link->pos <= list->pos
			&& !link_reserve->link->path)
			return (ft_get_way_one(link_reserve->link));
		if (link_reserve->next_links)
			link_reserve = link_reserve->next_links;
	}
	return (NULL);
}

t_way			*ft_path_test(t_adjlst *list, t_info *info)
{
	t_links			*link_reserve;
	t_links			*temp_link;
	int				i;

	i = 0;
	temp_link = list->links;
	link_reserve = list->links;
	if (list->link == 1)
		return (NULL);
	while (i++ < list->link)
	{
		if (temp_link->link->pos == list->pos - 1 && !temp_link->link->path)
			return (ft_get_way_one(temp_link->link));
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	if (list == info->end)
		return (ft_path_adder1(list, link_reserve));
	return (NULL);
}
