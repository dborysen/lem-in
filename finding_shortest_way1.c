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

void	del_one_step_way(t_rooms *start_room, t_rooms *end_room)
{
	t_data *naighbour;
	t_data *tmp;

	naighbour = start_room->naighbour;
	if (ft_strcmp(naighbour->data, end_room->room_name) != 0)
	{
		while (ft_strcmp(naighbour->next->data, end_room->room_name) != 0)
			naighbour = naighbour->next;
		tmp = naighbour->next->next;
		ft_strdel(&naighbour->next->data);
		free(naighbour->next);
		naighbour->next = tmp;
	}
	else
	{
		tmp = start_room->naighbour;
		start_room->naighbour = start_room->naighbour->next;
		ft_strdel(&tmp->data);
		free(tmp);
		tmp = NULL;
	}
}

t_data	*return_one_step_way(t_rooms **head_room)
{
	t_rooms *end_room;
	t_rooms *start_room;
	t_data	*tmp_naighbour;
	t_data	*one_step_way;

	one_step_way = NULL;
	end_room = find_end_room(*head_room);
	start_room = find_start_room(*head_room);
	tmp_naighbour = start_room->naighbour;
	while (tmp_naighbour != NULL)
	{
		if (ft_strcmp(end_room->room_name, tmp_naighbour->data) == 0)
		{
			del_one_step_way(start_room, end_room);
			new_node(&one_step_way, start_room->room_name);
			new_node(&one_step_way, end_room->room_name);
			break ;
		}
		tmp_naighbour = tmp_naighbour->next;
	}
	return (one_step_way);
}

int		one_step_way_exist(t_rooms *head_room)
{
	t_data	*tmp_naighbour;
	t_rooms	*end_room;
	t_rooms	*start_room;

	end_room = find_end_room(head_room);
	start_room = find_start_room(head_room);
	tmp_naighbour = start_room->naighbour;
	if (end_room != NULL)
	{
		while (tmp_naighbour != NULL)
		{
			if (ft_strcmp(end_room->room_name, tmp_naighbour->data) == 0)
				return (YES);
			tmp_naighbour = tmp_naighbour->next;
		}
	}
	return (NO);
}

void	mark_dead_end_way(t_way *checked_room, t_rooms **head_room)
{
	t_rooms	*tmp_head;
	t_way	*tmp_checked_room;

	tmp_head = *head_room;
	while (tmp_head != NULL)
	{
		tmp_checked_room = checked_room;
		while (tmp_checked_room != NULL)
		{
			if (ft_strcmp(tmp_head->room_name,
					tmp_checked_room->room_name) == 0)
				tmp_head->i_was_here = 1;
			tmp_checked_room = tmp_checked_room->next;
		}
		tmp_head = tmp_head->next_room;
	}
}

void	find_the_shortest_way(t_rooms **hd, t_ways **current_way,
								t_ways *written_ways)
{
	t_way	*line;
	t_way	*ch;

	line = NULL;
	ch = NULL;
	if (one_step_way_exist(*hd) == YES)
	{
		(*current_way)->way = return_one_step_way(&(*hd));
		return ;
	}
	if (line == NULL)
		save_naighbours_in_line(find_start_room(*hd), &line, &ch, *hd);
	while (line != NULL)
	{
		save_naighbours_in_line(get_room_from_line(*hd, line), &line, &ch, *hd);
		del_first_node(&line);
	}
	if (is_end_room_in_list(ch, *hd) == YES)
	{
		(*current_way)->way = return_shortest_way(ch, *hd);
		mark_used_ways(written_ways, &(*hd));
	}
	else
		mark_dead_end_way(ch, &(*hd));
	free_way(ch);
}
