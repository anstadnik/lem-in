/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:07:26 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 18:51:08 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (get_input(&data) == -1)
		return (-1);
	if (get_ways(&data) == -1)
		return (-1);
	/* print_data(data); */
	print_input(&data);
	assign_ants(&data);
	output(&data);
	/* sleep(3); */
	return (0);
}
