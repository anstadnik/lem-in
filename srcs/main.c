/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:07:26 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/29 18:01:00 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_room	*rooms;
	int		ants_number;

	rooms = NULL;
	ants_number = 0;
	if (get_input(&rooms, &ants_number) == -1)
		return (1);
	/* algo(); */
	return (0);
}
