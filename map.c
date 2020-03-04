/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:32:29 by cbernabo          #+#    #+#             */
/*   Updated: 2019/05/14 15:26:12 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_map(int map_size)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * map_size);
	while (++i < map_size)
	{
		map[i] = ft_strnew(map_size);
		place_dots(map[i], map_size);
		map[i][map_size] = '\0';
	}
	return (map);
}

int			get_map_sz(t_tetri **lst, int qnt_pieces)
{
	int		map_size;
	t_coord tmp;

	map_size = qnt_pieces * 4;
	tmp = get_max_h_w(lst, qnt_pieces);
	map_size = minimum_map_sz(map_size, tmp);
	return (map_size);
}

void		place_dots(char *str, int map_size)
{
	int i;

	i = -1;
	while (++i < map_size)
		str[i] = '.';
}

t_coord		get_max_h_w(t_tetri **lst, int tetrim)
{
	int		i;
	t_coord res;

	i = -1;
	res.width = 0;
	res.height = 0;
	while (++i < tetrim)
	{
		if (lst[i]->coord.width > res.width)
			res.width = lst[i]->coord.width;
		if (lst[i]->coord.height > res.height)
			res.height = lst[i]->coord.height;
	}
	return (res);
}

int			minimum_map_sz(int map_size, t_coord tmp)
{
	int i;

	i = 1;
	while ((i * i) < map_size)
		i++;
	while (i < tmp.height || i < tmp.width)
		i++;
	return (i);
}
