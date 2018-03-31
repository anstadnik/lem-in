/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:51:52 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 14:43:20 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//list of pointers to rooms I gotta check
//put there start
//pop 1st, and work with this one
//go through all it's connections, make them be checked, put in list all of them
//and also put in them way to them
//and don't forget to add them to list of ways

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
		way.len = room->way_to->len + 1;
		way.ants = 0;
		way.way = malloc(sizeof(t_way *) * way.len);
		ft_memcpy(way.way, room->way_to->way, sizeof(t_way *) * room->way_to->len);
		way.way[room->way_to->len] = cur;
		ft_lstpushf(&data->ways, &way, sizeof(t_way));
		cur->way_to = data->ways->content;
		tmp = tmp->next;
	}
}

static void	initialize_start(t_list **stack, t_data *data)
{
	t_way	way;

	*stack = NULL;
	ft_lstpushb(stack, &data->start, sizeof(t_data *));
	data->start->checked = 1;
	way.len = 1;
	way.way = malloc(sizeof(t_room *));
	way.way[0] = data->start;
	way.ants = 0;
	ft_lstpushb(&data->ways, &way, sizeof(t_way));
	data->start->way_to = data->ways->content;
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
	/* ft_printf("{magenta}\nget_ways{eoc}\n"); */
	initialize_start(&stack, data);
	/* print_data(*data); */
	while (stack)
	{
		cur = *(t_room **)stack->content;
		ft_lstdelnode(&stack, stack);
		process(data, cur, &stack);
	}
	print_data(*data);
	return (0);
}
