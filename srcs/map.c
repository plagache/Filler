/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:31:49 by plagache          #+#    #+#             */
/*   Updated: 2019/11/28 17:50:03 by plagache         ###   ########.fr       */
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

}

int			malloc_map(t_filler *info)
{
	int c;

	c = info->m_line;
	info->heat_map = (short**)malloc(sizeof(short*) * (c + 1));
	if (info->heat_map == NULL)
		return(FAILURE);
	info->heat_map[c] = NULL;
	while (c >= 0)
	{
		info->heat_map[c] = (short*)malloc(sizeof(short) * (info->m_column + 1));
		if (info->heat_map[c] == NULL)
			return (FAILURE);
		info->heat_map[c][info->m_column] = '\0';
		c--;
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
			|| fill_map(info) == FAILURE
			|| fill_piece(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
