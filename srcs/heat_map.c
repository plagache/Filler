/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:46:02 by plagache          #+#    #+#             */
/*   Updated: 2020/02/18 21:05:28 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/filler.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

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

int			is_zero(t_filler *info)
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

void			fill_map_value(t_filler *info, int line, int column, int value)
{
	if (line - 1 >= 0 && info->heat_map[line - 1][column] == 0)
		info->heat_map[line - 1][column] = value;
	if (line + 1 < info->m_line && info->heat_map[line + 1][column] == 0)
		info->heat_map[line + 1][column] = value;
	if (column - 1 >= 0 && info->heat_map[line][column - 1] == 0)
		info->heat_map[line][column - 1] = value;
	if (column + 1 < info->m_column && info->heat_map[line][column + 1] == 0)
		info->heat_map[line][column + 1] = value;
	//take the value and fill the case aroud with a next value//
}

void			search_value(t_filler *info, int value, int to_fill)
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
	//search a value in a short** (start with the opposant value
	//call fill map 
}

int			call_mapping(t_filler *info)
{
	int value;
	int to_fill;

	value = ad_value;
	to_fill = 1;
	while (is_zero(info) == TRUE)
	{
		search_value(info, value, to_fill);
		value = to_fill;
		to_fill++;
	}
//print_map(info->heat_map, info->fd_debug, info);
	return (SUCCESS);
}
