/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:25:07 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/31 21:24:52 by astadnik         ###   ########.fr       */
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
	int					rooms_am;
	int					links_am;
	char				start_end[2];
	int					ants_am;
	t_list				*ways;
	t_list				*ants;
};

struct					s_room
{
	char				*name;
	int					coords[2];
	t_list				*connections;
	t_way				*way_to;
	char				start;
	char				end;
	char				checked;
	char				used;
	char				visited_from_start;
};

struct					s_way
{
	t_room				**way;
	int					ants;
	int					len;
};

struct					s_ant
{
	char				finished;
	int					num;
	int					cur_step;
	t_way				*way;
};

char					get_input(t_data *data);
char					get_ants(t_data *data);
char					get_room(char *str, t_data *data);
char					get_link(char *str, t_data *data);
char					get_ways(t_data *data);
void					assign_ants(t_data *data);
void					output(t_data *data);

char					err(t_data *data);
void					print_data(t_data data);
void					print_input(t_data *data);
void					del_room(void *ptr);

#endif
