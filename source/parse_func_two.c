/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			error_link(t_adjlst *adjlst)
{
	t_adjlst *temp;

	temp = adjlst;
	while (temp)
	{
		if (temp->link == 0)
		{
			ft_putstr("ERROR: No links in room ");
			ft_putstr(temp->name);
			ft_putstr("\n");
			exit(1);
		}
		temp = temp->next_adj;
	}
}

char			*skip_comments_links(char *line, int fd)
{
	line != NULL ? free(line) : 0;
	while (getline_print(fd, &line))
		if (ft_strncmp("#", line, 1))
			return (line);
	return (line);
}

int				check_sp_free(char *line, int rate)
{
	if (rate == 1)
	{
		if (line[0] <= 32)
		{
			free(line);
			return (1);
		}
		return (0);
	}
	else if (rate == 0)
	{
		free(line);
		return (1);
	}
	return (1);
}

t_adjlst		*ft_set_links(t_info *info, t_adjlst *adjlst, char *line_one)
{
	char		*line;
	char		*pos_1;
	char		*pos_2;

	if (!(ft_set_links_help(adjlst, &pos_1, &pos_2, line_one)))
		return (NULL);
	ft_clean_pos(&pos_1, &pos_2, &line_one);
	while ((info->inter = getline_print(info->fd, &line)) != 0)
	{
		if (check_sp_free(line, 1))
			break ;
		!ft_strncmp("#", line, 1) ?
			line = skip_comments_links(line, info->fd) : 0;
		pos_1 = ft_strsplit_char(line, '-');
		if (ft_count_chr(line, '-'))
			pos_2 = ft_strsplit_char(&line[ft_strlen(pos_1) + 1], '\0');
		else if (check_sp_free(pos_1, 0))
			break ;
		!links_errors(pos_1, pos_2, adjlst, line) ? erreur(7) : 0;
		ft_clean_pos(&pos_1, &pos_2, &line);
	}
	!pos_1 && !pos_2 ? erreur(9) : 0;
	error_link(adjlst);
	return (adjlst);
}
