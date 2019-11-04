/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_square(t_visu *visu, int x, int y, int color)
{
	int		temp_x;
	int		temp_y;
	int		init_x;
	int		max;

	max = ((visu->win_x - (2 * visu->b_x)) / visu->x) / 3;
	max = (max > 30) ? 30 : max;
	max = (max < 1) ? 1 : max;
	temp_x = x + max;
	temp_y = y + max;
	x -= max;
	y -= max;
	init_x = x;
	while (x < temp_x || y < temp_y)
	{
		if ((x % temp_x) == 0)
		{
			x = init_x;
			y++;
		}
		mlx_pixel_put(visu->mlx_ptr, visu->win_ptr, x, y, color);
		x++;
	}
}

void		print_square(t_visu *visu, t_adjlst *adjlst, int *x, t_info *info)
{
	int				y;
	t_adjlst		*temp;

	temp = adjlst;
	while (temp)
	{
		*x = temp->cor_x;
		y = temp->cor_y;
		if (temp == info->start)
		{
			draw_square(visu, *x, y, 0xFFFFFF);
			mlx_string_put(visu->mlx_ptr, visu->win_ptr, *x - 5, y - 10,
				0xFFFFFF, "      START");
		}
		else if (temp == info->end)
		{
			draw_square(visu, *x, y, 0xFFFFFF);
			mlx_string_put(visu->mlx_ptr, visu->win_ptr, *x - 5, y - 10,
				0xFFFFFF, "      END");
		}
		else
			draw_square(visu, *x, y, 0x778899);
		temp = temp->next_adj;
	}
}

void		display_dots(t_visu *visu, t_adjlst *adjlst, t_info *info)
{
	t_adjlst		*temp;
	int				x;

	x = 0;
	temp = adjlst;
	while (temp)
	{
		print_lines(visu, temp);
		temp = temp->next_adj;
	}
	temp = adjlst;
	mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
	print_square(visu, adjlst, &x, info);
}
