/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:07:26 by astadnik          #+#    #+#             */
/*   Updated: 2018/04/01 13:30:07 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 1 && !(ac == 2 && !ft_strcmp("-d", av[1])))
	{
		ft_printf("{Wrong parameter");
		return (1);
	}
	ft_bzero(&data, sizeof(t_data));
	if (get_input(&data) == -1 || get_ways(&data) == -1)
		return (1);
	if (data.ways)
		print_input(&data);
	else
	{
		ft_printf("{red}No way from start to end\n{eoc}");
		return (1);
	}
	if (ac == 2)
		print_data(data);
	assign_ants(&data);
	output(&data);
	return (0);
}
