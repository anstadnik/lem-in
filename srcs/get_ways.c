/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:51:52 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 12:53:33 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	process(t_data *data, t_room *room, t_list **stack)
{
	t_list	*tmp;
	t_room	*cur;
	t_way	way;

	tmp = room->connections;
	while (tmp)
	{
		cur = *(t_room **)tmp->content;
		if (cur->checked)
		{
			tmp = tmp->next;
			continue;
		}
		cur->checked = 1;
		ft_lstpushb(stack, &cur, sizeof(t_data *));
		way.len = room->way_len + 1;
		ft_printf("{cyan}room_len = %d, way.len = %d\n{eoc}", room->way_len, way.len);
		way.ants = 0;
		way.way = ft_realloc(cur->way_to, cur->way_len, way.len);
		way.way[cur->way_len] = room->num;
		cur->way_to = way.way;
		cur->way_len = way.len;
		ft_lstpushb(&data->ways, &way, sizeof(t_way));
		tmp = tmp->next;
	}
}

char	get_ways(t_data *data)
{
	t_list	*stack;
	t_room	*cur;

	if (data->start_end[0] != 1 || data->start_end[1] != 1)
	{
		ft_printf("{red}No end or start{eoc}");
		return (err(data));
	}
	ft_printf("{magenta}\nget_ways{eoc}\n");
	//list of pointers to rooms I gotta check
	//put there start
	//pop 1st, and work with this one
	//go through all it's connections, make them be checked, put in list all of them
	//and also put in them way to them
	//and don't forget to add them to list of ways

	stack = NULL;
	ft_lstpushb(&stack, &data->start, sizeof(t_data *));
	data->start->checked = 1;
	while (stack)
	{
		cur = *(t_room **)stack->content;
		ft_printf("name = %s\n", cur->name);
		ft_lstdelnode(&stack, stack);
		process(data, cur, &stack);
	}
	return (0);
}
