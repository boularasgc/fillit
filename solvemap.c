/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:42:37 by cbernabo          #+#    #+#             */
/*   Updated: 2019/05/14 16:56:25 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			solve_map(t_tetri **pieces, int *qnt_pieces)
{
	static int	map_sz;
	char		**map;

	map_sz = get_map_sz(pieces, *qnt_pieces);
	map = create_map(map_sz);
	while (solver(map, pieces, map_sz) == 0)
	{
		map_sz++;
		ft_memdel((void **)map);
		map = create_map(map_sz);
	}
	print_map(map, map_sz);
	free_map(map);
}

int				solver(char **map, t_tetri **pieces, int map_sz)
{
	int			i;
	int			j;

	if (*pieces == NULL)
		return (1);
	i = -1;
	while (++i < map_sz)
	{
		j = -1;
		while (++j < map_sz)
			if (val_position(map, i, j, *pieces))
			{
				put_tetri(map, i, j, *pieces);
				if (solver(map, ++pieces, map_sz))
					return (1);
				else
				{
					--pieces;
					rm_tetri(map, i, j, *pieces);
				}
			}
	}
	return (0);
}

void			put_tetri(char **map, int i, int j, t_tetri *t)
{
	map[i + t->position[0][0]][j + t->position[0][1]] = t->letter;
	map[i + t->position[1][0]][j + t->position[1][1]] = t->letter;
	map[i + t->position[2][0]][j + t->position[2][1]] = t->letter;
	map[i + t->position[3][0]][j + t->position[3][1]] = t->letter;
}

void			rm_tetri(char **map, int i, int j, t_tetri *t)
{
	map[i + t->position[0][0]][j + t->position[0][1]] = '.';
	map[i + t->position[1][0]][j + t->position[1][1]] = '.';
	map[i + t->position[2][0]][j + t->position[2][1]] = '.';
	map[i + t->position[3][0]][j + t->position[3][1]] = '.';
}

int				val_position(char **map, int i, int j, t_tetri *t)
{
	int			x;
	int			curr_i;
	int			curr_j;
	int			mp_sz;

	mp_sz = ft_strlen(map[0]);
	x = -1;
	if (!t || t == NULL || !t->coord.height || !t->coord.width || !t->letter)
		return (0);
	while (++x < 4)
	{
		curr_i = t->position[x][0];
		curr_j = t->position[x][1];
		if (i + curr_i < 0 || i + curr_i >= mp_sz)
			return (0);
		if (j + curr_j < 0 || j + curr_j >= mp_sz)
			return (0);
		if (map[i + curr_i][j + curr_j] != '.')
			return (0);
	}
	return (1);
}
