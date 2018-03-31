/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:18:00 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 21:25:53 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	assign_ants(t_data *data)
{
	int		ants;
	t_list	*ways;
	t_way	*way;
	int		steps;

	ants = data->ants_am;
	steps = 1;
	while (ants > 0)
	{
		ways = data->ways;
		while (ways)
		{
			way = ways->content;
			if (way->len <= steps)
			{
				way->ants++;
				ants--;
			}
			ways = ways->next;
		}
		steps++;
	}
}
