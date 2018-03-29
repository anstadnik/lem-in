/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:14:37 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/29 19:44:03 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	del(void *ptr)
{
	t_room	*room;

	room = ptr;
	if (room->name)
		free(room->name);
	if (room->way)
		free(room->way);
}

static char	err(t_list **rooms)
{
	//check this for leaks
	ft_printf("{red}Error{eoc}\n");
	if (*rooms)
		ft_lstdel(rooms, &del);
	return (-1);
}

static char	get_ants_number(int *ants_number)
{
	char	*str;
	char	ret;

	ret = 1;
	while (42)
	{
		if (get_next_line(0, &str) != 1)
			return (-1);
		if (*str == '#')
		{
			if (!ft_strncmp(str, "##start", 7) || !ft_strncmp(str, "##end", 5))
				ret = -1;
		}
		else
			if (ft_isinteger(str) == 0)
				ret = (*ants_number = ft_atoi(str)) ? 0 : -1;
			else
				ret = -1;
		free(str);
		if (ret != 1)
			return (ret);
	}
}

char	get_input(t_list **rooms, int *ants_number)
{
	int		state;

	*rooms = NULL;
	state = 0;
	if (get_ants_number(ants_number) == -1)
		return (err(rooms));
	if (get_rooms(rooms) == -1)
		return (err(rooms));
	return (0);
}
