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

t_rooms	*find_start_room(t_rooms *head_room)
{
	if (head_room != NULL)
	{
		while (head_room->start_or_end != START)
		{
			head_room = head_room->next_room;
			if (head_room == NULL)
				return (NULL);
		}
		return (head_room);
	}
	return (NULL);
}

t_rooms	*get_room_from_line(t_rooms *current_room, t_way *line)
{
	while (ft_strcmp(line->room_name, current_room->room_name) != 0)
	{
		current_room = current_room->next_room;
		if (current_room == NULL)
			return (NULL);
	}
	return (current_room);
}

void	new_node_in_checked_room(t_way **way_list, char *room_name,
								char *parent_room)
{
	t_way *tmp_list;
	t_way *new;

	tmp_list = *way_list;
	new = (t_way*)malloc(sizeof(t_way));
	new->room_name = ft_strdup(room_name);
	new->parent_room = ft_strdup(parent_room);
	new->next = NULL;
	if (tmp_list == NULL)
		*way_list = new;
	else
	{
		while (tmp_list->next != NULL)
			tmp_list = tmp_list->next;
		tmp_list->next = new;
	}
}

int		is_room_already_in_line(t_way *line, char *room)
{
	while (line != NULL)
	{
		if (ft_strcmp(line->room_name, room) == 0)
			return (YES);
		line = line->next;
	}
	return (NO);
}
