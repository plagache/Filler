/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:43:23 by plagache          #+#    #+#             */
/*   Updated: 2020/04/21 18:41:17 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int			main(void)
{
	t_filler	info;

	info.turn = 0;
	ft_bzero(&info, sizeof(info));
	while (info.pos[2] != MAX_VALUE)
	{
		if (read_function(&info) == FAILURE)
			return (EXIT_FAILURE);
		if (get_info(&info, info.turn) == FAILURE)
			return (EXIT_FAILURE);
		if (check_size(&info) == FAILURE)
			return (EXIT_FAILURE);
		if (create_map(&info) == FAILURE)
			return (EXIT_FAILURE);
		offset_piece(&info);
		call_mapping(&info);
		best_score(&info);
		ft_printf("%i %i\n", info.pos[0], info.pos[1]);
		info.turn++;
		programme_clean(&info);
	}
	return (EXIT_SUCCESS);
}
