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

int		str_not_a_data(char *data_str, int row_num)
{
	if (ft_strlen(data_str) == 0)
		return (YES);
	else if (separating_signs(data_str) == ERROR && data_str[0] != '#')
		return (YES);
	else if (if_room(data_str, ' ') != 1 && if_room(data_str, ' ') != 3
			&& data_str[0] != '#')
		return (YES);
	else if (if_room(data_str, ' ') == 3 && right_coord(data_str) == NO
			&& data_str[0] != '#')
		return (YES);
	else if (if_room(data_str, ' ') == 1 && if_room(data_str, '-') != 2
			&& row_num != 0 && data_str[0] != '#')
		return (YES);
	return (NO);
}

int		is_any_not_valid_str(t_data *head_data)
{
	int i;

	i = 0;
	while (head_data != NULL)
	{
		if (str_not_a_data(head_data->data, i) == YES)
			return (ERROR);
		head_data = head_data->next;
		i++;
	}
	return (OK);
}

int		room_data_over(t_data *head_data)
{
	while (head_data != NULL)
	{
		if (if_room(head_data->data, '-') == 2)
			return (YES);
		head_data = head_data->next;
	}
	return (NO);
}

int		find_start_end_rooms(t_data *head_data)
{
	int	start_room;
	int	end_room;

	start_room = 0;
	end_room = 0;
	if (room_data_over(head_data) == YES)
	{
		while (head_data != NULL)
		{
			if (ft_strcmp(head_data->data, "##start") == 0
				&& head_data->next != NULL
				&& if_room(head_data->next->data, ' ') == 3)
				start_room++;
			if (ft_strcmp(head_data->data, "##end") == 0
				&& if_room(head_data->next->data, ' ') == 3)
				end_room++;
			head_data = head_data->next;
		}
		if (start_room != 1 || end_room != 1)
			return (ERROR);
	}
	return (OK);
}

int		find_room(t_data *head_data)
{
	int i;
	int room_num;
	int start_end_rooms;

	i = 0;
	room_num = 0;
	start_end_rooms = 0;
	start_end_rooms = find_start_end_rooms(head_data);
	if (room_data_over(head_data) == YES)
	{
		while (head_data != NULL)
		{
			if (if_room(head_data->data, ' ') == 3 && head_data->data[0] != '#')
			{
				if (head_data->data[0] == 'L' || head_data->data[0] == '#')
					return (ERROR);
				room_num++;
			}
			head_data = head_data->next;
			i++;
		}
		if (room_num == 0 || start_end_rooms == ERROR)
			return (ERROR);
	}
	return (OK);
}
