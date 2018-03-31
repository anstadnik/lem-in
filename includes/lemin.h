/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:25:07 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 12:53:04 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

typedef struct s_data	t_data;
typedef struct s_room	t_room;
typedef struct s_way	t_way;
typedef struct s_ant	t_ant;

struct					s_data
{
	t_list				*rooms;
	t_room				*start;
	t_list				*input;
	int					tmp;
	int					rooms_amount;
	char				start_end[2];
	int					ants_amount;
	t_list				*ways;
	t_list				*ants;
};

struct					s_room
{
	int		num;
	char	*name;
	int		coords[2];
	t_list	*connections;
	int		*way_to;
	int		way_len;
	char	start;
	char	end;
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

char	get_input(t_data *data);
char	get_ants(t_data *data);
char	get_room(char *str, t_data *data);
char	get_link(char *str, t_data *data);
char	get_ways(t_data *data);

char	err(t_data *data);
void	print_data(t_data data);
void	del_room(void *ptr);

#endif
