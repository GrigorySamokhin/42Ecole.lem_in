/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

double				ft_absdouble(double nb)
{
	return ((nb < 0.0) ? -nb : nb);
}

t_list				*ft_lstcreate(void *content, size_t cs)
{
	t_list			*t;

	if ((t = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	t->content = content;
	t->content_size = cs;
	t->next = NULL;
	return (t);
}

void				ft_lstpushback(t_list **begin_list,
			void *content, size_t cs)
{
	t_list			*tmp;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstcreate(content, cs);
	}
	else
		*begin_list = ft_lstcreate(content, cs);
}

t_adjlst			*find_room_by_name(t_adjlst *adjlst, char *str)
{
	t_adjlst		*temp;

	temp = adjlst;
	while (temp)
	{
		if (!ft_strcmp(temp->name, str))
			return (temp);
		temp = temp->next_adj;
	}
	return (NULL);
}

t_list				*ft_lstatpos(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp;

	i = -1;
	if (!begin_list)
		return (begin_list);
	tmp = begin_list;
	while (++i < nbr)
	{
		if (tmp == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}
