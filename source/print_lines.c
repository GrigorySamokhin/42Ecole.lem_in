/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_draw			*init_draw(int x1, int y1, int x2, int y2)
{
	t_draw	*draw;

	if (!(draw = (t_draw *)malloc(sizeof(t_draw))))
		return (NULL);
	draw->delta_x = x2 - x1;
	draw->delta_y = y2 - y1;
	draw->sign_x = x1 < x2 ? 1 : -1;
	draw->sign_y = y1 < y2 ? 1 : -1;
	if (draw->delta_x < 0)
		draw->delta_x *= -1;
	if (draw->delta_y < 0)
		draw->delta_y *= -1;
	draw->error = draw->delta_x - draw->delta_y;
	return (draw);
}

void			draw_line(t_dot *cor, int x2, int y2, t_visu *visu)
{
	t_draw		*draw;

	draw = init_draw(cor->x, cor->y, x2, y2);
	mlx_pixel_put(visu->mlx_ptr, visu->win_ptr, x2, y2, 0xFFFFFF);
	while (cor->x != x2 || cor->y != y2)
	{
		mlx_pixel_put(visu->mlx_ptr, visu->win_ptr, cor->x, cor->y, 0xFFFFFF);
		draw->error2 = draw->error * 2;
		if (draw->error2 > -draw->delta_y)
		{
			draw->error -= draw->delta_y;
			cor->x += draw->sign_x;
		}
		if (draw->error2 < draw->delta_x)
		{
			draw->error += draw->delta_x;
			cor->y += draw->sign_y;
		}
	}
}

void			print_lines(t_visu *visu, t_adjlst *adjlst)
{
	t_links		*links;
	t_adjlst	*temp;
	t_dot		*cor;

	temp = adjlst;
	links = adjlst->links;
	if (!(cor = (t_dot *)malloc(sizeof(t_dot))))
		return ;
	while (links)
	{
		cor->x = adjlst->cor_x;
		cor->y = adjlst->cor_y;
		draw_line(cor, links->link->cor_x, links->link->cor_y, visu);
		links = links->next_links;
	}
	free(cor);
}
