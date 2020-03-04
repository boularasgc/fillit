/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:24:05 by cbernabo          #+#    #+#             */
/*   Updated: 2019/05/14 15:36:36 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri			**main_val(int fd, int *qnt_pieces)
{
	int			x;
	char		*p_buff;
	static char buff[MAX_FL_SZ];

	x = read(fd, buff, MAX_FL_SZ);
	if (x > MAX_FL_SZ || x <= MIN_FL_SZ)
		return (NULL);
	buff[x] = '\0';
	if (x < MAX_FL_SZ && ((x + 1) % BLK_SZ == 0))
		*qnt_pieces = (x + 1) / BLK_SZ;
	p_buff = &buff[0];
	if (*qnt_pieces > 0 && val_tetblock(p_buff, *qnt_pieces))
		return (init_all_pieces(p_buff, *qnt_pieces));
	return (NULL);
}

int				val_tetblock(char *p_buff, int tetrim)
{
	int			i;
	int			j;

	j = 0;
	i = -1;
	while (++i < tetrim && ((valid_piece_chars(p_buff + j) &&
	(valid_tetrim(p_buff + j)))))
		j += 21;
	if (i == tetrim)
		return (1);
	return (0);
}

int				valid_piece_chars(char *p_buff)
{
	int			i;
	int			hashes;
	char		c;

	hashes = 0;
	i = -1;
	while (++i < 20 && (c = p_buff[i]) != '\0')
	{
		if (!is_valid_tetris_char(c))
			return (0);
		else if ((i + 1) % 5 == 0 && c != '\n')
			return (0);
		if (c == '#')
			hashes++;
	}
	c = p_buff[i];
	if (c != '\n' && c != '\0')
		return (0);
	if (hashes == 4)
		return (1);
	return (0);
}

int				is_valid_tetris_char(char c)
{
	return (c == '\n' || c == '#' || c == '.');
}

int				valid_tetrim(char *p_buff)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (++i < 19)
	{
		if (p_buff[i] == '#')
		{
			if (i + 1 <= 18 && p_buff[i + 1] == '#')
				count++;
			if (i + 5 <= 18 && p_buff[i + 5] == '#')
				count++;
			if (i - 1 >= 0 && p_buff[i - 1] == '#')
				count++;
			if (i - 5 >= 0 && p_buff[i - 5] == '#')
				count++;
		}
	}
	if (count == 6 || count == 8)
		return (count);
	return (0);
}
