/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_n_cord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list			*get_room_states(void)
{
	char		*line;
	char		**tab;
	t_list		*all;
	char		**temp;

	all = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "ERROR") == 0)
			exit(0);
		if (!line[0])
			ft_printf("ERROR\n");
		else
		{
			tab = ft_strsplit(line, ' ', NULL);
			ft_char_two_dem(tab);
			temp = get_words(tab);
			ft_lstpushback(&all, temp, 0);
			ft_free2((void **)tab);
		}
		free(line);
	}
	return (all);
}

int				**create_two_dem_int(int size, int len)
{
	int			**arr;
	int			i;

	i = -1;
	if (size < 1 || len < 1)
		return (NULL);
	if (!(arr = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	while (++i < size)
		if (!(arr[i] = (int *)malloc(sizeof(int) * len)))
			return (NULL);
	return (arr);
}

int				**get_map_coords(t_adjlst *adjlst, t_info *info,
				int max_x, int max_y)
{
	int			**map;
	t_adjlst	*temp;

	temp = adjlst;
	if (!(map = create_two_dem_int((max_x * max_y), 1)))
		return (NULL);
	while (temp)
	{
		if (temp == info->start)
			map[temp->cor_x + (max_x * temp->cor_y)][0] = 0;
		else if (temp == info->end)
			map[temp->cor_x + (max_x * temp->cor_y)][0] = 0;
		else
			map[temp->cor_x + (max_x * temp->cor_y)][0] = 0;
		temp = temp->next_adj;
	}
	return (map);
}

t_visu			*gen_map(t_adjlst *adjlst)
{
	int			max_x;
	int			max_y;
	t_visu		*visu;
	t_adjlst	*temp;

	max_x = 0;
	max_y = 0;
	temp = adjlst;
	while (temp)
	{
		if (temp->cor_x > max_x)
			max_x = temp->cor_x;
		if (temp->cor_y > max_y)
			max_y = temp->cor_y;
		temp = temp->next_adj;
	}
	max_x++;
	max_y++;
	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		return (NULL);
	visu->x = max_x;
	visu->y = max_y;
	visu->coords = NULL;
	return (visu);
}

void			convert_coords(t_visu *visu, t_adjlst *adjlst)
{
	t_adjlst	*temp;
	int			c_x;
	int			c_y;

	c_x = ((visu->win_x - (2 * 150)) / visu->x);
	c_y = ((visu->win_y - (2 * 150)) / visu->y);
	temp = adjlst;
	(void)visu;
	while (temp)
	{
		temp->cor_x = temp->cor_x * c_x + 150;
		temp->cor_y = temp->cor_y * c_y + 150;
		temp = temp->next_adj;
	}
}
