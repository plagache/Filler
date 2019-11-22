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

void		get_line_col(t_filler *info, char *str)
{
	int c;

	c = 7;
	while (ft_isdigit(str[c]) == 0)
		c++;
	info->line = atoi(str + c);
	while (ft_isdigit(str[c]) == 1)
		c++;
	info->column = atoi(str + c);
}

int			get_board(t_filler *info)
{
	char 	*line;
	int		l;

	l = 0;
	if (!(info->board = (char**)malloc(sizeof(char*) * (info->line + 1))))
		return (FAILURE);
	info->board[info->line] = NULL;
	get_next_line(0, &line);
	free(line);
	while(l < info->line)
	{
		if (!(info->board[l] = (char*)malloc(sizeof(char) * (info->column + 1))))
			return (FAILURE);
		info->board[l][info->column] = '\0';
		get_next_line(0, &line);
		ft_strcpy(info->board[l], (ft_strchr(line, ' ') + 1));
		free(line);
		l++;
	}
	return (SUCCESS);
}

void		get_piece_line_col(t_filler *info, char *str)
{
	int c;

	c = 5;
	while (ft_isdigit(str[c]) == 0)
		c++;
	info->piece_line = atoi(str + c);
	while (ft_isdigit(str[c]) == 1)
		c++;
	info->piece_column = atoi(str + c);
}


int			get_piece(t_filler *info)
{
	char 	*line;
	int		l;

	l = 0;
	if (!(info->piece = (char**)malloc(sizeof(char*) * (info->piece_line + 1))))
		return (FAILURE);
	info->piece[info->piece_line] = NULL;
	while(l < info->piece_line)
	{
		if (!(info->piece[l] = (char*)malloc(sizeof(char) * (info->piece_column + 1))))
			return (FAILURE);
		info->piece[l][info->piece_column] = '\0';
		get_next_line(0, &line);
		ft_strcpy(info->piece[l], line);
		free(line);
		l++;
	}
	return (SUCCESS);
}

void		get_infos(int fd, t_filler *info)
{
	char		*line;
	int			ret;

	ret = get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p") != NULL)
	{
		info->player_number = (line[10] == '1') ? 1 : 2;
		info->piece_id = info->player_number == 1 ? "O" : "X";
	}
	free(line);
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau") != NULL)
		get_line_col(info, line);
	free(line);
	
	ret = get_board(info);
	while (ret-- > 0)
	{
		get_next_line(0, &line);
		free(line);
	}
	
	get_next_line(0, &line);
	if (ft_strstr(line, "Piece") != NULL)
		get_piece_line_col(info, line);
	ret = get_piece(info);
	while (ret-- > 0)
	{
		get_next_line(0, &line);
		free(line);
	}
	(void)fd;
	dprintf(fd, "player number :|%i|\nParsing OK\n", info->player_number);
}
