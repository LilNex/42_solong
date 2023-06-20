/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bots_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:02:16 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 17:04:14 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_position_enemy(t_solong *u, int x, int y)
{
	char	**map;

	map = u->map->map;
	if ((x < 0 || y < 0) || (x >= u->map->height || y >= u->map->width))
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

t_position	*search_nearest_enemy(t_solong *utils, t_position *p_pos)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < RANGE_ENEMY)
	{
		while (y < RANGE_ENEMY)
		{
			if (is_position_enemy(utils, p_pos->x + x, p_pos->y + y))
				return (get_position(p_pos->x + x, p_pos->y + y));
			else if (is_position_enemy(utils, p_pos->x - x, p_pos->y - y))
				return (get_position(p_pos->x - x, p_pos->y - y));
			else if (is_position_enemy(utils, p_pos->x - x, p_pos->y + y))
				return (get_position(p_pos->x - x, p_pos->y + y));
			else if (is_position_enemy(utils, p_pos->x + x, p_pos->y - y))
				return (get_position(p_pos->x + x, p_pos->y - y));
			else
				y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}

int	get_movement(int p, int e)
{
	if (p == e)
		return (0);
	else if (p < e)
		return (-1);
	else
		return (1);
}

void	move_enemy_to_player(t_solong *u, t_position *p_pos, t_position *e_pos)
{
	int		x;
	int		y;
	char	**map;

	map = u->map->map;
	x = get_movement(p_pos->x, e_pos->x);
	y = get_movement(p_pos->y, e_pos->y);
	if (map[e_pos->x + x][e_pos->y] == 'P'
		|| map[e_pos->x][e_pos->y + y] == 'P')
		ft_error(u, "You loosed !\nThe enemy hitted you !", 0);
	if (x == 0 && map[e_pos->x][e_pos->y + y] == '1')
		x++;
	else if (y == 0 && map[e_pos->x][e_pos->y + y] == '1')
		y++;
	if (map[e_pos->x][e_pos->y + y] == '0')
	{
		map[e_pos->x][e_pos->y] = '0';
		map[e_pos->x][e_pos->y + y] = 'B';
	}
	else if (map[e_pos->x + x][e_pos->y] == '0')
	{
		map[e_pos->x][e_pos->y] = '0';
		map[e_pos->x + x][e_pos->y] = 'B';
	}
}

void	move_enemy(t_solong *utils, t_position	*p_pos)
{
	t_position	*e_pos;

	e_pos = search_nearest_enemy(utils, p_pos);
	if (e_pos)
	{
		move_enemy_to_player(utils, p_pos, e_pos);
		free_ptr(e_pos);
	}
	free_ptr(p_pos);
}
