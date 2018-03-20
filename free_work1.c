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

void	free_list(t_data *head)
{
	t_data *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		ft_strdel(&tmp->data);
		free(tmp);
	}
}

void	free_naighbour(t_data *head)
{
	t_data *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->data);
		free(tmp);
	}
}

void	free_room(t_rooms **head_room)
{
	t_rooms *tmp;
	t_rooms *tmp1;

	tmp = *head_room;
	while (tmp != NULL)
	{
		tmp1 = tmp->next_room;
		ft_strdel(&tmp->room_name);
		free_naighbour(tmp->naighbour);
		free(tmp);
		tmp = tmp1;
	}
}

void	free_way(t_way *shortest_way)
{
	t_way *tmp;

	while (shortest_way != NULL)
	{
		tmp = shortest_way;
		shortest_way = shortest_way->next;
		ft_strdel(&tmp->room_name);
		ft_strdel(&tmp->parent_room);
		free(tmp);
	}
}

void	free_all(t_data *head_data, t_rooms *head_room,
				t_var *var, t_ways *possible_ways)
{
	t_ways *tmp;

	free_list(head_data);
	free_room(&head_room);
	free(var);
	tmp = possible_ways;
	while (possible_ways != NULL)
	{
		tmp = possible_ways;
		possible_ways = possible_ways->next;
		free_list(tmp->way);
		free(tmp);
	}
}
