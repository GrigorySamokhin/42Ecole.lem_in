/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bfs_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_add_toqueue_bfs(t_queue **queue, t_queue *new)
{
	t_queue		*temp;

	temp = *queue;
	if (temp == NULL)
		*queue = new;
	else
	{
		while (temp->next_queue)
			temp = temp->next_queue;
		temp->next_queue = new;
	}
}

t_queue			*ft_set_queue_bfs(t_adjlst *adjlst, int pos, t_info *info)
{
	t_queue		*queue;
	t_queue		*start;
	t_links		*temp;
	int			i;

	i = 0;
	temp = adjlst->links;
	queue = NULL;
	while (i++ < adjlst->link)
	{
		ft_add_toqueue_bfs(&queue, ft_get_queue(temp, pos, info, 0));
		temp->link->vis_fin = 1;
		i == 1 ? start = queue : 0;
		if (temp->next_links)
			temp = temp->next_links;
	}
	return (start);
}

int				ft_no_quene_bfs(t_queue *queue, t_queue *to_check)
{
	t_queue		*temp;

	temp = queue;
	while (temp)
	{
		if (temp->link->name == to_check->link->name)
		{
			free(to_check);
			return (0);
		}
		temp = temp->next_queue;
	}
	free(to_check);
	return (1);
}

void			ft_add_queue_bfs(t_queue *queue, t_info *info, int pos)
{
	int			i;
	t_links		*temp;

	i = 0;
	if (queue == NULL)
		return ;
	temp = queue->link->links;
	while (i++ < queue->link->link)
	{
		if (!temp->link->visited && ft_no_quene_bfs(queue,
				ft_get_queue(temp, pos, info, 0)))
			ft_add_toqueue_bfs(&queue, ft_get_queue(temp, pos, info, 0));
		temp->next_links ? temp = temp->next_links : 0;
	}
}
