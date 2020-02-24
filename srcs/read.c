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

int		end_of_read(t_filler *info)
{
	int backslash_n = 0;
	char *ptr;
	int c;

	c = 0;
	if ((ptr = ft_strstr(info->output_vm, "Piece ")) == NULL)
		return (FAILURE);
	if (ft_strchr(ptr, '\n') == NULL)
		return (FAILURE);
	backslash_n = ft_atoi(ptr + 6);
	while (ptr[c])
	{
		backslash_n -= (ptr[c] == '\n' ? 1 : 0);
		c++;
	}
	if (backslash_n == -1)
		return (SUCCESS);
	return (FAILURE);
}

int		read_function(int fd_debug, t_filler *info)
{
	char	buff[BUFF_SIZE + 1];
	int		ret = 0;

	(void)fd_debug;
	if (info->output_vm == NULL)
		info->output_vm = ft_strnew(0);
	while (end_of_read(info) != SUCCESS)
	{
		ret = read(0, buff, BUFF_SIZE);
		buff[ret] = '\0';
		info->output_vm = ft_strjoinfree(1, info->output_vm, buff);
	}
	//dprintf(fd_debug, "ret =|%i|\n|%s|\n", ret, info->output_vm);
	return (ret);
}
