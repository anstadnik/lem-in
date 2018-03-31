/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:14:37 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 20:26:15 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	get_rooms_and_links(t_data *data)
{
	char	*str;
	char	state;
	int		ret;

	state = 0;
	while (42)
	{
		if ((ret = get_next_line(0, &str)) != 1)
			return (ret);
		ft_lstpushb(&data->input, str, ft_strlen(str) + 1);
		if (state == 0)
			state = get_room(str, data);
		else if (state == 1)
			state = get_link(str, data);
		else if (state == 2 || state == -1)
		{
			free(str);
			return (state == -1 ? -1 : 0);
		}
		free(str);
	}
}

char	get_input(t_data *data)
{
	int		state;

	data->rooms = NULL;
	state = 0;
	if (get_ants(data) == -1)
		return (err(data));
	if (get_rooms_and_links(data) == -1)
		return (err(data));
	return (0);
}
