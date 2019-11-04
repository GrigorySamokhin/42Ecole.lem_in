/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				i(t_info *info)
{
	free(info);
	return (1);
}

int				ft_dispatcher(void)
{
	t_adjlst	*adjlst;
	t_info		*info;

	info = ft_create_info();
	info->fd = 0;
	if (!(adjlst = ft_create_adjlst(info, 0, NULL)))
		return (i(info));
	ft_putendl("");
	info->sum_rooms = ft_set_sum_rooms(adjlst);
	if (!(info->end) || !(info->start))
	{
		ft_putendl("No start or end");
		exit(1);
	}
	adjlst = move_start_to_start(adjlst, 0, NULL);
	ft_bfc(adjlst, info, NULL);
	ft_del_lst_adjlst(&adjlst);
	free(info);
	return (1);
}

int				main(int args, char **argv)
{
	if (args == 1)
		ft_dispatcher();
	else
		ft_putendl(" < 'Lem-in type file'");
	(void)argv;
	return (1);
}
