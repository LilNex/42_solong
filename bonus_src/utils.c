/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:45:10 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/17 13:49:47 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	*get_position(int x, int y)
{
	t_position	*pos;

	pos = ft_calloc(1, sizeof(t_position));
	if (!pos)
		return (pos);
	pos->x = x;
	pos->y = y;
	return (pos);
}

t_position	*get_player_position(t_solong *utils)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (utils->map->map[x])
	{
		while (utils->map->map[x][y])
		{
			if (utils->map->map[x][y] == 'P')
				return (get_position(x, y));
			y++;
		}
		x++;
		y = 0;
	}
	return (NULL);
}
