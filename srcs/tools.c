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

void		get_init_pos(t_filler *info)
{
	int 	c;
	char 	*pos;


	info->piece_id_op = info->adver_number == 1 ? 'O' : 'X';
	c = 0;
	while (c < info->line)
	{
		if ((pos = ft_strchr(info->board[c], info->piece_id)) != NULL)
		{
			info->init_X = c;
			info->init_Y = (int)(pos - info->board[c]);
		}
		c++;
	}
	c = 0;
	while (c < info->line)
	{
		if ((pos = ft_strchr(info->board[c], info->piece_id_op)) != NULL)
		{
			info->init_op_X = c;
			info->init_op_Y = (int)(pos - info->board[c]);
		}
		c++;
	}
}

void		get_last_pos_adver(t_filler *info, int attck)
{

}

int			get_piece_size(t_filler *info)
{
	int x;
	int y;
	int size;

	x = 0;
	size = 0;
	while (info->piece[x] != '\0')
	{
		y = 0;
		while (info->piece[x][y] != '\0')
		{
			if (info->piece[x][y] == '*')
				size++;
			y++;
		}
		x++;
	}
	return (size);
}

int			get_nbr_board(t_filler *info, int player_number)
{
	int x;
	int y;
	int size;
	char p;


	x = 0;
	size = 0;
	p = 'x';
	if (player_number == 1)
		p = 'o';
	while (info->board[x] != '\0')
	{
		y = 0;
		while (info->board[x][y] != '\0')
		{
			if (info->board[x][y] == p || info->board[x][y] == p - 32)
				size++;
			y++;
		}
		x++;
	}
	return (size);
}
