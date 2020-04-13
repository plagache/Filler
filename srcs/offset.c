/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:55:30 by plagache          #+#    #+#             */
/*   Updated: 2020/04/13 17:44:36 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static void	diff_piece(t_filler *info)
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
}

void		offset_piece(t_filler *info)
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
	diff_piece(info);
}
