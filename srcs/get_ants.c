/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:41:30 by astadnik          #+#    #+#             */
/*   Updated: 2018/04/01 13:49:40 by astadnik         ###   ########.fr       */
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

static char	check_str(char *str, t_data *data)
{
	size_t	i;

	if (*str == '#')
	{
		if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
			return (error(&str));
	}
	else if (ft_isinteger(str) == 0)
	{
		data->ants_am = ft_atoi(str);
		i = 0;
		while (str[i])
			if (!ft_isdigit(str[i++]))
				return (error(&str));
		return (data->ants_am ? 0 : error(&str));
	}
	else
		return (error(&str));
	return (2);
}

char		get_ants(t_data *data)
{
	char	*str;
	char	ret;

	while (42)
	{
		if (get_next_line(0, &str) != 1)
			return (error(&str));
		ft_lstpushb(&data->input, str, ft_strlen(str) + 1);
		if ((ret = check_str(str, data)) != 2)
		{
			ft_memdel((void **)&str);
			return (ret);
		}
		ft_memdel((void **)&str);
	}
}
