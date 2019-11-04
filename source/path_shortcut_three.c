/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_shortcut_three.                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_path_search_help(t_adjlst *list, t_adjlst *to_go,
									t_links *temp_link, t_info *info)
{
	int			i;

	i = 0;
	while (i++ < list->link)
	{
		if (to_go->pos >= temp_link->link->pos && temp_link->link != info->end
			&& temp_link->link->link > 1 && (!temp_link->link->test_path
			&& !temp_link->link->path))
			to_go = temp_link->link;
		temp_link->next_links ? temp_link = temp_link->next_links : 0;
	}
}

void			ft_path_search_help_2(t_adjlst *list, t_adjlst *to_go,
		t_links *temp_link, t_info *info)
{
	int			i;
	int			pos_link;

	i = 0;
	temp_link = list->links;
	pos_link = to_go->pos + 2;
	if (!ft_valid_way(to_go, info) && to_go->pos < 10)
	{
		while (i++ < list->link)
		{
			if (temp_link->link->pos == pos_link && (!temp_link->link->path
			&& !temp_link->link->test_path))
				to_go = temp_link->link;
			temp_link->next_links ? temp_link = temp_link->next_links : 0;
		}
	}
}

t_way			*ft_path_search(t_adjlst *list, t_info *info)
{
	t_links		*temp_link;
	t_adjlst	*to_go;

	temp_link = list->links;
	to_go = list->links->link;
	if (list->link == 1)
		return (NULL);
	if ((to_go->path || to_go->test_path) && list->link >= 2)
		to_go = list->links->next_links->link;
	ft_path_search_help(list, to_go, temp_link, info);
	ft_path_search_help_2(list, to_go, temp_link, info);
	if (to_go->test_path || to_go->path)
		return (NULL);
	else
		to_go != info->start ? to_go->test_path = 1 : 0;
	return (ft_get_way_one(to_go));
}

int				ft_set_intersections(t_info *info)
{
	t_adjlst	*temp;
	int			result;

	result = 1;
	temp = info->start;
	while (temp)
	{
		result++;
		temp->link >= 3 && temp->shortcut ? temp->intersection = TRUE : 0;
		temp = temp->next_adj;
	}
	return (result);
}
