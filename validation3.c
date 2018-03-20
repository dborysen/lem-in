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

int		is_ant_num(char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] < 48 || str[i] > 57 || str[i] == '0')
				return (-1);
			i++;
		}
		return (ft_atoi(str));
	}
	return (-1);
}

int		separating_signs(char *str)
{
	int space_num;
	int hyphen_num;
	int i;

	i = 0;
	space_num = 0;
	hyphen_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			hyphen_num++;
		else if (str[i] == ' ')
			space_num++;
		i++;
	}
	if (hyphen_num > 1 || space_num > 2)
		return (ERROR);
	return (OK);
}

int		right_coord(char *room_data)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(room_data, ' ');
	while (split[1][i] != '\0')
	{
		if (split[1][i] < 48 || split[1][i] > 57)
		{
			free_array(&split);
			return (NO);
		}
		i++;
	}
	i = 0;
	while (split[2][i] != '\0')
	{
		if (split[2][i] < 48 || split[2][i++] > 57)
		{
			free_array(&split);
			return (NO);
		}
	}
	free_array(&split);
	return (YES);
}

int		if_room(char *str, char c)
{
	char	**tmp;
	int		i;
	int		k;
	int		m;

	k = 0;
	i = 0;
	m = 0;
	if (str != NULL)
	{
		tmp = ft_strsplit(str, c);
		while (tmp[i] != 0)
			i++;
		while (tmp[k] != 0)
		{
			free(tmp[k]);
			k++;
		}
		free(tmp);
		return (i);
	}
	else
		return (ERROR);
}
