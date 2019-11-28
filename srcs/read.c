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
#include <fcntl.h>

char		*next_line(char *line)
{
	char	*next_line;

	next_line = (ft_strchr(line, '\n') + 1);
	return (next_line);
}

int		read_function(int fd_debug, t_filler *info)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	(void)fd_debug;
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (info->prog == NULL)
			info->prog = ft_strdup(buff);
		else
			info->prog = ft_strjoinfree(1, info->prog, buff);
	}
//	dprintf(fd_debug, "prog||%s||", info->prog);
	return (ret);
}
