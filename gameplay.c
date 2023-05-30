/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:52:53 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 14:21:54 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position *get_position(int x, int y)
{
	t_position *pos;

	pos = ft_calloc(1 , sizeof(t_position));
	if (!pos)
		return (pos);
	pos->x = x;
	pos->y = y;
	return (pos);
}

t_position *get_player_position(t_solong *utils)
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
	return NULL;
}

void	move_player(t_solong *utils, int x, int y)
{
	t_position	*p_pos;
	char		**map;

	p_pos = get_player_position(utils);
	map = utils->map->map;
	if (map[p_pos->x][p_pos->y] == 'P')
	{
		if (map[(p_pos->x) + x][(p_pos->y) + y] != '1')
		{
			map[(p_pos->x)][(p_pos->y)] = '0';
			if (map[(p_pos->x) + x][(p_pos->y) + y] == 'C')
				utils->c_collected++;
			if (map[(p_pos->x) +x][(p_pos->y) +y] == 'E')
				ft_error("You hitted an enemy !");
			
			map[(p_pos->x) +x][(p_pos->y) +y] = 'P';
		}
	}
}

int	handle_press(int keycode, void *params)
{
	t_solong	*u;

	u = (t_solong *)params;
	if (keycode == 123)
		move_player(u, 0, -1);
	else if (keycode == 126)
		move_player(u, -1, 0);
	else if (keycode == 124)
		move_player(u, 0, 1);
	else if (keycode == 125)
		move_player(u, 1, 0);

	//53 for ESC

	render_window(u);
	return (0);
}
