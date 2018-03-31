/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:07:26 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 14:26:13 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (get_input(&data) == -1)
		return (-1);
	print_input(&data);
	/* ft_printf("{magenta}BEFORE GET_WAYS\n{eoc}"); */
	/* print_data(data); */
	if (get_ways(&data) == -1)
		return (-1);
	/* ft_printf("{magenta}AFTER GET_WAYS\n{eoc}"); */
	/* print_data(data); */

	/* algo(); */
	return (0);
}
