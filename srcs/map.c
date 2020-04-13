/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:31:49 by plagache          #+#    #+#             */
/*   Updated: 2020/04/13 17:48:31 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static	int	fill_base_map(t_filler *info)
{
	int line;
	int column;

	line = 0;
	while (line < info->m_line)
	{
		column = 0;
		while (column < info->m_column)
		{
			if (ft_strchr(info->pl_char,
					info->map[line][column + 4]) != NULL)
				info->heat_map[line][column] = PL_VALUE;
			else if (ft_strchr(info->ad_char,
					info->map[line][column + 4]) != NULL)
				info->heat_map[line][column] = AD_VALUE;
			else
				info->heat_map[line][column] = BASE_VALUE;
			column++;
		}
		line++;
	}
	return (SUCCESS);
}

static	int	fill_piece(t_filler *info)
{
	int line;
	int column;

	line = 0;
	while (line < info->p_line)
	{
		column = 0;
		while (column < info->p_column)
		{
			if (info->piece[line][column] == '*')
				info->heat_piece[line][column] = STAR_VALUE;
			else
				info->heat_piece[line][column] = BASE_VALUE;
			column++;
		}
		line++;
	}
	return (SUCCESS);
}

static	int	malloc_map(t_filler *info)
{
	int c;

	c = info->m_line;
	info->heat_map = (short**)malloc(sizeof(short*) * (c + 1));
	if (info->heat_map == NULL)
		return (FAILURE);
	info->heat_map[c] = NULL;
	c = 0;
	while (c < info->m_line)
	{
		info->heat_map[c] = (short*)malloc(sizeof(short)
			* (info->m_column));
		if (info->heat_map[c] == NULL)
			return (FAILURE);
		c++;
	}
	return (SUCCESS);
}

static	int	malloc_piece(t_filler *info)
{
	int c;

	c = info->p_line;
	info->heat_piece = (short**)malloc(sizeof(short*) * (c + 1));
	if (info->heat_piece == NULL)
		return (FAILURE);
	info->heat_piece[c] = NULL;
	c = 0;
	while (c < info->p_line)
	{
		info->heat_piece[c] = (short*)malloc(sizeof(short)
				* (info->p_column));
		if (info->heat_piece[c] == NULL)
			return (FAILURE);
		c++;
	}
	return (SUCCESS);
}

int			create_map(t_filler *info)
{
	if (malloc_map(info) == FAILURE
			|| malloc_piece(info) == FAILURE
			|| fill_base_map(info) == FAILURE
			|| fill_piece(info) == FAILURE)
		return (FAILURE);
	call_mapping(info);
	return (SUCCESS);
}
