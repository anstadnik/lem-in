/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:11:10 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 18:28:53 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_rooms(t_list *rooms)
{
	t_room	*room_tmp;
	t_list	*list_tmp;
	int		c;

	while (rooms)
	{
		room_tmp = rooms->content;
		ft_printf("{yellow}name = %s, coords = [%d, %d]",
				room_tmp->name, room_tmp->coords[0], room_tmp->coords[1]);
		if (room_tmp->start)
			ft_printf(", {magenta}start{eoc}");
		if (room_tmp->end)
			ft_printf(", {magenta}end{eoc}");
		/* ft_printf("{red}POTATO{eoc}"); */
		if (room_tmp->way_to)
		{
			ft_printf("{green}\nWay_len = %d\n{eoc}", room_tmp->way_to->len);
			ft_printf("{green}Way to this room:\n{eoc}");
			c = 0;
			while (c < room_tmp->way_to->len)
			{
				ft_printf("{yellow}%s{eoc}", room_tmp->way_to->way[c++]->name);
				if (c != room_tmp->way_to->len)
					ft_printf("{yellow}-{eoc}");
			}
		}
		ft_printf("\n");
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

void	print_data(t_data data)
{
	t_list	*list_tmp;
	int		c;
	t_way	*way_tmp;

	ft_printf("{blue}\n################################################\n{eoc}");
	ft_printf("{yellow}MY DATA:\n\n{eoc}");
	ft_printf("{cyan}ROOMS:\n\n{eoc}");
	print_rooms(data.rooms);
	ft_printf("{cyan}WAYS:\n\n{eoc}");
	list_tmp = data.ways;
	while (list_tmp)
	{
		way_tmp = list_tmp->content;
		ft_printf("{yellow}len = %d, ants = %d\n{eoc}", way_tmp->len, way_tmp->ants);
		ft_printf("{green}Ways:\n{eoc}");
		c = 0;
		while (c < way_tmp->len)
		{
			ft_printf("{yellow}%s{eoc}", way_tmp->way[c++]->name);
			if (c != way_tmp->len)
				ft_printf("{yellow}-{eoc}");
		}
		ft_printf("\n\n");
		list_tmp = list_tmp->next;
	}
	ft_printf("{green}starts amount = %d, ends amount = %d\n{eoc}", data.start_end[0], data.start_end[1]);
	ft_printf("{green}rooms_amount = %d, ants_amount = %d\n\n{eoc}", data.rooms_amount, data.ants_amount);
	ft_printf("{blue}################################################\n\n{eoc}");
}

void	print_input(t_data *data)
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
