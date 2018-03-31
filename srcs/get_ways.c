/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:51:52 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 17:16:45 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	clear(t_data *data, t_list *stack)
{
	t_list	*rooms;

	ft_lstdel(&stack, &free);
	rooms = data->rooms;
	while (rooms)
	{
		((t_room *)rooms->content)->checked = 0;
		if (!((t_room *)rooms->content)->used && ((t_room *)rooms->content)->way_to)
		{
			free(((t_room *)rooms->content)->way_to->way);
			free(((t_room *)rooms->content)->way_to);
			((t_room *)rooms->content)->way_to = NULL;
		}
		rooms = rooms->next;
	}
}

static char	add_way(t_data *data, t_room *room, t_list **stack, t_room *cur)
{
	t_way	way;
	int		i;

	way.len = room->way_to->len + 1;
	way.ants = 0;
	way.way = malloc(sizeof(t_way *) * way.len);
	ft_memcpy(way.way, room->way_to->way, sizeof(t_way *) * room->way_to->len);
	way.way[room->way_to->len] = cur;
	if (cur->end)
	{
		i = 0;
		while (i < way.len - 1)
			way.way[i++]->used = 1;
		ft_lstpushf(&data->ways, &way, sizeof(t_way));
		return (1);
	}
	cur->checked = 1;
	ft_lstpushb(stack, &cur, sizeof(t_data *));
	cur->way_to = malloc(sizeof(t_way));
	ft_memcpy(cur->way_to, &way, sizeof(t_way));
	return (0);
}

static char	process(t_data *data, t_room *room, t_list **stack)
{
	t_list	*tmp;
	t_room	*cur;

	tmp = room->connections;
	while (tmp)
	{
		cur = *(t_room **)tmp->content;
		if (!cur->checked && !cur->used)
			if (add_way(data, room, stack, cur))
				return (1);
		tmp = tmp->next;
	}
	return (0);
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
	if (data->start->way_to)
	{
		free(way.way);
		return ;
	}
	data->start->way_to = malloc(sizeof(t_way));
	ft_memcpy(data->start->way_to, &way, sizeof(t_way));
}

char	get_ways(t_data *data)
{
	t_list	*stack;
	t_room	*cur;
	char	stop;

	if (data->start_end[0] != 1 || data->start_end[1] != 1)
	{
		ft_printf("{red}No end or start{eoc}");
		return (err(data));
	}
	stop = 0;
	while (!stop)
	{
		stop = 1;
		initialize_start(&stack, data);
		while (stack)
		{
			cur = *(t_room **)stack->content;
			ft_lstdelnode(&stack, stack);
			if (process(data, cur, &stack))
			{
				stop = 0;
				clear(data, stack);
				break ;
			}
		}
	}
	/* clear(data, stack); */
	return (0);
}
