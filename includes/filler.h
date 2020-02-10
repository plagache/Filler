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
	char	**info_vm;
	char 	**piece;
	char	**map;
	short	**heat_map;
	short	**heat_piece;
	char	*output_vm;
	char	pl_char[2];
	char	ad_char[2];
	int		p_line;
	int		p_column;
	int		m_line;
	int		m_column;
}					t_filler;

int					read_function(int fd, t_filler *info);
int					get_info(t_filler *info, int fd_debug, int turn);
#endif
