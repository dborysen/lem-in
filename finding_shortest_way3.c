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

int		already_visited(char *naighbour, t_rooms *head_room)
{
	while (head_room != NULL && ft_strcmp(head_room->room_name, naighbour) != 0)
	{
		head_room = head_room->next_room;
	}
	if (head_room != NULL && head_room->i_was_here == YES)
		return (YES);
	return (NO);
}

void	save_naighbours_in_line(t_rooms *current_room, t_way **line,
								t_way **checked_room, t_rooms *head_room)
{
	char	*parent_room;
	t_data	*tmp_naighbour;

	parent_room = ft_strdup("");
	tmp_naighbour = NULL;
	if (current_room != NULL)
	{
		tmp_naighbour = current_room->naighbour;
		while (tmp_naighbour != NULL)
		{
			if (is_room_already_in_line(*line, tmp_naighbour->data) == NO &&
				already_visited(tmp_naighbour->data, head_room) == NO)
				new_node_in_checked_room(&(*line), tmp_naighbour->data,
										current_room->room_name);
			tmp_naighbour = tmp_naighbour->next;
		}
		if (current_room->i_was_here == NO)
			new_node_in_checked_room(&(*checked_room), current_room->room_name,
									(*line)->parent_room);
		current_room->i_was_here = YES;
	}
	free(parent_room);
}

t_rooms	*find_end_room(t_rooms *head_room)
{
	if (head_room != NULL)
	{
		while (head_room != NULL && head_room->start_or_end != END)
		{
			head_room = head_room->next_room;
		}
		return (head_room);
	}
	return (NULL);
}

int		is_end_room_in_list(t_way *line, t_rooms *head_room)
{
	t_rooms *end_room;

	end_room = find_end_room(head_room);
	if (end_room != NULL)
	{
		while (line != NULL)
		{
			if (ft_strcmp(end_room->room_name, line->room_name) == 0)
				return (YES);
			line = line->next;
		}
	}
	return (NO);
}

t_way	*find_needed_room_in_checked_list(char *end_room_name,
										t_way *checked_room)
{
	while (ft_strcmp(end_room_name, checked_room->room_name) != 0)
	{
		checked_room = checked_room->next;
	}
	return (checked_room);
}
