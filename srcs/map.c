/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:31:49 by plagache          #+#    #+#             */
/*   Updated: 2020/02/12 16:36:28 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
//my printf lib
#include <unistd.h>
//write read
#include <stdlib.h>
//malloc
#include <stdio.h>
//perror
#include <string.h>
//strerror
#include "../includes/filler.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

int			fill_map(t_filler *info)
{
	int line;
	int column;

	line = 0;
	while (line < info->m_line)
	{
		column = 0;
		while (column < info->m_column)
		{
		//	dprintf(info->fd_debug, "\n|%s|\n", info->info_vm[line + 3]);
		//	dprintf(info->fd_debug, "\nheatmap|%hi|\n", info->heat_map[line][column]);
			if (ft_strchr(info->pl_char, info->info_vm[line + 3][column + 4]) != 0)
				info->heat_map[line][column] = pl_value;
			else if (ft_strchr(info->ad_char, info->info_vm[line + 3][column + 4]) != 0)
			{
				dprintf(info->fd_debug, "test\n");
				info->heat_map[line][column] = ad_value;
			}
			else
				info->heat_map[line][column] = base_value;
			column++;
		}
		line++;
	}
	//fill map with basic info
	return (SUCCESS);
}

int			malloc_map(t_filler *info)
{
	int c;

	c = info->m_line;
	info->heat_map = (short**)malloc(sizeof(short*) * (c + 1));
	if (info->heat_map == NULL)
		return(FAILURE);
	info->heat_map[c] = NULL;
	c = 0;
	while (c < info->m_line)
	{
		info->heat_map[c] = (short*)malloc(sizeof(short) * (info->m_column + 1));
		if (info->heat_map[c] == NULL)
			return (FAILURE);
		info->heat_map[c][info->m_column] = '\0';
		c++;
	}
	return (SUCCESS);
}

int			malloc_piece(t_filler *info)
{
	int c;

	c = info->p_line;
	info->heat_piece = (short**)malloc(sizeof(short*) * (c + 1));
	if (info->heat_piece == NULL)
		return(FAILURE);
	info->heat_piece[c] = NULL;
	while (c >= 0)
	{
		info->heat_piece[c] = (short*)malloc(sizeof(short) * (info->p_column + 1));
		if (info->heat_piece[c] == NULL)
			return (FAILURE);
		info->heat_piece[c][info->p_column] = '\0';
		c--;
	}
	return (SUCCESS);
}

int			create_map(t_filler *info)
{
	if (malloc_map(info) == FAILURE 
			|| malloc_piece(info) == FAILURE
			|| fill_map(info) == FAILURE)

		//	|| fill_piece(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
