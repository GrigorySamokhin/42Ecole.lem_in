/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_func_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_set_ways(t_adjlst ***temp, t_way *path, int i, int len)
{
	int j;

	j = -1;
	while (++j < len)
	{
		if (j + 1 == len)
		{
			temp[i][j] = ft_get_copy(path->node);
			temp[i][1]->x = j;
			temp[i][j + 1] = NULL;
		}
		else
			temp[i][j] = path->node;
		path = path->next_way;
	}
}

t_adjlst			***ft_get_array(t_paths *paths_all, t_info *info)
{
	t_adjlst		***temp;
	t_way			*path;
	int				i;
	int				len;
	int				ants;

	i = -1;
	ants = 0;
	info->ways_all = ft_len_path(paths_all);
	temp = (t_adjlst ***)malloc(sizeof(t_adjlst **) *
			(array_len(paths_all, info) + 1));
	while (++i < info->ways && ants < info->sum_ants && paths_all != NULL)
	{
		path = paths_all->link;
		len = ft_len_way(path);
		ants = ants + len;
		temp[i] = (t_adjlst **)malloc(sizeof(t_adjlst *) * (len + 1));
		ft_set_ways(temp, path, i, len);
		temp[i][1]->count = len - 1;
		paths_all = paths_all->next_paths;
	}
	info->ways = i;
	return (temp);
}

void				ft_adder1(t_adjlst ***temp, t_info *info, int pos2)
{
	int pos1;

	pos1 = -1;
	while (++pos1 < info->ways)
	{
		temp[pos1][pos2]->ant = info->numb_ant < info->sum_ants
								? ++info->numb_ant : -1;
		if (!ft_strcmp(temp[pos1][1]->name, info->end->name))
			info->end->ant++;
	}
	pos1 = -1;
	while (++pos1 < info->ways)
		if (temp[pos1][pos2]->ant > 0)
			print_block(temp[pos1][pos2]->ant, temp[pos1][pos2]->name);
}

void				ft_set_ants_start(t_adjlst ***temp, t_info *info, int pos2)
{
	int i;

	i = -1;
	if (info->numb_ant < info->sum_ants)
		ft_adder1(temp, info, pos2);
	while (++i < info->ways)
	{
		temp[i][1]->engaged = FALSE;
		temp[i][1]->ret = FALSE;
	}
}

int					ft_set_ant_return(t_adjlst **temp, int *len)
{
	int len2;

	if (temp[2] != NULL)
		if (temp[1]->ant == temp[2]->ant && temp[1]->ant != -1)
			return (-2);
	while (temp[*len - 1]->ant == 0)
	{
		*len -= 1;
		if (*len == 0)
			break ;
	}
	len2 = *len;
	while (len2--)
	{
		if (len2 + 1 <= temp[1]->count)
			if (temp[len2 + 1]->ant == temp[len2]->ant
				&& temp[len2 + 1] != 0 && temp[len2 + 1]->ant != -1)
				break ;
	}
	return (len2);
}
