/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_free_arr(t_adjlst ***temp, t_info *info)
{
	int			i;

	i = -1;
	while (++i < info->ways)
	{
		free(temp[i][temp[i][1]->x]);
		free(temp[i]);
	}
	free(temp);
}

int				ft_print_add(t_adjlst ***temp, t_info *info, int *i)
{
	info->pos == info->ways ? info->pos = 0 : 0;
	if (ft_move_ant(temp[info->pos], info, i) == 1)
		info->ret++;
	info->pos++;
	if (end(temp, info) || info->ret == info->ways)
		return (0);
	return (1);
}

int				ender(t_adjlst ***temp, t_info *info)
{
	int			i;

	i = -1;
	while (++i < info->ways)
	{
		if (temp[i][temp[i][1]->count]->ant != -1)
		{
			if (temp[i][1]->count == 1)
				continue;
			return (0);
		}
	}
	if (info->numb_ant == info->sum_ants)
		return (1);
	return (0);
}

void			ft_print_ants_help(t_info *info, int cn, t_adjlst ***temp)
{
	int			i;

	i = 0;
	while (info->end->ant <= info->sum_ants)
	{
		cn = info->end->ant;
		info->pos = 0;
		while (i++ <= info->numb)
			if (!(ft_print_add(temp, info, &i)))
				break ;
		ft_set_ants_start(temp, info, 1);
		ft_putstr("\n");
		if (ender(temp, info))
			break ;
		if (info->end->ant >= info->sum_ants)
			break ;
		info->numb = info->numb_ant - info->end->ant + info->ways;
		info->ret = 0;
		if (cn == info->end->ant && cn != 0)
			break ;
		i = 0;
	}
}

void			ft_print_ants(t_paths *paths_all, t_info *info)
{
	t_adjlst	***temp;

	temp = ft_get_array(paths_all, info);
	ft_set_ants_start(temp, info, 1);
	ft_putstr("\n");
	if (info->end->ant != info->sum_ants)
		ft_print_ants_help(info, 0, temp);
	ft_free_arr(temp, info);
}
