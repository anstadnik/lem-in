/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:41:30 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 18:55:39 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	get_ants(t_data *data)
{
	char	*str;
	char	ret;

	ret = 1;
	while (ret == 1)
	{
		if (get_next_line(0, &str) != 1)
			return (-1);
		ft_lstpushb(&data->input, str, ft_strlen(str) + 1);
		if (*str == '#')
		{
			if (!ft_strncmp(str, "##start", 7) || !ft_strncmp(str, "##end", 5))
				ret = -1;
		}
		else
			if (ft_isinteger(str) == 0)
			{
				data->ants_amount = ft_atoi(str);
				ret = 0;
			}
			else
				ret = -1;
		free(str);
	}
	if (ret == -1 || !data->ants_amount)
		ft_printf("{red}Error with ants\n{eoc}");
	return (ret != -1 && data->ants_amount ? 0 : -1);
}
