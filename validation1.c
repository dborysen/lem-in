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

int		validation(t_data *head_data)
{
	char *error_massage;

	error_massage = NULL;
	if (is_ant_num(head_data->data) == ERROR)
		error_massage = ft_strdup("\nWRONG ANTS NUMBER");
	else if (is_any_not_valid_str(head_data) == ERROR)
		error_massage = ft_strdup("\nWRONG DATA FORMAT");
	else if (if_there_is_a_room(head_data) == ERROR)
		error_massage = ft_strdup("\nWRONG ROOMS DATA");
	if (error_massage != NULL)
	{
		ft_printf("\e[1;31m \n%S ERROR%S\e[0m", L"🔥🔥🔥🔥🔥", L"🔥🔥🔥🔥🔥");
		ft_printf("\e[1;31m %s\n%S\n\e[0m\n", error_massage,
					L"🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥");
		free(error_massage);
		return (ERROR);
	}
	return (OK);
}

int		same_coord(char *room1, char *room2)
{
	char **r1_split;
	char **r2_split;

	r1_split = ft_strsplit(room1, ' ');
	r2_split = ft_strsplit(room2, ' ');
	if (if_room(room1, ' ') == 3 && if_room(room2, ' ') == 3)
	{
		if (ft_strcmp(r1_split[0], r2_split[0]) != 0 &&
			ft_strcmp(r1_split[1], r2_split[1]) == 0
			&& ft_strcmp(r1_split[2], r2_split[2]) == 0)
		{
			free_array(&r1_split);
			free_array(&r2_split);
			return (YES);
		}
	}
	free_array(&r1_split);
	free_array(&r2_split);
	return (NO);
}

int		one_name_different_coord(char *room1, char *room2)
{
	char **r1_split;
	char **r2_split;

	r1_split = ft_strsplit(room1, ' ');
	r2_split = ft_strsplit(room2, ' ');
	if (if_room(room1, ' ') == 3 && if_room(room2, ' ') == 3)
	{
		if (ft_strcmp(r1_split[0], r2_split[0]) == 0 &&
			(ft_strcmp(r1_split[1], r2_split[1]) != 0
			|| ft_strcmp(r1_split[2], r2_split[2]) != 0))
		{
			free_array(&r1_split);
			free_array(&r2_split);
			return (YES);
		}
	}
	free_array(&r1_split);
	free_array(&r2_split);
	return (NO);
}

int		is_unic_coord(t_data *head_room)
{
	t_data *tmp;

	while (head_room != NULL)
	{
		tmp = head_room;
		while (tmp != NULL)
		{
			if (same_coord(head_room->data, tmp->data) == YES ||
			one_name_different_coord(head_room->data, tmp->data) == YES)
				return (ERROR);
			tmp = tmp->next;
		}
		head_room = head_room->next;
	}
	return (OK);
}

int		if_there_is_a_room(t_data *head_data)
{
	if (find_room(head_data) == ERROR || is_unic_coord(head_data) == ERROR)
		return (ERROR);
	return (OK);
}
