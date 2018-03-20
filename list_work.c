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

void	new_node(t_data **head, char *line)
{
	t_data *tmp;
	t_data *new;

	tmp = *head;
	new = (t_data*)malloc(sizeof(t_data));
	new->data = ft_strdup(line);
	new->next = NULL;
	if (*head != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}

void	new_node_in_start(t_data **head, char *line)
{
	t_data *tmp;
	t_data *new;

	tmp = *head;
	new = (t_data*)malloc(sizeof(t_data));
	new->data = ft_strdup(line);
	new->next = NULL;
	if (*head != NULL)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void	del_first_node(t_way **line)
{
	t_way *tmp_line;

	tmp_line = (*line)->next;
	ft_strdel(&(*line)->room_name);
	ft_strdel(&(*line)->parent_room);
	free(*line);
	*line = tmp_line;
}

void	del_last_node(t_ways *way)
{
	while (way->next->next != NULL)
		way = way->next;
	free(way->next);
	way->next = NULL;
}
