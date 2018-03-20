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

t_ants	*find_ant(t_ants *ants_list, int i)
{
	while (ants_list->ant != i && ants_list != NULL)
	{
		ants_list = ants_list->next;
	}
	return (ants_list);
}

int		if_room_empty(t_ants *ants_list, char *room)
{
	while (ants_list != NULL)
	{
		if (ants_list->way->next != NULL &&
			ft_strcmp(ants_list->way->data, room) == 0)
			return (NO);
		ants_list = ants_list->next;
	}
	return (YES);
}

void	output_ants_move(t_ants **ants_list, int ant_num)
{
	int		i;
	t_ants	*current_ant;

	i = 1;
	while (i <= ant_num)
	{
		current_ant = find_ant(*ants_list, i);
		if (current_ant->way->next != NULL &&
			if_room_empty(*ants_list, current_ant->way->next->data) == YES)
		{
			print_move(current_ant->way->next->data, i);
			current_ant->way = current_ant->way->next;
		}
		i++;
	}
}

void	output_way(t_ants *ants_list, int ant_num)
{
	int i;
	int room_num;

	i = 1;
	room_num = count_rooms(ants_list->way);
	while (i <= ant_num + room_num - 1)
	{
		output_ants_move(&ants_list, ant_num);
		ft_putendl("");
		i++;
	}
}

void	output(t_data *data_from_file, t_data *shortest_way, int ants)
{
	t_ants *ants_list;

	(void)ants;
	ants_list = NULL;
	output_data(data_from_file, shortest_way);
	make_ants_with_way_list(&ants_list, shortest_way, ants);
	output_way(ants_list, ants);
	free_ants_list(ants_list);
}
