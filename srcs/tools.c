/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:42:43 by plagache          #+#    #+#             */
/*   Updated: 2020/02/18 12:42:48 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/filler.h"
#include "../libft/includes/libft.h"

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

void		free_arr(void **arr)
{
	int c;

	c = 0;
	while (arr[c] != NULL)
	{
		free(arr[c]);
		c++;
	}
	free(arr);
}

void		free_ptr(t_filler *info)
{
	info->piece = NULL;
	info->map = NULL;
	info->info_vm = NULL;
	info->heat_map = NULL;
	info->heat_piece = NULL;
}

void		programme_clean(t_filler *info)
{
		free_arr((void**)info->info_vm);
		free_arr((void**)info->heat_map);
		free_arr((void**)info->heat_piece);
		free_ptr(info);
//		dprintf(info->fd_debug, "|fin de free|\n");
}
