/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:16:53 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 12:53:53 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del_room(void *ptr)
{
	t_room	*room;

	room = ptr;
	if (room->connections)
		ft_lstdel(&room->connections, &free);
	if (room->name)
		free(room->name);
	if (room->way_to)
		free(room->way_to);
	free(room);
}

char	err(t_data *data)
{
	//check this for leaks
	ft_printf("{red}Error{eoc}\n");
	if (data->rooms)
		ft_lstdel(&data->rooms, &del_room);
	if (data->input)
		ft_lstdel(&data->input, &free);
	return (-1);
}
