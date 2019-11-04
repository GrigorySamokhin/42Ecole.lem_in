/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_set_sum_rooms(t_adjlst *adjlst)
{
	int			count;
	t_adjlst	*temp;

	count = 0;
	temp = adjlst;
	while (temp->next_adj)
	{
		count++;
		temp = temp->next_adj;
	}
	return (count);
}

t_queue			*ft_get_queue(t_links *list, int pos, t_info *info, int rev)
{
	t_queue		*links;

	links = (t_queue *)malloc(sizeof(t_queue));
	links->link = list->link;
	if (rev == 0)
		list->link->visited = (list->link == info->end) ? FALSE : TRUE;
	else
		list->link->visited = (list->link == info->end) ? TRUE : FALSE;
	pos != 0 ? links->link->pos = pos : 0;
	links->next_queue = NULL;
	return (links);
}

t_links			*ft_get_lst(void *adjlst)
{
	t_links		*links;

	links = (t_links *)malloc(sizeof(t_links));
	links->link = adjlst;
	links->next_links = NULL;
	return (links);
}

void			ft_lst_end(t_links **lst, t_links *new)
{
	t_links		*tmp;

	tmp = *lst;
	if (tmp == NULL)
		*lst = new;
	else
	{
		while (tmp->next_links)
			tmp = tmp->next_links;
		tmp->next_links = new;
	}
}

int				ft_count_list(t_queue *queue)
{
	t_queue		*temp;
	int			result;

	result = 1;
	temp = queue;
	while (temp)
	{
		result++;
		temp = temp->next_queue;
	}
	return (result);
}
