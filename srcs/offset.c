/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:55:30 by plagache          #+#    #+#             */
/*   Updated: 2020/02/27 11:55:38 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/filler.h"
#include "../libft/includes/libft.h"

/*
** #include "../libft/includes/ft_printf.h" **
** my printf lib **
** #include <unistd.h> **
** write read **
** #include <stdlib.h> **
** malloc **
** #include <stdio.h> **
** perror **
** #include <string.h> **
** strerror **
*/

// take the piece form
// calculate diff
// only needed for placebale


void		diff_piece(t_filler *info)
{
	int line;
	int column;

	line = info->p_line - 1;
	while (ft_strchr(info->piece[line], '*') == NULL)
		line--;
	info->diff_l = (info->p_line - 1) - line;
	column = info->p_column - 1;
	info->diff_c = -1;
	while (column >= 0 && info->diff_c == -1)
	{
		line = 0;
		while (line < info->p_line && info->piece[line][column] != '*')
			line++;
		if (line != info->p_line)
			info->diff_c = (info->p_column - 1) - column;
		column--;
	}
//	dprintf(info->fd_debug, "        diffline |%i|\n diffcol|%i|\n", info->diff_l, info->diff_c);
}


// take the piece 
// calculate the offset
// is needed for placebale
//

void	offset_piece(t_filler *info)
{
	int line;
	int column;

	line = 0;
	while (ft_strchr(info->piece[line], '*') == NULL)
		line++;
	info->offset_l = line;
	column = 0;
	info->offset_c = -1;
	while (column < info->p_column && info->offset_c == -1)
	{
		line = 0;
		while (line < info->p_line && info->piece[line][column] != '*')
			line++;
		if (line != info->p_line)
			info->offset_c = column;
		column++;
	}
//	dprintf(info->fd_debug, "        offsetline |%i|\n offsetcol|%i|\n", info->offset_l, info->offset_c);
	diff_piece(info);
}
