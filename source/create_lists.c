/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_is_digital_str(char *str)
{
	int			i;

	i = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void			ft_set_coord(t_adjlst *adjlst, char *line)
{
	int			i;
	int			size;
	char		**str;

	i = 0;
	while (line[i] > 32)
		i++;
	while (line[i] <= 32)
		i++;
	str = ft_strsplit(&line[i], ' ', &size);
	if (!str[0] || !str[1])
		erreur(13);
	if (ft_is_digital_str(str[0]) && ft_is_digital_str(str[1]) && size == 2)
	{
		adjlst->cor_x = ft_atoi(str[0]);
		adjlst->cor_y = ft_atoi(str[1]);
	}
	else
		erreur(14);
	free(str[0]);
	free(str[1]);
	free(str);
}

t_info			*ft_create_info(void)
{
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->ways = 0;
	info->count = 0;
	info->fd = 0;
	info->numb_ant = 0;
	info->inter = 0;
	info->sum_ants = 0;
	info->sum_queue = 0;
	info->sum_rooms = 0;
	info->to_count = 0;
	return (info);
}

t_adjlst		*ft_get_adjlst(char *line)
{
	t_adjlst	*adjlst;

	adjlst = (t_adjlst *)malloc(sizeof(t_adjlst));
	adjlst->y = 0;
	adjlst->name = ft_strsplit_char(line, 32);
	ft_set_coord(adjlst, line);
	adjlst->x = 0;
	adjlst->shortcut = FALSE;
	adjlst->link = 0;
	adjlst->x = 0;
	adjlst->path = 0;
	adjlst->start = 0;
	adjlst->ant = 0;
	adjlst->vis_fin = 0;
	adjlst->links = NULL;
	adjlst->next_adj = NULL;
	adjlst->pos = 0;
	adjlst->visited = 0;
	adjlst->intersection = 0;
	return (adjlst);
}

t_adjlst		*ft_get_copy(t_adjlst *temp)
{
	t_adjlst	*adjlst;

	adjlst = (t_adjlst *)malloc(sizeof(t_adjlst));
	adjlst->y = 0;
	adjlst->name = temp->name;
	adjlst->x = 0;
	adjlst->shortcut = FALSE;
	adjlst->link = 0;
	adjlst->path = 0;
	adjlst->ant = 0;
	adjlst->vis_fin = 0;
	adjlst->links = NULL;
	adjlst->next_adj = NULL;
	adjlst->pos = INT_MAX;
	adjlst->visited = 0;
	adjlst->intersection = 0;
	return (adjlst);
}
