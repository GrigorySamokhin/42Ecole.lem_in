/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				deal_key(int key, void *param)
{
	t_visu		*visu;

	visu = (t_visu *)param;
	if (key == 53)
		exit(1);
	else if (key == 124)
		go_forward(visu);
	return (1);
}

void			mlx_main_lemin(t_adjlst *adjlst, t_info *info)
{
	t_visu		*visu;
	t_list		*room_state;

	visu = gen_map(adjlst);
	room_state = get_room_states();
	visu->b_x = 200;
	visu->b_y = 200;
	visu->adjlst = adjlst;
	visu->info = info;
	visu->win_x = 900;
	visu->win_y = 900;
	visu->step = -1;
	visu->room_state = room_state;
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, visu->win_x, visu->win_y,
			"lem-in");
	convert_coords(visu, adjlst);
	display_dots(visu, adjlst, info);
	mlx_key_hook(visu->win_ptr, deal_key, visu);
	mlx_loop(visu->mlx_ptr);
}

int				ft_dispatcher_visu(void)
{
	t_adjlst	*adjlst;
	t_info		*info;

	info = ft_create_info();
	info->fd = 0;
	if (!(adjlst = ft_create_adjlst(info, 0, NULL)))
		return (i_free(info));
	ft_putendl("");
	info->sum_rooms = ft_set_sum_rooms(adjlst);
	adjlst = move_start_to_start(adjlst, 0, NULL);
	mlx_main_lemin(adjlst, info);
	ft_del_lst_adjlst(&adjlst);
	free(info);
	return (1);
}

int				main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		ft_dispatcher_visu();
	else
		ft_printf("ERROR.");
	return (1);
}
