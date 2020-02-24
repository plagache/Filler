#include "../libft/includes/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/filler.h"
#include "../libft/includes/libft.h"

int		calcul_score(t_filler *info, int c_line, int c_column)
{
	int counter;
	int line;
	int column;

	counter = 0;
	line = 0;
	while (line < info->p_line)
	{
		column = 0;
		while (column < info->p_column)
		{
			if (info->heat_map[line + c_line][column + c_column] != ad_value
					&& info->heat_map[line + c_line][column + c_column] != pl_value
					&& info->heat_piece[line][column] == star_value)
				counter += info->heat_map[line + c_line][column + c_column];
			column++;
		}
		line++;
	}
	return (counter);
}

int		is_placeable(t_filler *info, int c_line, int c_column)
{
	int counter;
	int line;
	int column;

	counter = 0;
	line = 0;
	while (c_line + line < info->m_line && line < info->p_line)
	{
		column = 0;
		while (c_column + column < info->m_column && column < info->p_column)
		{
			if (info->heat_map[line + c_line][column + c_column] == ad_value
					&& info->heat_piece[line][column] == star_value)
				return (FALSE);
			else if (info->heat_map[line + c_line][column + c_column] == pl_value
					&& info->heat_piece[line][column] == star_value)
				counter++;
			column++;
		}
		line++;
	}
	if (counter == 1)
	{
		dprintf(info->fd_debug, "|%i|\n", counter);
		return (TRUE);
	}
	return (FALSE);
}

void	best_score(t_filler *info)
{
	int line;
	int column;

	line = 0;
	info->pos[2] = 9999;
	while (line < info->m_line)
	{
		column = 0;
		while (column < info->m_column)
		{
			if (is_placeable(info, line, column) == TRUE)	
			{
				if (info->pos[2] > calcul_score(info, line, column))
				{
					info->pos[0] = line;
					info->pos[1] = column;
					info->pos[2] = calcul_score(info, line, column);
					dprintf(info->fd_debug, "|%i||%i|%i|\n", info->pos[0], info->pos[1], info->pos[2]);
				}
			}
			column++;
		}
		line++;
	}
	//test toutes les positions et retien les pos du best_score 
}
