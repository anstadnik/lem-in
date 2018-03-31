/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:07:26 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 12:53:23 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_rooms(t_list *tmp)
{
	t_room	*tmp2;
	t_list	*tmp3;
	int		c;

	while (tmp)
	{
		tmp2 = tmp->content;
		ft_printf("{yellow}num = %d, name = %s, coords = [%d, %d]", tmp2->num,
				tmp2->name, tmp2->coords[0], tmp2->coords[1]);
		if (tmp2->start)
			ft_printf(", start");
		if (tmp2->end)
			ft_printf(", end");
		ft_printf("\n{eoc}");
		ft_printf("{green}Way_len = %d\n{eoc}", tmp2->way_len);
		c = 0;
		ft_printf("{green}Way to this room:\n{eoc}");
		while (c < tmp2->way_len)
		{
			ft_printf("{yellow}%d{eoc}", tmp2->way_to[c++]);
			if (c != tmp2->way_len)
				ft_printf("{yellow}-{eoc}");
		}
		ft_printf("\n");
		tmp3 = tmp2->connections;
		ft_printf("{green}Connections:\n{eoc}");
		while (tmp3)
		{
			tmp2 = *(t_room **)tmp3->content;
			ft_printf("{yellow}%s\n{eoc}", tmp2->name);
			tmp3 = tmp3->next;
		}
		tmp = tmp->next;
		ft_printf("\n\n");
	}

}

void	print_data(t_data data)
{
	t_list	*tmp;
	int		c;
	t_way	*tmp4;

	ft_printf("{blue}\n################################################\n{eoc}");
	ft_printf("{yellow}MY DATA:\n\n{eoc}");
	ft_printf("{cyan}ROOMS:\n\n{eoc}");
	print_rooms(data.rooms);
	ft_printf("{cyan}WAYS:\n\n{eoc}");
	tmp = data.ways;
	while (tmp)
	{
		tmp4 = tmp->content;
		ft_printf("{yellow}len = %d, ants = %d\n{eoc}", tmp4->len, tmp4->ants);
		ft_printf("{green}Ways:\n{eoc}");
		c = 0;
		while (c < tmp4->len)
		{
			ft_printf("{yellow}%d{eoc}", tmp4->way[c++]);
			if (c != tmp4->len)
				ft_printf("{yellow}-{eoc}");
		}
		ft_printf("\n\n");
		tmp = tmp->next;
	}
	ft_printf("{green}starts amount = %d, ends amount = %d\n{eoc}", data.start_end[0], data.start_end[1]);
	ft_printf("{green}rooms_amount = %d\n\n{eoc}", data.rooms_amount);
	ft_printf("{blue}################################################\n\n{eoc}");
}

static void	print_input(t_data *data)
{
	t_list	*lst;

	lst = data->input;
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	ft_lstdel(&data->input, &free);
	ft_memdel((void **)&data->input);
}

int	main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (get_input(&data) == -1)
		return (-1);
	print_input(&data);
	ft_printf("{magenta}BEFORE GET_WAYS\n{eoc}");
	print_data(data);
	if (get_ways(&data) == -1)
		return (-1);
	ft_printf("{magenta}AFTER GET_WAYS\n{eoc}");
	print_data(data);

	/* algo(); */
	return (0);
}
