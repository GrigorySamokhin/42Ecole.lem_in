/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_set_levels_help(t_queue **queue)
{
	t_queue *temp;

	temp = *queue;
	*queue = (*queue)->next_queue;
	free(temp);
}

int				ft_set_levels(t_adjlst *adjlst, t_info *info, t_queue *queue)
{
	int		pos;
	int		sum_queue;
	int		k;
	int		i;

	pos = 2;
	k = -1;
	queue = ft_set_queue_bfs(adjlst, pos - 1, info);
	while (++k < info->sum_rooms)
	{
		sum_queue = ft_count_list(queue);
		if ((sum_queue == 1 && k != 0) || queue == NULL)
			break ;
		i = -1;
		while (++i < sum_queue - 1)
		{
			ft_add_queue_bfs(queue, info, pos);
			queue->next_queue ? ft_set_levels_help(&queue) : 0;
		}
		pos += 1;
	}
	info->max_pos = pos;
	free(queue);
	return (0);
}

t_adjlst		*ft_what_min_vertex(t_adjlst *list)
{
	t_links		*temp_min;
	t_links		*temp;
	int			i;

	i = 0;
	temp = list->links;
	temp_min = list->links;
	while (i++ < list->link)
	{
		if (temp->link->pos < temp_min->link->pos)
			temp_min = temp;
		temp = temp->next_links;
	}
	if (temp_min == NULL)
	{
		ft_putstr("No way.\n");
		exit(1);
	}
	temp_min->link->shortcut = TRUE;
	return (temp_min->link);
}

void			ft_set_shortcut(t_info *info, int i)
{
	t_links		*temp_link;
	t_adjlst	*temp_adj;
	int			quantity;
	int			importance;

	temp_adj = ft_what_min_vertex(info->end);
	quantity = temp_adj->pos;
	importance = temp_adj->pos;
	while (i++ < quantity)
	{
		temp_link = temp_adj->links;
		while (temp_link->next_links)
		{
			if (temp_link->link->pos == importance - 1)
				break ;
			temp_link = temp_link->next_links;
		}
		if (temp_link->link->pos == importance - 1)
			temp_link->link->shortcut = TRUE;
		temp_adj = temp_link->link;
		importance--;
	}
	info->ways = info->end->link;
	info->start->link <= info->end->link ? info->ways =
			info->start->link : 0;
}

t_queue			*ft_set_queue(t_adjlst *adjlst, int pos, t_info *info)
{
	t_queue		*queue;
	t_queue		*start;
	t_links		*temp;
	int			i;

	i = 0;
	temp = adjlst->links;
	adjlst->visited = 0;
	queue = NULL;
	start = queue;
	while (i++ < adjlst->link)
	{
		if (!temp->link->shortcut)
			ft_add_toqueue_bfs(&queue, ft_get_queue(temp, pos, info, 1));
		if (temp->next_links)
			temp = temp->next_links;
	}
	ft_del_lst_q(&queue);
	return (start);
}
