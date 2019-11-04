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

t_paths			*ft_set_final_paths(t_info *info)
{
	t_paths			*paths_all;
	t_way			*path_one;

	paths_all = NULL;
	info->count == 1 ? ft_path_end(&paths_all, ft_set_shortcut_path(info)) : 0;
	while (info->count++ < (info->ways))
	{
		path_one = ft_get_way_one(info->end);
		if (!(path_one = ft_way_end(&path_one,
				ft_path_start(path_one->node, info))))
			break ;
		path_one = ft_set_fin_adder(path_one, info);
		ft_path_end(&paths_all, ft_get_path(path_one, info));
	}
	return (paths_all);
}

void			ft_rec_ways(t_info *info)
{
	info->count = 0;
	if (info->sum_rooms > 100)
		info->count = 1;
}

int				ft_bfc(t_adjlst *adjlst, t_info *info, t_queue *queue)
{
	t_paths		*paths_all;

	adjlst->visited = TRUE;
	ft_set_levels(info->start, info, queue);
	ft_set_shortcut(info, 0);
	ft_set_paths(info);
	ft_set_intersections(info);
	ft_set_levels_final(info->start, info, queue, 2);
	info->end->pos = INT_MAX;
	ft_rec_ways(info);
	paths_all = ft_set_final_paths(info);
	if (paths_all == NULL)
		erreur(66);
	info->numb = info->numb_ant - info->end->ant + info->ways;
	info->pos = 0;
	info->ret = 0;
	info->sum_ants == 1 ? info->ways = 1 : 0;
	ft_print_ants(paths_all, info);
	ft_del_lst_path(&paths_all);
	return (1);
}
