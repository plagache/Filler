#include "libft/includes/ft_printf.h"
//my printf lib
#include <unistd.h>
//write read
#include <stdlib.h>
//malloc
#include <stdio.h>
//perror
#include <string.h>
//strerror
#include "filler.h"
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <fcntl.h>

/*
** 1) parser to read:
** - board and piece
** 2) best pos to know coor
** - then write coor
*/

/*
** void	fill_file(int fd, char	*line)
** {
** 	int	ret;
** 
** 	while (ft_strstr(line, "Plateau") == NULL)
** 	{
** 		if (ret != -1)
** 		{
** 			ret = get_next_line(0, &line);
** 			write(fd, line, ft_strlen(line));
** 			write(fd, "\n", 1);
** 			free(line);
** 		}
** 	}
** }
*/
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
		return (-1);
	info->board[info->line] = NULL;
	get_next_line(0, &line);
	free(line);
	while(l < info->line)
	{
		if (!(info->board[l] = (char*)malloc(sizeof(char) * (info->column + 1))))
			return (-1);
		info->board[l][info->column] = '\0';
		get_next_line(0, &line);
		ft_strcpy(info->board[l], ft_strchr(line, '.'));
		free(line);
		l++;
	}
	return (0);
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
		return (-1);
	info->piece[info->piece_line] = NULL;
	while(l < info->piece_line)
	{
		if (!(info->piece[l] = (char*)malloc(sizeof(char) * (info->piece_column + 1))))
			return (-1);
		info->piece[l][info->piece_column] = '\0';
		get_next_line(0, &line);
		ft_strcpy(info->piece[l], line);
		free(line);
		l++;
	}
	return (l);
}

void		get_infos(int fd, t_filler *info)
{
	char		*line;
	int			ret;

	ret = get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p") != NULL)
		info->piece_id = (line[11] == '1') ? "x" : "o";
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
	get_piece(info);
	dprintf(fd, "1line :|%i|\ncolumn :|%i|\nParsing OK\n", info->line, info->column);
}

int			main(void)
{
	int			fd_debug;
	t_filler	info;

	fd_debug = open("output.txt", O_CREAT|O_RDWR|O_APPEND);
	get_infos(fd_debug, &info);
	close(fd_debug);
	ft_printf("8 2\n");
	return (0);
}

/*
** 1) Start
** Prog reads on standard input the player order like so:
** $$$ exec p1 : [player name]
** $$$ exec p2 : [palyer name]
**
** p1 is identified by 'o' 'O'
** p2 is identified by 'x' 'X'
**
**
** 2) Read board and piece
** Prog reads the game board like so:
** Plateau Lne Col:
**     01234567890134567890123456789
** 000 .............................
** 001 .............................
** 002 ..X..........................
** 003 .............................
** 004 .............................
** 005 .............................
** 006 .............................
** 007 .............................
** 008 .............................
** 009 .............................
** 010 .............................
** 011 ..........................O..
** 012 .............................
** 013 .............................
**
** 
** Prog reads the pieces like so:
** Piece Lne Col:
**  ...*...
**  ...*...
**  ...*...
**  ..***..
**
** Each turn Prog reads the updated map and the piece to place.
**
** Prog places piece by giving where the top left of the piece should be placed in the board coordinates system.
** In the example player X can place the piece by printing 2 -1
**
** After printing on the output, Prog is stopped until next turn by vm.
*/


