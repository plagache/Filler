#ifndef	FILLER_H
# define FILLER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE 1

typedef struct		s_filler
{
	char	**board;
	int		line;
	int		column;
	int		init_X;
	int		init_Y;
	int		init_op_X;
	int		init_op_Y;
	char 	**piece;
	int		piece_line;
	int		piece_column;
	int		player_number;
	int		adver_number;
	char	piece_id;
	//+32 pour les minus.
	char	piece_id_op;
	//same
}					t_filler;


void				get_line_col(t_filler *info);
void				get_piece_line_col(t_filler *info);
int					get_board(t_filler *info);
int					get_piece(t_filler *info);
void				get_infos(int fd, t_filler *info);
void				get_init_pos(t_filler *info);
int					get_piece_size(t_filler *info);
int					get_nbr_board(t_filler *info, int player_number);
#endif
