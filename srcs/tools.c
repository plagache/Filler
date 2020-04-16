/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:42:43 by plagache          #+#    #+#             */
/*   Updated: 2020/04/16 15:51:18 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static	void	free_ptr(t_filler *info)
{
	info->piece = NULL;
	info->map = NULL;
	info->info_vm = NULL;
	info->heat_map = NULL;
	info->heat_piece = NULL;
	info->p_line = 0;
	info->p_column = 0;
	info->offset_l = 0;
	info->offset_c = 0;
	info->diff_l = 0;
	info->diff_c = 0;
	info->m_line = 0;
	info->m_column = 0;
}

void			programme_clean(t_filler *info)
{
	free_arr((void**)info->info_vm);
	free_arr((void**)info->heat_map);
	free_arr((void**)info->heat_piece);
	free_ptr(info);
}

void			free_info(t_filler *info)
{
	free_arr((void**)info->info_vm);
	free_ptr(info);
}

static	int		check_p_size(t_filler *info)
{
	int column;
	int line;

	line = 0;
	while (info->piece[line])
	{
		column = 0;
		while (info->piece[line][column])
			column++;
		if (column != info->p_column)
			return (FAILURE);
		line++;
	}
	if (line != info->p_line)
		return (FAILURE);
	return (SUCCESS);
}

int				check_size(t_filler *info)
{
	int column;
	int line;

	line = 0;
	while (info->map[line] && info->map + line != info->piece - 1)
	{
		column = 0;
		while (info->map[line][column])
			column++;
		if (column != info->m_column + 4)
		{
			free_info(info);
			return (FAILURE);
		}
		line++;
	}
	if (line != info->m_line || check_p_size(info) == FAILURE)
	{
		free_info(info);
		return (FAILURE);
	}
	return (SUCCESS);
}
