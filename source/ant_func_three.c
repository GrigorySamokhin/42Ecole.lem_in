/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_func_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_zer_temp(t_adjlst **temp, t_info *info)
{
	temp[1]->ant = -1;
	temp[1]->ret == 0 ? info->ret++ : 0;
	temp[1]->ret = 1;
}

int				ft_zero(int *i)
{
	*i -= 1;
	if (*i == -1)
		*i += 1;
	return (0);
}

int				print_ant(t_adjlst **temp, int len, t_info *info)
{
	if (temp[1]->engaged && len == temp[1]->count)
		return (1);
	len - 1 >= 0 ? temp[len]->ant = temp[len - 1]->ant : 0;
	temp[len]->ant > 0 ? print_block(temp[len]->ant, temp[len]->name) : 0;
	len == temp[1]->count && temp[len]->ant != -1 ? info->end->ant++ : 0;
	(info->sum_ants == info->numb_ant && len == temp[1]->count)
		? temp[1]->engaged = TRUE : 0;
	(info->sum_ants == info->numb_ant && len == 2)
		? ft_zer_temp(temp, info) : 0;
	if (len - 2 >= 0)
		if (temp[len]->ant == temp[len - 1]->ant && temp[len - 2]->ant == -1)
		{
			temp[len - 1]->ant = -1;
			temp[1]->ret == 0 ? info->ret++ : 0;
			temp[1]->ret = 1;
		}
	if (temp[temp[1]->count]->ant == -1)
	{
		temp[1]->engaged = 0;
		return (1);
	}
	return (0);
}

int				ft_move_ant(t_adjlst **temp, t_info *info, int *i)
{
	int len;
	int len2;

	len = temp[1]->count;
	if ((len2 = ft_set_ant_return(temp, &len)) == -2)
		return (ft_zero(i));
	if (len2 == -1 && len != 1)
	{
		if (print_ant(temp, len, info) == 1)
			return (ft_zero(i));
	}
	else
	{
		if (print_ant(temp, len2, info) == 2)
			return (1);
		if (len2 - 1 > 0)
			if (info->sum_ants == info->numb_ant && temp[len2 - 2]->ant == -1)
				temp[len2 - 1]->ant = -1;
	}
	return (0);
}

int				end(t_adjlst ***temp, t_info *info)
{
	int i;

	i = -1;
	while (++i < info->ways)
		if (temp[i][2])
			if (temp[i][1]->ant != temp[i][2]->ant)
				return (0);
	i = -1;
	while (++i < info->ways)
		if (temp[i][1]->ant == -1)
			return (0);
	return (1);
}
