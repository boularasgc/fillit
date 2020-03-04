/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:46:09 by cbernabo          #+#    #+#             */
/*   Updated: 2019/05/14 15:27:52 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		**init_all_pieces(char *p_buff, int tetrim)
{
	int		i;
	int		j;
	t_tetri	**pieces;

	pieces = malloc(sizeof(*pieces) * (tetrim));
	i = -1;
	j = 0;
	while (++i < tetrim)
	{
		pieces[i] = init_piece(&p_buff[j], i);
		j += 21;
	}
	pieces[tetrim] = NULL;
	return (pieces);
}

t_tetri		*init_piece(char *p_buff, int alpha)
{
	int		i;
	int		small;
	int		big;
	t_tetri *tmp;

	tmp = malloc(sizeof(t_tetri));
	relative_coordenates_of_piece(p_buff, tmp);
	i = -1;
	big = tmp->position[0][1];
	small = tmp->position[0][1];
	while (++i < 4)
	{
		if (big < tmp->position[i][1])
			big = tmp->position[i][1];
		if (small > tmp->position[i][1])
			small = tmp->position[i][1];
	}
	tmp->coord.width = big - small + 1;
	tmp->coord.height = tmp->position[3][0] + 1;
	tmp->letter = alpha + 'A';
	return (tmp);
}

void		relative_coordenates_of_piece(char *p_buff, t_tetri *piece)
{
	int		line;
	int		column;
	t_coord first;
	int		hashes;

	line = -1;
	hashes = 0;
	first.width = 0;
	first.height = 0;
	while (++line < 4 && hashes < 4)
	{
		column = -1;
		while (++column < 5)
			if (p_buff[(line * 5) + column] == '#')
			{
				if (hashes == 0)
				{
					first.height = line;
					first.width = column;
				}
				piece->position[hashes][0] = line - first.height;
				piece->position[hashes++][1] = column - first.width;
			}
	}
}
