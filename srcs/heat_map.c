/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:46:02 by plagache          #+#    #+#             */
/*   Updated: 2020/04/22 21:32:45 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static int	is_zero(t_filler *info)
{
	int line;
	int column;

	line = 0;
	while (line < info->m_line)
	{
		column = 0;
		while (column < info->m_column)
		{
			if (info->heat_map[line][column] == 0)
				return (TRUE);
			column++;
		}
		line++;
	}
	return (FALSE);
}

static void	fill_map_value(t_filler *info, int line, int column, int value)
{
	if (line - 1 >= 0 && info->heat_map[line - 1][column] == 0)
		info->heat_map[line - 1][column] = value;
	if (line + 1 < info->m_line && info->heat_map[line + 1][column] == 0)
		info->heat_map[line + 1][column] = value;
	if (column - 1 >= 0 && info->heat_map[line][column - 1] == 0)
		info->heat_map[line][column - 1] = value;
	if (column + 1 < info->m_column && info->heat_map[line][column + 1] == 0)
		info->heat_map[line][column + 1] = value;
	if (line - 1 >= 0 && column - 1 >= 0
		&& info->heat_map[line - 1][column - 1] == 0)
		info->heat_map[line - 1][column - 1] = value;
	if (line + 1 < info->m_line && column - 1 >= 0
		&& info->heat_map[line + 1][column - 1] == 0)
		info->heat_map[line + 1][column - 1] = value;
	if (column + 1 < info->m_column && line - 1 >= 0
		&& info->heat_map[line - 1][column + 1] == 0)
		info->heat_map[line - 1][column + 1] = value;
	if (line + 1 < info->m_line && column + 1 < info->m_column
		&& info->heat_map[line + 1][column + 1] == 0)
		info->heat_map[line + 1][column + 1] = value;
}

static void	search_value(t_filler *info, int value, int to_fill)
{
	int line;
	int column;

	line = 0;
	while (line < info->m_line)
	{
		column = 0;
		while (column < info->m_column)
		{
			if (info->heat_map[line][column] == value)
				fill_map_value(info, line, column, to_fill);
			column++;
		}
		line++;
	}
}

int			call_mapping(t_filler *info)
{
	int value;
	int to_fill;

	value = AD_VALUE;
	to_fill = 1;
	while (is_zero(info) == TRUE && to_fill < 142)
	{
		search_value(info, value, to_fill);
		value = to_fill;
		to_fill++;
	}
	return (SUCCESS);
}
