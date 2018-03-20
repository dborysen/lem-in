/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:53:29 by dborysen          #+#    #+#             */
/*   Updated: 2018/02/20 10:53:31 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define START 1
# define END 2
# define YES 1
# define NO 0
# define ERROR -1
# define OK 0

# include "ft_printf/ft_printf.h"
# include <locale.h>

typedef struct	s_var
{
	int ants;
}				t_var;

typedef struct	s_data
{
	char			*data;
	struct s_data	*next;
}				t_data;

typedef struct	s_ants
{
	int				ant;
	t_data			*way;
	struct s_ants	*next;
}				t_ants;

typedef struct	s_ways
{
	t_data			*way;
	struct s_ways	*next;
}				t_ways;

typedef struct	s_way
{
	char			*room_name;
	char			*parent_room;
	struct s_way	*next;
}				t_way;

typedef struct	s_rooms
{
	char			*room_name;
	int				coordinates[2];
	int				start_or_end;
	int				i_was_here;
	struct s_rooms	*next_room;
	t_data			*naighbour;
}				t_rooms;

int				is_ant_num(char *str);
int				if_room(char *str, char c);
int				read_data(t_data **head_data);
int				validation(t_data *head_data);
int				same_coord(char *room1, char *room2);
int				one_name_different_coord(char *room1, char *room2);
int				is_unic_coord(t_data *head_room);
int				if_there_is_a_room(t_data *head_data);
int				str_not_a_data(char *data_str, int row_num);
int				is_any_not_valid_str(t_data *head_data);
int				room_data_over(t_data *head_data);
int				find_start_end_rooms(t_data *head_data);
int				find_room(t_data *head_data);
int				is_ant_num(char *str);
int				separating_signs(char *str);
int				right_coord(char *room_data);
int				if_room(char *str, char c);
void			free_list(t_data *head);
void			free_naighbour(t_data *head);
void			free_room(t_rooms **head_room);
void			free_way(t_way *shortest_way);
void			free_all(t_data *head_data, t_rooms *head_room,
						t_var *var, t_ways *possible_ways);
void			new_node(t_data **head, char *line);
void			new_node_in_start(t_data **head, char *line);
void			del_first_node(t_way **line);
void			del_last_node(t_ways *way);
void			make_rib_node(char *str, t_data **head_naighbour);
void			save_ribs(char *str, t_rooms **head_room);
void			find_ribs(t_data *head_data, t_rooms **head_room);
void			parsing_data(t_data *head_data, t_var **var,
							t_rooms **head_room);
t_rooms			*fill_room_node(int main_rooms, char **split_room_line);
void			save_rooms(char *str, t_rooms **head_room, int main_rooms);
void			free_array(char ***str);
void			find_possible_ways(t_rooms **head_room, t_ways **possible_ways);
void			del_one_step_way(t_rooms *start_room, t_rooms *end_room);
t_data			*return_one_step_way(t_rooms **head_room);
int				one_step_way_exist(t_rooms *head_room);
int				all_ways_checked(t_rooms *head_room);
int				heck_dublicate(char *already_in_list, char *new_one,
								t_data **new);
void			mark_dead_end_way(t_way *checked_room, t_rooms **head_room);
void			find_the_shortest_way(t_rooms **head_room, t_ways **current_way,
									t_ways *written_ways);
t_data			*return_shortest_way(t_way *checked_room, t_rooms *head_room);
t_rooms			*find_rooms(t_data *head);
void			clean_all_visited_rooms(t_rooms *head_room);
void			mark_current_way(t_data *used_way, t_rooms *head_room);
void			mark_used_ways(t_ways *used_ways, t_rooms **head_room);
void			make_way_node(t_ways **possible_ways, t_data *new_way);
int				already_visited(char *naighbour, t_rooms *head_room);
void			save_naighbours_in_line(t_rooms *current_room, t_way **line,
								t_way **checked_room, t_rooms *head_room);
t_rooms			*find_end_room(t_rooms *head_room);
int				s_end_room_in_list(t_way *line, t_rooms *head_room);
t_way			*find_needed_room_in_checked_list(char *end_room_name,
												t_way *checked_room);
t_rooms			*find_start_room(t_rooms *head_room);
t_rooms			*get_room_from_line(t_rooms *current_room, t_way *line);
void			new_node_in_checked_room(t_way **way_list, char *room_name,
										char *parent_room);
int				is_room_already_in_line(t_way *line, char *room);
t_ants			*find_ant(t_ants *ants_list, int i);
int				if_room_empty(t_ants *ants_list, char *room);
void			output_ants_move(t_ants **ants_list, int ant_num);
void			output_way(t_ants *ants_list, int ant_num);
void			output(t_data *data_from_file, t_data *shortest_way, int ants);
void			output_data(t_data *data_from_file, t_data *shortest_way);
void			make_ants_node(t_ants **ants_head, t_data *shortest_way,
								int ant_num);
void			free_ants_list(t_ants *ants_list);
void			make_ants_with_way_list(t_ants **ants_list,
										t_data *shortest_way, int ants);
int				count_rooms(t_data *rooms);
int				is_end_room_in_list(t_way *line, t_rooms *head_room);
void			print_move(char *room, int ant_num);

#endif
