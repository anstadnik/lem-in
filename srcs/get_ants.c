/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:41:30 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 21:35:18 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	error(char **str)
{
	ft_printf("{red}Error with ants\n{eoc}");
	if (*str)
		ft_memdel((void **)str);
	return (-1);
}

char		get_ants(t_data *data)
{
	char	*str;

	while (42)
	{
		if (get_next_line(0, &str) != 1)
			return (-1);
		ft_lstpushb(&data->input, str, ft_strlen(str) + 1);
		if (*str == '#')
		{
			if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
				return (error(&str));
		}
		else if (ft_isinteger(str) == 0)
		{
			data->ants_am = ft_atoi(str);
			return (0);
		}
		else
			return (error(&str));
		ft_memdel((void **)&str);
	}
}
