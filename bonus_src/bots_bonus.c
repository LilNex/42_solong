/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bots_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:02:16 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 00:51:40 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_position_enemy(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (map[x] && map[x][y] == 'B')
		return (1);
	else if (x >= 0 && map[x] && map[x][y] == 'B')
		return (1);
	else if (x >= 0 && map[x] && map[x][y] == 'B')
		return (1);
	else if (map[x] && map[x][y] == 'B')
		return (1);
	else
		return (0);
}

t_position	*search_nearest_enemy(t_position *p_pos, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < RANGE_ENEMY)
	{
		while (y < RANGE_ENEMY)
		{
			if (is_position_enemy(map, p_pos->x + x, p_pos->y + y))
				return (get_position(p_pos->x + x, p_pos->y + y));
			else if (is_position_enemy(map, p_pos->x - x, p_pos->y - y))
				return (get_position(p_pos->x - x, p_pos->y - y));
			else if (is_position_enemy(map, p_pos->x - x, p_pos->y + y))
				return (get_position(p_pos->x - x, p_pos->y + y));
			else if (is_position_enemy(map, p_pos->x + x, p_pos->y - y))
				return (get_position(p_pos->x + x, p_pos->y - y));
			else
				y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}

void	move_enemy(t_solong *utils, t_position	*p_pos)
{
	t_position	*e_pos;

	e_pos = search_nearest_enemy(p_pos, utils->map->map);
	if (e_pos)
	{
		printf("ENEMY | x : %d; y : %d\n",e_pos->x, e_pos->y);
	}
}