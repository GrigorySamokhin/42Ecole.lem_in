/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_del_lst_q(t_queue **del)
{
	t_queue		**tmp;

	tmp = del;
	if (*del != NULL)
	{
		while ((*tmp)->next_queue)
			ft_del_lst_q(&(*tmp)->next_queue);
		if (del)
		{
			free(*del);
			*del = NULL;
		}
	}
}

void			ft_set_paths(t_info *info)
{
	t_queue		*queue;
	int			sum_queue;
	t_queue		*temp;

	queue = ft_set_queue(info->start, 0, info);
	while (queue)
	{
		sum_queue = ft_count_list(queue);
		ft_add_paths(queue, info, 0);
		if (sum_queue == 1)
			break ;
		temp = queue;
		queue = queue->next_queue;
		free(temp);
	}
	free(queue);
}

void			ft_add_queue_final(t_queue *queue, t_info *info, int pos, int i)
{
	t_links		*temp;
	int			qar;

	if (queue == NULL || queue->link == info->end || queue->link == info->start)
		return ;
	temp = queue->link->links;
	qar = queue->link->intersection;
	while (i++ < queue->link->link)
	{
		if (!temp->link->vis_fin && ft_no_quene_bfs(queue,
				ft_get_queue(temp, pos, info, 0)))
		{
			if (temp->link->intersection && qar)
			{
				temp->link->vis_fin = FALSE;
				info->to_count++;
			}
			else
			{
				temp->link->vis_fin = 1;
				ft_add_toqueue_bfs(&queue, ft_get_queue(temp, pos, info, 0));
			}
		}
		temp->next_links ? temp = temp->next_links : 0;
	}
}

void			ft_set_levels_final_help(t_queue **queue, t_queue **temp)
{
	*temp = *queue;
	*queue = (*queue)->next_queue;
	free(*temp);
}

int				ft_set_levels_final(t_adjlst *adjlst,
		t_info *info, t_queue *queue, int pos)
{
	t_queue		*temp;
	int			k;
	int			i;

	info->start->vis_fin = TRUE;
	queue = ft_set_queue_bfs(adjlst, pos - 1, info);
	k = 0;
	while (k++ < info->sum_rooms)
	{
		info->sum_queue = ft_count_list(queue);
		info->to_count = 0;
		if ((info->sum_queue == 1 && k != 0) || queue == NULL)
			break ;
		i = 0;
		while (i++ < info->sum_queue - 1)
		{
			ft_add_queue_final(queue, info, pos, 0);
			if (queue->next_queue)
				ft_set_levels_final_help(&queue, &temp);
		}
		pos += 1;
	}
	free(queue);
	return (0);
}
