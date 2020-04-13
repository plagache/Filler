/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:25:48 by plagache          #+#    #+#             */
/*   Updated: 2020/04/13 17:47:29 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 4096

# define FALSE 0
# define TRUE 1

# define SUCCESS -31415
# define FAILURE -43

# define BASE_VALUE 0
# define PL_VALUE -1
# define AD_VALUE -2
# define STAR_VALUE -3

typedef struct		s_filler
{
	char	**info_vm;
	char	**map;
	char	**piece;
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
	int		turn;
}					t_filler;

int					read_function(t_filler *info);
int					get_info(t_filler *info, int turn);
int					create_map(t_filler *info);
int					print_map(short **board, int fd, t_filler *info);
int					print_piece(short **board, int fd, t_filler *info);
int					call_mapping(t_filler *info);
void				best_score(t_filler *info);
void				programme_clean(t_filler *info);
void				offset_piece(t_filler *info);
#endif
