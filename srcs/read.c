/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:31:49 by plagache          #+#    #+#             */
/*   Updated: 2019/11/27 18:24:11 by plagache         ###   ########.fr       */
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

int		ft_strlen_char(char *s, char c)
{
	int count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (count);
		count++;
	}
	return (FAILURE);
}

int		read_function(int fd_debug, t_filler *info)
{
	char	buff[BUFF_SIZE + 1];
	int		count;
	int		ret;

	count = 0;
	while ((ret = read(0, buff, BUFF_SIZE + 1)) > 0)
	{
		buff[ret] = '\0';
		if (info->prog == NULL)
			info->prog = ft_strdup(buff);
		else
			info->prog = ft_strjoinfree(1, info->prog, buff);
		return(FAILURE);
	}
	dprintf(fd_debug, "prog||%s||", info->prog);
	/*
	   while (buff[count] != '\n' && buff[count])
	   {
	   tmp[count] = buff[count];
	   count++;
	   }
	   */
	ft_printf("13 15");
	return (SUCCESS);
}
