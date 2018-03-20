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

#include "lem_in.h"

t_data	*return_shortest_way(t_way *checked_room, t_rooms *head_room)
{
	t_data	*shortest_way;
	t_rooms *start_room;
	t_rooms *end_room;
	t_way	*needed_room;

	shortest_way = NULL;
	start_room = find_start_room(head_room);
	end_room = find_end_room(head_room);
	needed_room = find_needed_room_in_checked_list(end_room->room_name,
														checked_room);
	while (ft_strcmp(start_room->room_name, needed_room->room_name) != 0)
	{
		new_node_in_start(&shortest_way, needed_room->room_name);
		needed_room = find_needed_room_in_checked_list(needed_room->parent_room,
														checked_room);
	}
	new_node_in_start(&shortest_way, needed_room->room_name);
	return (shortest_way);
}

void	clean_all_visited_rooms(t_rooms *head_room)
{
	while (head_room != NULL)
	{
		head_room->i_was_here = 0;
		head_room = head_room->next_room;
	}
}

void	mark_current_way(t_data *used_way, t_rooms *head_room)
{
	t_data	*tmp_way;
	t_rooms	*tmp_head;

	tmp_head = head_room;
	while (tmp_head != NULL)
	{
		tmp_way = used_way;
		while (tmp_way != NULL)
		{
			if (tmp_head->start_or_end == NO &&
				ft_strcmp(tmp_head->room_name, tmp_way->data) == 0)
				tmp_head->i_was_here = YES;
			tmp_way = tmp_way->next;
		}
		tmp_head = tmp_head->next_room;
	}
}

void	mark_used_ways(t_ways *used_ways, t_rooms **head_room)
{
	t_rooms *tmp_head;
	t_ways	*tmp_way;

	tmp_head = *head_room;
	tmp_way = used_ways;
	clean_all_visited_rooms(tmp_head);
	while (used_ways != NULL)
	{
		mark_current_way(used_ways->way, tmp_head);
		used_ways = used_ways->next;
	}
}

void	make_way_node(t_ways **possible_ways, t_data *new_way)
{
	t_ways *new;
	t_ways *tmp_ways;

	new = (t_ways*)malloc(sizeof(t_ways));
	new->way = new_way;
	new->next = NULL;
	tmp_ways = *possible_ways;
	if (tmp_ways != NULL)
	{
		while (tmp_ways->next != NULL)
			tmp_ways = tmp_ways->next;
		tmp_ways->next = new;
	}
	else
		*possible_ways = new;
}
