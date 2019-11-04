/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_shortcut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way			*ft_path_addition(t_adjlst *list, t_info *info)
{
	t_links		*link_temp;
	int			i;

	i = 0;
	link_temp = list->links;
	if (list == info->end)
	{
		while (i++ < list->link)
		{
			if (link_temp->link->pos <= list->pos && !link_temp->link->path)
			{
				link_temp->link != info->start ? link_temp->link->path = 1 : 0;
				return (ft_get_way_one(link_temp->link));
			}
			link_temp->next_links ? link_temp = link_temp->next_links : 0;
		}
	}
	return (NULL);
}

t_way			*ft_path(t_adjlst *list, t_info *info)
{
	t_links		*temp_link;
	int			i;

	i = 0;
	temp_link = list->links;
	while (i++ < list->link)
	{
		if (temp_link->link->pos == list->pos - 1 && !temp_link->link->path)
		{
			temp_link->link != info->start ? temp_link->link->path = 1 : 0;
			return (ft_get_way_one(temp_link->link));
		}
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	return (ft_path_addition(list, info));
}

t_way			*ft_path_shortcut(t_adjlst *list, t_info *info)
{
	t_links		*temp_link;
	int			i;

	i = 0;
	temp_link = list->links;
	while (i++ < list->link)
	{
		if (temp_link->link->shortcut && !temp_link->link->path)
		{
			temp_link->link != info->start ? temp_link->link->path = 1 : 0;
			return (ft_get_way_one(temp_link->link));
		}
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	return (NULL);
}

t_paths			*ft_set_shortcut_path(t_info *info)
{
	t_paths		*paths_all;
	t_way		*path_one;

	paths_all = NULL;
	path_one = ft_get_way_one(info->end);
	while (path_one->node != info->start)
		path_one = ft_way_end(&path_one,
				ft_path_shortcut(path_one->node, info));
	ft_path_end(&paths_all, ft_get_path(path_one, info));
	return (paths_all);
}
