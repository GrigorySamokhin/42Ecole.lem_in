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

void				print_block(int ant, char *name)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(name);
	ft_putstr(" ");
}

int					ft_len_way(t_way *way)
{
	t_way		*temp;
	int			i;

	i = 0;
	temp = way;
	while (temp)
	{
		i++;
		temp = temp->next_way;
	}
	return (i);
}

int					ft_len_path(t_paths *way)
{
	t_paths		*temp;
	int			i;

	i = 0;
	temp = way;
	while (temp)
	{
		i++;
		temp = temp->next_paths;
	}
	return (i);
}

int					array_len(t_paths *paths_all, t_info *info)
{
	t_paths		*temp;
	int			ants;
	int			len;

	len = 0;
	ants = 0;
	temp = paths_all;
	while (ants < info->sum_ants && temp)
	{
		ants = ants + ft_len_way(temp->link);
		temp = temp->next_paths;
		len++;
	}
	return (len - 1);
}
