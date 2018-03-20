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

int		all_ways_checked(t_rooms *head_room)
{
	t_rooms	*tmp_room;
	t_rooms	*start_room;
	t_data	*start_naighbour;

	start_room = find_start_room(head_room);
	start_naighbour = NULL;
	if (start_room != NULL)
		start_naighbour = start_room->naighbour;
	if (start_naighbour == NULL)
		return (YES);
	while (start_naighbour != NULL)
	{
		tmp_room = head_room;
		while (tmp_room != NULL)
		{
			if (ft_strcmp(start_naighbour->data, tmp_room->room_name) == 0)
			{
				if (tmp_room->i_was_here == NO)
					return (NO);
			}
			tmp_room = tmp_room->next_room;
		}
		start_naighbour = start_naighbour->next;
	}
	return (YES);
}

void	find_possible_ways(t_rooms **head_room, t_ways **possible_ways)
{
	t_ways *tmp_ways;

	*possible_ways = (t_ways*)malloc(sizeof(t_ways));
	(*possible_ways)->way = NULL;
	(*possible_ways)->next = NULL;
	tmp_ways = *possible_ways;
	while (all_ways_checked(*head_room) != YES)
	{
		find_the_shortest_way(&(*head_room), &(*possible_ways), tmp_ways);
		(*possible_ways)->next = (t_ways*)malloc(sizeof(t_ways));
		(*possible_ways)->next->way = NULL;
		(*possible_ways)->next->next = NULL;
		(*possible_ways) = (*possible_ways)->next;
	}
	*possible_ways = tmp_ways;
	if (tmp_ways->way != NULL)
		del_last_node(tmp_ways);
	if ((*possible_ways)->next != NULL)
	{
		if ((*possible_ways)->next->way == NULL)
		{
			free((*possible_ways)->next);
			(*possible_ways)->next = NULL;
		}
	}
}
