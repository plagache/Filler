#include "../libft/includes/ft_printf.h"
//my printf lib
#include <unistd.h>
//write read
#include <stdlib.h>
//malloc
#include <stdio.h>
//perror
#include <string.h>
//strerror
#include "../includes/filler.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <fcntl.h>

/*
int		move_piece(t_filler *info)
{
	int m;
	int c;

	m = 0;
	c = 0;
	while(info->piece_id[c])
	{
		if (info->piece_id[c] == "*")
			return (c);
		c++;
	}
	return (0);
}
*/

int		check_col(t_filler *info, char c)
{
	int res;
	int x;
	int y;
	int z;
	int i;

	i = 0;
	z = 0;
	x = info->init_X;
	res = 0;
	while (x < info->line)
	{
		y = info->init_Y;
		while (y < info->column)
		{
			if (info->board[x][y] == c && info->piece[z][i])
				res++;
			y++;
		}
		x++;
	}
	return (res);
}
