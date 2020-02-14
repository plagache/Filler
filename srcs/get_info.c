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

void		find_player(t_filler *info)
{
	info->pl_char[2] = '\0';
	info->ad_char[2] = '\0';
	info->pl_char[0] = info->output_vm[10] == '1' ?  'O' : 'X' ;
	info->pl_char[1] = info->pl_char[0] == 'O' ?  'o' : 'x';
	info->ad_char[0] = info->output_vm[10] == '1' ?  'X' : 'O';
	info->ad_char[1] = info->ad_char[0] == 'X' ?  'x' : 'o';
}

int			find_piece(t_filler *info)
{
	int	c;

	c = 0;
	while (ft_strncmp(info->info_vm[c], "Piece ", 6) != 0)
		c++;
	info->piece = ft_strsplit(info->info_vm[c], ' ');
	if (info->piece == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int			find_map(t_filler *info)
{
	int	c;

	c = 0;
	while (ft_strncmp(info->info_vm[c], "Plateau ", 8) != 0)
		c++;
	info->map = ft_strsplit(info->info_vm[c], ' ');
	if (info->map == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int			get_board(t_filler *info)
{
	info->info_vm = ft_strsplit(info->output_vm, '\n');
	if (info->info_vm == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int			get_info(t_filler *info, int fd_debug, int turn)
{
	if (get_board(info) == FAILURE || find_map(info) == FAILURE 
		|| find_piece(info) == FAILURE)
		return (FAILURE);
	info->p_line = ft_atoi(info->piece[1]);
	info->p_column = ft_atoi(info->piece[2]);
	info->m_line = ft_atoi(info->map[1]);
	info->m_column = ft_atoi(info->map[2]);
	info->piece_line = ft_atoi(info->piece[1]);
	info->piece_column = ft_atoi(info->piece[2]);
//	dprintf(fd_debug, "\n|%i||%i||%i||%i|\n", info->p_line, info->p_column, info->m_line, info->m_column);
	if (turn == 0)
		find_player(info);
//	dprintf(fd_debug, "|%s||%s|\n", info->pl_char, info->ad_char);
//	dprintf(fd_debug, "|%i||%i|\n", info->piece_line, info->piece_column);
	(void)fd_debug;
	if (create_map(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
