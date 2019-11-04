/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_func_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_set_zero_testpath(t_info *info)
{
	t_adjlst *temp;

	temp = info->start;
	while (temp)
	{
		temp->test_path = FALSE;
		temp = temp->next_adj;
	}
}

t_way			*ft_set_temp_path(t_adjlst *top)
{
	t_way		*temp_path;

	temp_path = ft_get_way_one(top);
	temp_path->node->test_path = 1;
	temp_path->node->path = 0;
	temp_path = ft_way_end(&temp_path,
			ft_path_start_test(temp_path->node));
	temp_path->node->test_path = 1;
	temp_path->node->path = 0;
	return (temp_path);
}

t_way			*ft_choose_second_way(t_way *temp_path,
		t_info *info, int *count)
{
	while (!ft_valid_way(temp_path->node, info))
	{
		*count += 1;
		if (!(temp_path = ft_way_end(&temp_path,
				ft_path_search(temp_path->node, info))))
		{
			*count = 10000;
			break ;
		}
	}
	if (temp_path)
	{
		while (temp_path->node != info->start)
		{
			*count += 1;
			if (!(temp_path = ft_way_end(&temp_path,
					ft_path_test(temp_path->node, info))))
			{
				*count = 10000;
				break ;
			}
		}
	}
	return (temp_path);
}

int				ft_choose_way(t_adjlst *top, t_info *info)
{
	int			count;
	t_way		*temp_path;

	count = 0;
	temp_path = ft_set_temp_path(top);
	if (ft_valid_way(temp_path->node, info))
		while (temp_path->node != info->start)
		{
			if (!(temp_path = ft_way_end(&temp_path,
					ft_path_test(temp_path->node, info))))
				return (0);
			count++;
		}
	else
		temp_path = ft_choose_second_way(temp_path, info, &count);
	ft_set_zero_testpath(info);
	ft_del_lst_ways(&temp_path);
	return (count);
}

t_way			*ft_set_fin_adder(t_way *path_one, t_info *info)
{
	if (ft_valid_way(path_one->node, info))
		while (path_one->node != info->start)
			path_one = ft_way_end(&path_one, ft_path(path_one->node, info));
	else
	{
		while (!ft_valid_way(path_one->node, info))
			if (!(path_one = ft_way_end(&path_one,
				ft_path_second_way(path_one->node, info))))
				break ;
		if (path_one)
			while (path_one->node != info->start)
				if (!(path_one = ft_way_end(&path_one,
						ft_path(path_one->node, info))))
					break ;
	}
	return (path_one);
}
