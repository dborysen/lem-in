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

void	print_move(char *room, int ant_num)
{
	ft_putchar('L');
	ft_putnbr(ant_num);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

int		main(void)
{
	t_data	*data_from_file;
	t_rooms *head_room;
	t_ways	*possible_ways;
	t_var	*var;

	data_from_file = NULL;
	possible_ways = NULL;
	setlocale(LC_ALL, "");
	read_data(&data_from_file);
	parsing_data(data_from_file, &var, &head_room);
	find_possible_ways(&head_room, &possible_ways);
	if (possible_ways->way == NULL)
		ft_printf("\e[1;31m \n%S ERROR%S\nNO POSSIBLE WAYS\n%S\n\e[0m\n",
			L"🔥🔥🔥🔥🔥", L"🔥🔥🔥🔥🔥", L"🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥");
	else
		output(data_from_file, possible_ways->way, var->ants);
	free_all(data_from_file, head_room, var, possible_ways);
	return (0);
}
