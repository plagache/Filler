#ifndef	FILLER_H
# define FILLER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_filler
{
	char	**board;
	int		line;
	int		column;
	char 	**piece;
	int		piece_line;
	int		piece_column;
	char	*piece_id;
}					t_filler;

#endif
