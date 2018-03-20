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

int		check_dublicate(char *already_in_list, char *new_one, t_data **new)
{
	if (ft_strcmp(already_in_list, new_one) == 0)
	{
		ft_strdel(&(*new)->data);
		free(*new);
		return (ERROR);
	}
	return (OK);
}

void	make_rib_node(char *str, t_data **head_naighbour)
{
	t_data *new;
	t_data *tmp;

	tmp = *head_naighbour;
	new = (t_data*)malloc(sizeof(t_data));
	new->data = ft_strdup(str);
	new->next = NULL;
	if (*head_naighbour == NULL)
		*head_naighbour = new;
	else
	{
		while (tmp->next != NULL)
		{
			if (check_dublicate(tmp->data, str, &new) == ERROR)
				return ;
			tmp = tmp->next;
		}
		if (check_dublicate(tmp->data, str, &new) == ERROR)
			return ;
		tmp->next = new;
	}
}

void	save_ribs(char *str, t_rooms **head_room)
{
	char	**split_on_words;
	int		i;
	t_rooms	*rooms;

	i = 0;
	rooms = *head_room;
	split_on_words = ft_strsplit(str, '-');
	while (rooms != NULL)
	{
		if (ft_strcmp(rooms->room_name, split_on_words[0]) == 0)
		{
			make_rib_node(split_on_words[1], &rooms->naighbour);
		}
		else if (ft_strcmp(rooms->room_name, split_on_words[1]) == 0)
		{
			make_rib_node(split_on_words[0], &rooms->naighbour);
		}
		rooms = rooms->next_room;
	}
	while (i < 2)
		free(split_on_words[i++]);
	free(split_on_words);
}

void	find_ribs(t_data *head_data, t_rooms **head_room)
{
	while (head_data != NULL)
	{
		if (if_room(head_data->data, '-') == 2)
		{
			save_ribs(head_data->data, &(*head_room));
		}
		head_data = head_data->next;
	}
}
