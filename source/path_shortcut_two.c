/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_shortcut_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way			*ft_path_start_test(t_adjlst *list)
{
	t_links		*temp_link;
	t_adjlst	*temp_min;
	int			i;

	i = 0;
	temp_link = list->links;
	temp_min = list->links->link;
	if ((temp_min->path || temp_min->shortcut) && list->link > 1)
		temp_min = list->links->next_links->link;
	while (i++ < list->link)
	{
		if (!temp_link->link->path)
		{
			if (temp_link->link->pos >= temp_min->pos &&
				!temp_link->link->shortcut)
				temp_min = temp_link->link;
		}
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	temp_min->test_path = 1;
	return (ft_get_way_one(temp_min));
}

t_adjlst		*ft_pathhelp(t_links *temp, t_adjlst *temp_min)
{
	while (temp_min->path)
	{
		temp->next_links ? temp = temp->next_links : 0;
		temp_min = temp->link;
		if (!temp->next_links)
			break ;
	}
	if (temp_min->path)
		return (NULL);
	return (temp_min);
}

t_way			*ft_path_start(t_adjlst *list, t_info *info)
{
	t_links		*temp_link;
	t_adjlst	*temp_min;
	t_links		*temp;
	int			i;

	i = 0;
	temp_link = list->links;
	temp = info->end->links;
	temp_min = info->end->links->link;
	if (!(temp_min = ft_pathhelp(temp, temp_min)))
		return (NULL);
	while (i++ < list->link)
	{
		if (!temp_link->link->path)
		{
			if (temp_link->link->pos <= temp_min->pos &&
				!temp_link->link->shortcut)
				temp_min = temp_link->link;
		}
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
	temp_min->path = 1;
	return (ft_get_way_one(temp_min));
}
