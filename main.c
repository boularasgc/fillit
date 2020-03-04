/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:45:43 by mboulara          #+#    #+#             */
/*   Updated: 2019/04/23 21:56:31 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"

int		main(int cnt, char **argv)
{
	int fd;

	if (cnt != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (1);
	}
	else if (cnt == 2)
		fd = open(argv[1], O_RDONLY);
}
