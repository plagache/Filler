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

void		get_line_col(t_filler *info)
{
	char *line;

	line = info->prog_board;
	if (ft_strstr(line, "Plateau") != NULL)
	{
		int c;

		c = 7;
		while (ft_isdigit(line[c]) == 0)
			c++;
		info->line = atoi(line + c);
		while (ft_isdigit(line[c]) == 1)
			c++;
		info->column = atoi(line + c);
	}
	info->prog_board = next_line(info->prog_board);
}

int			get_board(t_filler *info)
{
	char 	*line;
	int		l;

	l = 0;
	if (!(info->board = (char**)malloc(sizeof(char*) * (info->line + 1))))
		return (FAILURE);
	info->board[info->line] = NULL;
	line = info->prog_board;
	line = next_line(line);
	while(l < info->line - 1)
	{
		if (!(info->board[l] = (char*)malloc(sizeof(char) * (info->column + 1))))
			return (FAILURE);
		info->board[l][info->column] = '\0';
		line = next_line(line);
		ft_strncpy(info->board[l], (ft_strchr(line, ' ') + 1), info->column);
		l++;
	}
	return (SUCCESS);
}

void		get_piece_line_col(t_filler *info)
{
	char *line;

	info->prog_piece = ft_strstr(info->prog_board, "Piece");
	line = info->prog_piece;
	if (ft_strstr(line, "Piece") != NULL)
	{
		int c;

		c = 5;
		while (ft_isdigit(line[c]) == 0)
			c++;
		info->piece_line = atoi(line + c);
		while (ft_isdigit(line[c]) == 1)
			c++;
		info->piece_column = atoi(line + c);
	}
	info->prog_piece = next_line(info->prog_piece);
}


int			get_piece(t_filler *info)
{
	char 	*line;
	int		l;

	l = 0;
	if (!(info->piece = (char**)malloc(sizeof(char*) * (info->piece_line + 1))))
		return (FAILURE);
	info->piece[info->piece_line] = NULL;
	line = info->prog_piece;
	line = next_line(line);
	while(l < info->piece_line)
	{
		if (!(info->piece[l] = (char*)malloc(sizeof(char) * (info->piece_column + 1))))
			return (FAILURE);
		info->piece[l][info->piece_column] = '\0';
		line = next_line(line);
		ft_strncpy(info->piece[l], line, info->piece_column);
		dprintf(3, "line||%s||\n", info->piece[l]);
		dprintf(3, "line||%s||\n", line);
		l++;
	}
	return (SUCCESS);
}

int			get_player_number(t_filler *info)
{
	if (ft_strstr(info->prog, "$$$ exec p") != NULL)
	{
		info->player_number = (info->prog[10] == '1') ? 1 : 2;
		info->adver_number = info->player_number == 2 ? 1 : 2;
		info->piece_id = info->player_number == 1 ? 'O' : 'X';
	}
	info->prog_board = ft_strstr(info->prog, "Plateau");
	return (0);
}

void		get_infos(int fd, t_filler *info)
{
	get_player_number(info);
	get_line_col(info);
	get_board(info);
	get_piece_line_col(info);
	get_piece(info);
	(void)fd;
}
