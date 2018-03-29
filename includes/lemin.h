/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:25:07 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/29 17:15:20 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

typedef struct s_room	t_room;
typedef struct s_way	t_way;

struct					s_room
{
	int		num;
	char	*name;
	int		coords[2];
	int		*connections;
	int		*way;
	char	start;
	char	second;
	char	checked;
};

struct					s_way
{
	int		*way;
	int		ants;
	int		len;
};

struct					s_ant
{
	int		num;
	int		*way;
};

char	get_input(t_room **room, int *ants_number);

#endif
