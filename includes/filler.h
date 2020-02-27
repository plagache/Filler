#ifndef	FILLER_H
# define FILLER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define BUFF_SIZE 200

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILURE 1

# define base_value 0
# define pl_value -1
# define ad_value -2
# define star_value -3

typedef struct		s_filler
{
	char	**info_vm;
	char	**map;
	char 	**piece;
	short	**heat_map;
	short	**heat_piece;
	char	*output_vm;
	char	pl_char[3];
	char	ad_char[3];
	int		pos[3];
	int		p_line;
	int		p_column;
	int		offset_l;
	int		offset_c;
	int		diff_l;
	int		diff_c;
	int		m_line;
	int		m_column;
	int		fd_debug;
}					t_filler;

int					read_function(int fd, t_filler *info);
int					get_info(t_filler *info, int turn);
void				free_arr(void **arr);
int					create_map(t_filler *info);
int					print_map(short **board, int fd, t_filler *info);
int					print_piece(short **board, int fd, t_filler *info);
int					call_mapping(t_filler *info);
void				best_score(t_filler *info);
void				programme_clean(t_filler *info);
void				offset_piece(t_filler *info);
#endif
