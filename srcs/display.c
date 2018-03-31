/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:11:10 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 21:38:07 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_room(t_room *room)
{
	int	c;

	c = 0;
	ft_printf("{yellow}name = %s, coords = [%d, %d]",
			room->name, room->coords[0], room->coords[1]);
	if (room->start)
		ft_printf(", {magenta}start{eoc}");
	if (room->end)
		ft_printf(", {magenta}end{eoc}");
	if (room->way_to)
	{
		ft_printf("{green}\nWay_len = %d\n{eoc}", room->way_to->len);
		ft_printf("{green}Way to this room:\n{eoc}");
		c = 0;
		while (c < room->way_to->len)
		{
			ft_printf("{yellow}%s{eoc}", room->way_to->way[c++]->name);
			if (c != room->way_to->len)
				ft_printf("{yellow}-{eoc}");
		}
	}
	ft_printf("\n");
}

static void	print_rooms(t_list *rooms)
{
	t_room	*room_tmp;
	t_list	*list_tmp;

	while (rooms)
	{
		room_tmp = rooms->content;
		print_room(room_tmp);
		if ((list_tmp = room_tmp->connections))
		{
			ft_printf("{green}Connections:\n{eoc}");
			while (list_tmp)
			{
				room_tmp = *(t_room **)list_tmp->content;
				ft_printf("{yellow}%s\n{eoc}", room_tmp->name);
				list_tmp = list_tmp->next;
			}
		}
		else
			ft_printf("{green}No connections\n{eoc}");
		rooms = rooms->next;
		ft_printf("\n");
	}
}

static void	print_ways(t_list *ways)
{
	int		c;
	t_way	*way;

	while (ways)
	{
		way = ways->content;
		ft_printf("{yellow}len = %d, ants = %d\n{eoc}", way->len, way->ants);
		ft_printf("{green}Ways:\n{eoc}");
		c = 0;
		while (c < way->len)
		{
			ft_printf("{yellow}%s{eoc}", way->way[c++]->name);
			if (c != way->len)
				ft_printf("{yellow}-{eoc}");
		}
		ft_printf("\n\n");
		ways = ways->next;
	}
}

void		print_data(t_data d)
{
	ft_printf("{blue}\n###############################################\n{eoc}");
	ft_printf("{yellow}MY DATA:\n\n{eoc}");
	ft_printf("{cyan}ROOMS:\n\n{eoc}");
	print_rooms(d.rooms);
	ft_printf("{cyan}WAYS:\n\n{eoc}");
	print_ways(d.ways);
	ft_printf("{green}starts amount = %d, ends amount = %d\n{eoc}",
			d.start_end[0], d.start_end[1]);
	ft_printf("{green}rooms_am = %d, ants_am = %d\n\n{eoc}", d.rooms_am,
			d.ants_am);
	ft_printf("{blue}###############################################\n\n{eoc}");
}

void		print_input(t_data *data)
{
	t_list	*lst;

	lst = data->input;
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
	ft_lstdel(&data->input, &free);
	ft_memdel((void **)&data->input);
}
