/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_func_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adjlst		*ft_what_max_vertex(t_adjlst *adjlst)
{
	t_links		*temp_max;
	t_links		*temp;
	int			i;

	i = 0;
	temp = adjlst->links;
	temp_max = adjlst->links;
	while (i++ < adjlst->link)
	{
		if (temp->link->pos > temp_max->link->pos && temp->link->shortcut)
			temp_max = temp;
		if (temp->next_links)
			temp = temp->next_links;
	}
	return (temp_max->link);
}

void			ft_add_paths(t_queue *queue, t_info *info, int pos)
{
	t_links		*temp;
	t_adjlst	*temp_adj;
	int			i;

	i = 0;
	if (queue == NULL || info == NULL)
		return ;
	temp = queue->link->links;
	if (queue->link->shortcut)
		temp_adj = ft_what_max_vertex(queue->link);
	else
		temp_adj = NULL;
	while (i++ < queue->link->link)
	{
		if (temp->link->visited && ft_no_quene_bfs(queue,
				ft_get_queue(temp, pos, info, 1)) && !(temp->link == temp_adj))
			ft_add_toqueue_bfs(&queue, ft_get_queue(temp, pos, info, 1));
		temp->next_links ? temp = temp->next_links : 0;
	}
}
