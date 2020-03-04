/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:46:14 by cbernabo          #+#    #+#             */
/*   Updated: 2019/05/14 16:55:56 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>

# define MAX_FL_SZ 546
# define MIN_FL_SZ 19
# define BLK_SZ 21

typedef struct	s_coord
{
	int	height;
	int	width;
}				t_coord;

typedef	struct	s_tetri
{
	int			position[4][2];
	t_coord		coord;
	char		letter;
}				t_tetri;

int				main(int cnt, char **argv);
t_tetri			**main_val(int fd, int *qnt_pieces);
int				val_tetblock(char *p_buff, int tetrim);
int				valid_piece_chars(char *p_buff);
int				is_valid_tetris_char(char c);
int				valid_tetrim(char *p_buff);
t_tetri			**init_all_pieces(char *p_buff, int tetrim);
t_tetri			*init_piece(char *p_buff, int alpha);
void			relative_coordenates_of_piece(char *p_buff, t_tetri *piece);
char			**create_map(int map_size);
void			place_dots(char *str, int map_size);
int				get_map_sz(t_tetri **lst, int tetrim);
t_coord			get_max_h_w(t_tetri **lst, int tetrim);
void			solve_map(t_tetri **pieces, int *qnt_pieces);
int				minimum_map_sz(int map_size, t_coord tmp);
void			print_map(char **map, int map_size);
int				solver(char **map, t_tetri **pieces, int map_sz);
int				val_position(char **map, int i, int j, t_tetri *t);
void			put_tetri(char **map, int i, int j, t_tetri *t);
void			rm_tetri(char **map, int i, int j, t_tetri *t);
void			free_map(char **map);

#endif
