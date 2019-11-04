/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func_two_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_set_links_rooms(t_adjlst *adjlst, char *pos_1, char *pos_2)
{
	t_adjlst	*temp;
	t_adjlst	*temp_2;

	temp = adjlst;
	if (!ft_strcmp(pos_1, pos_2))
		erreur(7);
	while (temp)
	{
		if (!(ft_strcmp(temp->name, pos_1)))
		{
			temp_2 = adjlst;
			if (!(link_by_link(temp, temp_2, pos_2)))
				erreur(8);
			break ;
		}
		temp = temp->next_adj;
	}
	return (1);
}

int				links_errors(char *pos_1, char *pos_2,
					t_adjlst *adjlst, char *line)
{
	if (!(ft_set_links_rooms(adjlst, pos_1, pos_2)))
		return (0);
	if (!ft_strchr(line, '-') && !ft_strchr(line, '#'))
		return (0);
	return (1);
}

int				ft_set_links_help(t_adjlst *adjlst, char **pos_1,
					char **pos_2, char *fir)
{
	if (fir == NULL)
		return (0);
	*pos_1 = ft_strsplit_char(fir, '-');
	*pos_2 = ft_strsplit_char(&fir[ft_strlen(*pos_1) + 1], '\0');
	if (!(ft_set_links_rooms(adjlst, *pos_1, *pos_2)))
		return (0);
	return (1);
}

int				link_by_link(t_adjlst *temp, t_adjlst *temp_2, char *pos_2)
{
	while (temp_2)
	{
		if ((!ft_strcmp(temp_2->name, pos_2)))
		{
			ft_lst_end(&temp->links, ft_get_lst(temp_2));
			ft_lst_end(&temp_2->links, ft_get_lst(temp));
			temp->link++;
			temp_2->link++;
			break ;
		}
		if (!temp_2->next_adj)
			return (0);
		temp_2->next_adj ? temp_2 = temp_2->next_adj : 0;
	}
	return (1);
}

int				ft_set_ant_help(t_info *info)
{
	if (info->sum_ants > 2147483647)
		erreur(1);
	if (info->sum_ants <= 0)
		erreur(2);
	return (1);
}
