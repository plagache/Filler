/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:43:08 by plagache          #+#    #+#             */
/*   Updated: 2020/04/13 17:41:58 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static	void	find_player(t_filler *info)
{
	info->pl_char[2] = '\0';
	info->ad_char[2] = '\0';
	info->pl_char[0] = info->output_vm[10] == '1' ? 'O' : 'X';
	info->pl_char[1] = info->pl_char[0] == 'O' ? 'o' : 'x';
	info->ad_char[0] = info->output_vm[10] == '1' ? 'X' : 'O';
	info->ad_char[1] = info->ad_char[0] == 'X' ? 'x' : 'o';
}

static	int		find_piece(t_filler *info)
{
	int	c;

	c = 0;
	while (ft_strncmp(info->info_vm[c], "Piece ", 6) != 0)
		c++;
	info->piece = ft_strsplit(info->info_vm[c], ' ');
	info->p_line = ft_atoi(info->piece[1]);
	info->p_column = ft_atoi(info->piece[2]);
	free_arr((void**)info->piece);
	info->piece = info->info_vm + c + 1;
	if (info->piece == NULL || info->p_line == 0 || info->p_column == 0)
		return (FAILURE);
	return (SUCCESS);
}

static	int		find_map(t_filler *info)
{
	int	c;

	c = 0;
	while (ft_strncmp(info->info_vm[c], "Plateau ", 8) != 0)
		c++;
	info->map = ft_strsplit(info->info_vm[c], ' ');
	info->m_line = ft_atoi(info->map[1]);
	info->m_column = ft_atoi(info->map[2]);
	free_arr((void**)info->map);
	info->map = info->info_vm + c + 2;
	if (info->map == NULL || info->m_line == 0 || info->m_column == 0)
		return (FAILURE);
	return (SUCCESS);
}

static int		get_board(t_filler *info)
{
	info->info_vm = ft_strsplit(info->output_vm, '\n');
	if (info->info_vm == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int				get_info(t_filler *info, int turn)
{
	if (get_board(info) == FAILURE || find_map(info) == FAILURE
		|| find_piece(info) == FAILURE)
		return (FAILURE);
	if (turn == 0)
		find_player(info);
	ft_strdel(&(info->output_vm));
	if (create_map(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
