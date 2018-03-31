/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:28:53 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 21:27:46 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	move_ants(t_data *data)
{
	t_list	*ants;
	t_ant	*ant;
	char	first;

	ants = data->ants;
	first = 1;
	while (ants)
	{
		ant = ants->content;
		if (ant->finished)
		{
			ants = ants->next;
			continue ;
		}
		if (first)
			first--;
		else
			ft_printf(" ");
		ft_printf("L%d-%s ", ant->num, ant->way->way[ant->cur_step++]->name);
		if (ant->cur_step == ant->way->len)
			ant->finished = 1;
		ants = ants->next;
	}
}

static void	add_ants(t_data *data)
{
	t_way		*way;
	t_list		*ways;
	static int	counter = 0;
	t_ant		ant;

	ways = data->ways;
	while (ways && data->ants_am)
	{
		way = ways->content;
		data->ants_am--;
		ant.num = ++counter;
		ant.cur_step = 1;
		ant.finished = 0;
		ant.way = way;
		ft_lstpushb(&data->ants, &ant, sizeof(t_ant));
		ways = ways->next;
	}
}

static char	check_end(t_data *data)
{
	t_list	*ants;
	t_ant	*ant;
	char	first;

	ants = data->ants;
	first = 1;
	while (ants)
	{
		ant = ants->content;
		if (!ant->finished)
			return (1);
		ants = ants->next;
	}
	return (data->ants_am != 0);
}

void		output(t_data *data)
{
	add_ants(data);
	while (check_end(data))
	{
		move_ants(data);
		add_ants(data);
		ft_printf("\n");
	}
}
