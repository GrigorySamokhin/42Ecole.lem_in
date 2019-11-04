/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			erreur(int code)
{
	code == 1 ? ft_putstr("ERROR: More than INT_MAX.\n") : 0;
	code == 2 ? ft_putstr("ERROR: Negative value or not a value.\n") : 0;
	code == 3 ? ft_putstr("ERROR: Command before ants.\n") : 0;
	code == 4 ? ft_putstr("ERROR: Empty file or dir "
	"or not ants in the first line.\n") : 0;
	code == 5 ? ft_putstr("ERROR: No links or rooms\n") : 0;
	code == 6 ? ft_putstr("ERROR: Room name starts with 'L'\n") : 0;
	code == 7 ? ft_putstr("ERROR: Bad links.\n") : 0;
	code == 8 ? ft_putstr("ERROR: Not correct links.\n") : 0;
	code == 9 ? ft_putstr("ERROR: Second line at the end of file.\n") : 0;
	code == 10 ? ft_putstr("ERROR: Second start or end.") : 0;
	code == 11 ? ft_putendl("ERROR: No start or end") : 0;
	code == 12 ? ft_putstr("ERROR: Duplicate rooms or spaces.\n") : 0;
	code == 13 ? ft_putstr("ERROR: Not valid coord or spaces.\n") : 0;
	code == 14 ? ft_putstr("ERROR: Too many coord or invaid values.\n") : 0;
	code == 66 ? ft_putstr("ERROR: No way.\n") : 0;
	exit(1);
}

int				getline_print(int fd, char **line)
{
	int pos;

	pos = get_next_line(fd, line);
	if (pos == 0)
		return (0);
	ft_putendl(*line);
	return (pos);
}

int				ft_set_ant(t_info *info)
{
	char		*line;
	int			size;
	char		**str;
	int			ret;

	while ((ret = getline_print(info->fd, &line) > 0))
	{
		if (ft_strncmp("#", line, 1))
			break ;
		if (!strcmp("##start", line) || !strcmp("##end", line))
			erreur(3);
		line != NULL ? free(line) : 0;
	}
	str = ft_strsplit(line, ' ', &size);
	if (ret <= 0 || size > 1 || !ft_is_digital_str(str[0]))
		erreur(4);
	info->sum_ants = ft_atoi(str[0]);
	free(str[0]);
	free(str[1]);
	free(str);
	if (!(ft_set_ant_help(info)))
		return (-1);
	line != NULL ? free(line) : 0;
	return (info->sum_ants);
}

int				ft_create_adjlst_help(t_info *info,
		t_adjlst *adjlst, char *line)
{
	if (!(ft_set_links(info, adjlst, line)))
		erreur(5);
	return (1);
}

t_adjlst		*ft_create_adjlst(t_info *info, int i, char *line)
{
	t_adjlst	*adjlst;

	adjlst = NULL;
	if (ft_set_ant(info) <= 0)
		return (NULL);
	while ((i = getline_print(info->fd, &line)) != 0)
	{
		while (!ft_strchr(line, '-'))
		{
			if (!ft_strcmp(line, "##start"))
				ft_adjlst_end_help(&adjlst, info, 1);
			else if (!ft_strcmp(line, "##end"))
				ft_adjlst_end_help(&adjlst, info, 2);
			else if (line[0] != '#')
				ft_adjlst_end(&adjlst, ft_get_adjlst(line), info, 0);
			(line[0] == 'L') ? erreur(6) : 0;
			line != NULL ? free(line) : 0;
			getline_print(info->fd, &line);
		}
		break ;
	}
	i == 0 ? exit(1) : 0;
	if (!(ft_create_adjlst_help(info, adjlst, line)))
		return (NULL);
	return (adjlst);
}
