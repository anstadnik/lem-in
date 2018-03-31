/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:05:15 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 18:44:57 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	error(t_list *list)
{
	del_room(list->content);
	free(list);
	return (-1);
}

static char	check_dupl(t_room *room, t_list *rooms)
{
	t_room	*cur;

	while (rooms)
	{
		cur = rooms->content;
		if (!ft_strcmp(room->name, cur->name) ||
				(room->coords[0] == cur->coords[0] &&
				room->coords[1] == cur->coords[1]))
		{
			ft_printf("{red}Found duplicate of room %s{eoc}\n", room->name);
			return (1);
		}
		rooms = rooms->next;
	}
	return (0);
}

static char	parse_room(char *str, t_room *room)
{
	if (*str == 'L' || *str == '#' || *str == ' ' || !*str)
		return (-1);
	room->name = ft_strsub(str, 0, ft_strsrch(str, ' '));
	if (!(str = ft_strchr(str, ' ')) || ft_isinteger(++str) == -1)
		return (-1);
	room->coords[0] = ft_atoi(str);
	if (!(str = ft_strchr(str, ' ')) || ft_isinteger(++str) == -1)
		return (-1);
	room->coords[1] = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (-1);
	return (0);
}

static char	put_room(char *str, t_data *data)
{
	t_list	*list;
	t_room	*room;

	list = ft_memalloc(sizeof(t_list));
	list->content = ft_memalloc(sizeof(t_room));
	room = list->content;
	if (parse_room(str, room) == -1)
	{
		ft_printf("{red}Error in %s's input{eoc}\n", room->name);
		return (error(list));
	}
	if (check_dupl(room, data->rooms) == 1)
		return (error(list));
	data->rooms_amount++;
	if (data->tmp)
	{
		if (data->tmp == 1)
		{
			room->start = 1;
			data->start = room;
		}
		else
			room->end = 1;
		data->tmp = 0;
	}
	ft_lstadd(&data->rooms, list);
	return (0);
}

char	get_room(char *str, t_data *data)
{
	if (*str == '#')
	{
		if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		{
			if (!data->tmp)
				data->tmp = str[2] == 'e' ? 2 : 1;
			else
				return (-1);
			data->start_end[str[2] == 'e']++;
		}
	}
	else
		return (ft_strchr(str, ' ') ? put_room(str, data) : get_link(str, data));
	return (0);
}
