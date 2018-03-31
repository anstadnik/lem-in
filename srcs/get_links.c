/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:37:46 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 21:26:30 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	error(char *n1, char *n2)
{
	free(n1);
	free(n2);
	return (-1);
}

static char	connect_rooms(char *n1, char *n2, t_list *rooms)
{
	t_room	*r1;
	t_room	*r2;
	t_room	*cur;

	r1 = NULL;
	r2 = NULL;
	while (!(r1 && r2) && rooms)
	{
		cur = rooms->content;
		if (!ft_strcmp(cur->name, n1))
			r1 = cur;
		if (!ft_strcmp(cur->name, n2))
			r2 = cur;
		rooms = rooms->next;
	}
	if (!r1 || !r2)
	{
		ft_printf("{red}Not existing room %s-%s{eoc}\n", n1, n2);
		return (error(n1, n2));
	}
	ft_lstpushf(&r1->connections, &r2, sizeof(t_room *));
	ft_lstpushf(&r2->connections, &r1, sizeof(t_room *));
	free(n1);
	free(n2);
	return (1);
}

char		get_link(char *str, t_data *data)
{
	char	*n1;
	char	*n2;
	ssize_t	dash;

	if (data->tmp || !data->rooms)
		return (-1);
	if (*str == '#')
		return (ft_strcmp(str, "##start") && ft_strcmp(str, "##end") ? 1 : -1);
	dash = 0;
	if (ft_strchr(str, ' ') || (dash = ft_strsrch(str, '-')) == -1 ||
			ft_strchr(str + dash + 1, '-'))
	{
		ft_printf("{red}Error in link %s{eoc}\n", str);
		return (-1);
	}
	n1 = ft_strsub(str, 0, dash);
	n2 = ft_strsub(str, dash + 1, ft_strlen(str) - dash);
	if (!ft_strcmp(n1, n2))
	{
		ft_printf("{red}Same name in links{eoc}\n", str);
		return (error(n1, n2));
	}
	data->links_am++;
	return (connect_rooms(n1, n2, data->rooms));
}
