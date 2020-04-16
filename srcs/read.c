/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:31:49 by plagache          #+#    #+#             */
/*   Updated: 2020/04/16 15:49:30 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "filler.h"
#include "libft.h"

static	int	end_of_read(char *str)
{
	char	*ptr;
	int		backslash_n;
	int		c;

	backslash_n = 0;
	c = 0;
	if ((ptr = ft_strstr(str, "Piece ")) == NULL)
		return (FAILURE);
	if (ft_strchr(ptr, '\n') == NULL)
		return (FAILURE);
	backslash_n = ft_atoi(ptr + 6);
	while (ptr[c])
	{
		backslash_n -= (ptr[c] == '\n' ? 1 : 0);
		c++;
	}
	if (backslash_n != -1)
		return (FAILURE);
	return (SUCCESS);
}

static	int	check_dev(int len, char *buff, char *str_to_free)
{
	int c;

	c = 0;
	if (!buff || buff[c] == '\0')
		return (FAILURE);
	while (c < len)
	{
		if (buff[c] <= 0)
		{
			free(str_to_free);
			return (FAILURE);
		}
		c++;
	}
	return (SUCCESS);
}

int			read_function(t_filler *info)
{
	char	buff[BUFF_SIZE + 1];
	char	*str;
	int		ret;

	str = ft_strnew(0);
	ret = 0;
	if (str == NULL)
		return (ret);
	while (end_of_read(str) != SUCCESS)
	{
		if ((ret = read(0, buff, BUFF_SIZE)) < 0)
		{
			free(str);
			return (FAILURE);
		}
		buff[ret] = '\0';
		if (check_dev(ret, buff, str) == FAILURE)
		{
			free(str);
			return (FAILURE);
		}
		str = ft_strjoinfree(1, str, buff);
	}
	info->output_vm = str;
	return (ret);
}
