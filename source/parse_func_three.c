/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			error_adj(t_adjlst **adjlst, t_adjlst *new)
{
	t_adjlst	*temp;

	temp = *adjlst;
	while (temp)
	{
		if (ft_strcmp(temp->name, new->name) == 0)
			erreur(12);
		temp = temp->next_adj;
	}
}

void			ft_adjlst_end(t_adjlst **adjlst, t_adjlst *new,
		t_info *info, int flag)
{
	t_adjlst	*temp_adj;

	temp_adj = *adjlst;
	if (temp_adj == NULL)
	{
		*adjlst = new;
		flag == 1 ? info->start = *adjlst : 0;
		flag == 2 ? info->end = *adjlst : 0;
	}
	else
	{
		error_adj(adjlst, new);
		while (temp_adj->next_adj)
			temp_adj = temp_adj->next_adj;
		temp_adj->next_adj = new;
		flag == 1 ? info->start = temp_adj->next_adj : 0;
		flag == 2 ? info->end = temp_adj->next_adj : 0;
	}
	flag == 1 ? new->start = 1 : 0;
}

int				is_already(t_adjlst *adjlst, t_info *info, int flag)
{
	t_adjlst *temp;

	temp = adjlst;
	while (temp)
	{
		if ((temp == info->start && flag == 1)
			|| (temp == info->end && flag == 2))
			return (1);
		temp = temp->next_adj;
	}
	return (0);
}

void			ft_adjlst_end_help(t_adjlst **adjlst, t_info *info,
					int flag)
{
	char		*line;

	if (flag == 1 || flag == 2)
	{
		if (is_already(*adjlst, info, flag))
			erreur(10);
	}
	while (getline_print(info->fd, &line))
	{
		if (line[0] != '#')
			break ;
		free(line);
	}
	ft_adjlst_end(adjlst, ft_get_adjlst(line), info, flag);
	ft_strdel(&line);
}

t_adjlst		*move_start_to_start(t_adjlst *adjlst, int pos, t_adjlst *temp)
{
	t_adjlst	*prev;
	t_adjlst	*start;

	temp = adjlst;
	if (adjlst->start != 1)
	{
		prev = temp;
		while (temp)
		{
			if (temp->start == 1)
			{
				start = temp;
				prev->next_adj = temp->next_adj;
				pos = 1;
			}
			prev = temp;
			temp = temp->next_adj;
		}
		if (!pos)
			erreur(11);
		start->next_adj = adjlst;
		return (start);
	}
	return (adjlst);
}
