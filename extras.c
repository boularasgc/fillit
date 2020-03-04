/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:47:39 by cbernabo          #+#    #+#             */
/*   Updated: 2019/05/15 09:27:04 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_all_piece(t_tetri **pieces)
{
	int i;

	i = -1;
	while (pieces[++i] != NULL)
	{
		free(pieces[i]->position[0]);
		free(pieces[i]->position[1]);
		free(pieces[i]->position[2]);
		free(pieces[i]->position[3]);
		free(pieces[i]);
	}
}

void	print_map(char **map, int map_size)
{
	int i;
	int j;

	i = -1;
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

void	free_map(char **map)
{
	int i;
	int mp_sz;

	i = 0;
	mp_sz = ft_strlen(map[0]);
	while (i < mp_sz)
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
}
