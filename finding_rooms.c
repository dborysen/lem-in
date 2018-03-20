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

void	parsing_data(t_data *head_data, t_var **var, t_rooms **head_room)
{
	*var = (t_var*)malloc(sizeof(t_var));
	(*var)->ants = is_ant_num(head_data->data);
	*head_room = find_rooms(head_data);
	find_ribs(head_data, &(*head_room));
}

t_rooms	*fill_room_node(int main_rooms, char **split_room_line)
{
	t_rooms *new;

	new = (t_rooms*)malloc(sizeof(t_rooms));
	new->room_name = ft_strdup(split_room_line[0]);
	new->coordinates[0] = ft_atoi(split_room_line[1]);
	new->coordinates[1] = ft_atoi(split_room_line[2]);
	new->next_room = NULL;
	new->naighbour = NULL;
	new->start_or_end = 0;
	new->i_was_here = 0;
	if (main_rooms == START || main_rooms == END)
		new->start_or_end = main_rooms;
	return (new);
}

void	save_rooms(char *str, t_rooms **head_room, int main_rooms)
{
	int		i;
	char	**split_room_line;
	t_rooms	*new;
	t_rooms	*tmp_head;

	split_room_line = ft_strsplit(str, ' ');
	new = fill_room_node(main_rooms, split_room_line);
	tmp_head = *head_room;
	if (*head_room == NULL)
		*head_room = new;
	else
	{
		while (tmp_head->next_room != NULL)
			tmp_head = tmp_head->next_room;
		tmp_head->next_room = new;
	}
	i = 0;
	while (i < 3)
		free(split_room_line[i++]);
	free(split_room_line);
}

t_rooms	*find_rooms(t_data *head)
{
	int		main_rooms;
	t_data	*tmp;
	t_rooms	*head_room;

	head_room = NULL;
	tmp = head;
	main_rooms = 0;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->data, "##start") == 0)
			main_rooms = START;
		else if (ft_strcmp(tmp->data, "##end") == 0)
			main_rooms = END;
		if (if_room(tmp->data, ' ') == 3)
		{
			save_rooms(tmp->data, &head_room, main_rooms);
			main_rooms = 0;
		}
		tmp = tmp->next;
	}
	return (head_room);
}

void	free_array(char ***str)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *str;
	while (tmp[i] != 0)
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
}
