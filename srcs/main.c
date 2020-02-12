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

int		print_board(char **board, int fd)
{
	int count;

	count = 0;
	while (board[count] != NULL)
	{
		dprintf(fd, "%s\n", board[count]);
		count++;
	}
	return (SUCCESS);
}

int		print_map(short **board, int fd, t_filler *info)
{
	int count;
	int x;

	count = 0;
	while (count < info->m_line)
	{
		x = 0;
		while (x < info->m_column)
		{
			dprintf(fd, "%hi", board[count][x]);
			x++;
		}
		dprintf(fd, "\n");
		count++;
	}
	return (SUCCESS);
}

int			main(void)
{
	int			fd_debug;
	int			turn;
	t_filler	info;

	turn = 0;
	fd_debug = open("output.txt", O_CREAT|O_RDWR|O_APPEND);
	ft_bzero(&info, sizeof(info));
	info.fd_debug = fd_debug;
	while (1)
	{
		read_function(fd_debug, &info);
		get_info(&info, fd_debug, turn);
		print_map(info.heat_map, fd_debug, &info);
		//print_board(info.map, fd_debug);
		//print_board(info.piece, fd_debug);
		//print_board(info.info_vm, fd_debug);
		turn++;
		//print_map(info.heat_piece, fd_debug);
		free(info.output_vm);
		free_arr((void**)info.piece);
		free_arr((void**)info.map);
		free_arr((void**)info.info_vm);
		//getchar();
		return (EXIT_FAILURE);
	}

	close(fd_debug);
	return (EXIT_SUCCESS);
}

//todo free array void**

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
 ** Plateau Lne 14  Col 30:
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
 ** Piece Lne 4 Col 7:
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


