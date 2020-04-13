/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:32:59 by plagache          #+#    #+#             */
/*   Updated: 2020/04/13 17:50:03 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static	int	calcul_score(t_filler *info, int c_line, int c_column)
{
	int counter;
	int line;
	int column;

	counter = 0;
	line = info->offset_l;
	while (line < info->p_line - info->diff_l)
	{
		column = info->offset_c;
		while (column < info->p_column)
		{
			if (info->heat_map[line + c_line][column + c_column] != AD_VALUE
				&& info->heat_map[line + c_line][column + c_column] != PL_VALUE
				&& info->heat_piece[line][column] == STAR_VALUE)
				counter += info->heat_map[line + c_line][column + c_column];
			column++;
		}
		line++;
	}
	return (counter);
}

static	int	is_placeable(t_filler *info, int c_line, int c_column)
{
	int counter;
	int line;
	int column;

	counter = 0;
	line = info->offset_l;
	while (c_line + line < info->m_line && line < (info->p_line - info->diff_l))
	{
		column = info->offset_c;
		while (c_column + column < info->m_column && column
		< (info->p_column - info->diff_c))
		{
			if (info->heat_map[line + c_line][column + c_column] == AD_VALUE
					&& info->heat_piece[line][column] == STAR_VALUE)
				return (FALSE);
			else if (info->heat_map[line + c_line][column + c_column]
			== PL_VALUE && info->heat_piece[line][column] == STAR_VALUE)
				counter++;
			column++;
		}
		line++;
	}
	if (counter == 1)
		return (TRUE);
	return (FALSE);
}

void		best_score(t_filler *info)
{
	int line;
	int column;

	line = 0 - info->offset_l;
	info->pos[2] = 9999;
	while ((line + (info->p_line - info->diff_l)) < info->m_line)
	{
		column = 0 - info->offset_c;
		while (column + info->p_column - info->diff_c < info->m_column)
		{
			if (is_placeable(info, line, column) == TRUE)
			{
				if (info->pos[2] > calcul_score(info, line, column))
				{
					info->pos[0] = line;
					info->pos[1] = column;
					info->pos[2] = calcul_score(info, line, column);
				}
			}
			column++;
		}
		line++;
	}
}
