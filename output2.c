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

void	output_data(t_data *data_from_file, t_data *shortest_way)
{
	while (data_from_file != NULL)
	{
		ft_putendl(data_from_file->data);
		data_from_file = data_from_file->next;
	}
	ft_putendl("");
	while (shortest_way->next != NULL)
	{
		ft_putstr(shortest_way->data);
		ft_printf(" %C ", L'👉');
		shortest_way = shortest_way->next;
	}
	ft_putstr(shortest_way->data);
	ft_printf(" %C\n", L'🏁');
}

void	make_ants_node(t_ants **ants_head, t_data *shortest_way, int ant_num)
{
	t_ants *new;
	t_ants *tmp_head;

	tmp_head = *ants_head;
	new = (t_ants*)malloc(sizeof(t_ants));
	new->ant = ant_num;
	new->way = shortest_way;
	new->next = NULL;
	if (*ants_head != NULL)
	{
		while (tmp_head->next != NULL)
			tmp_head = tmp_head->next;
		tmp_head->next = new;
	}
	else
		*ants_head = new;
}

void	free_ants_list(t_ants *ants_list)
{
	t_ants *tmp;

	while (ants_list->next != NULL)
	{
		tmp = ants_list;
		ants_list = ants_list->next;
		free(tmp);
	}
	free(ants_list);
}

void	make_ants_with_way_list(t_ants **ants_list, t_data *shortest_way,
								int ants)
{
	int i;

	i = 1;
	while (i <= ants)
	{
		make_ants_node(&(*ants_list), shortest_way, i);
		i++;
	}
}

int		count_rooms(t_data *rooms)
{
	int i;

	i = 0;
	while (rooms != NULL)
	{
		rooms = rooms->next;
		i++;
	}
	return (i - 1);
}
