/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			disp_steps(t_visu *visu, t_list **rs, t_adjlst *main, int step)
{
	t_adjlst	*r;
	t_list		*l;
	t_dot		d;
	int			i;
	char		**tmp;

	i = -1;
	l = ft_lstatpos(*rs, step);
	display_dots(visu, main, visu->info);
	while (((char **)l->content)[++i])
	{
		tmp = ft_strsplit(((char**)l->content)[i], '-', NULL);
		r = find_room_by_name(main, tmp[1]);
		d.x = r->cor_x;
		d.y = r->cor_y;
		if (r != visu->info->start && r != visu->info->end)
		{
			draw_square(visu, d.x, d.y, 0xEB402B);
			mlx_string_put(visu->mlx_ptr, visu->win_ptr, d.x - 5, d.y - 10,
					0x000000, tmp[0] + 1);
		}
		freechar2(tmp);
	}
}

int				ft_lstsize(t_list *begin_list)
{
	t_list		*tmp;
	int			i;

	i = 0;
	if (!begin_list)
		return (0);
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void			go_forward(t_visu *visu)
{
	t_adjlst	*adjlst;
	t_list		*rs;
	int			size;

	adjlst = visu->adjlst;
	rs = visu->room_state;
	size = ft_lstsize(rs);
	if (visu->step == -1)
	{
		visu->step += 1;
		disp_steps(visu, &rs, adjlst, visu->step);
	}
	else if (visu->step == size - 2)
		display_dots(visu, adjlst, visu->info);
	else
	{
		visu->step += 1;
		if (visu->step < size)
			disp_steps(visu, &rs, adjlst, visu->step);
	}
}
