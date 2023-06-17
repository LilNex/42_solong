/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:58:25 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/17 12:32:15 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_solong *utils)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (utils->map->map[x])
	{
		while (utils->map->map[x][y])
		{
			if (utils->map->map[x][y])
				mlx_put_image_to_window(utils->mlx, utils->mlx_window,
					(utils->a_data->backgroud), (y * BLOCK_SIZE),
					(x * BLOCK_SIZE));
			y++;
		}
		x++;
		y = 0;
	}
}

void	render_block(t_solong *utils, int x, int y)
{
	if (utils->map->map[x][y] == '1')
		mlx_put_image_to_window(utils->mlx, utils->mlx_window,
			utils->a_data->wall, (y * BLOCK_SIZE), (x * BLOCK_SIZE));
	else if (utils->map->map[x][y] == 'P')
		mlx_put_image_to_window(utils->mlx, utils->mlx_window,
			utils->a_data->player, (y * BLOCK_SIZE), (x * BLOCK_SIZE));
	else if (utils->map->map[x][y] == 'E')
		mlx_put_image_to_window(utils->mlx, utils->mlx_window,
			utils->a_data->exit, (y * BLOCK_SIZE), (x * BLOCK_SIZE));
	else if (utils->map->map[x][y] == 'C')
		mlx_put_image_to_window(utils->mlx, utils->mlx_window,
			utils->a_data->collectible, (y * BLOCK_SIZE), (x * BLOCK_SIZE));
}

void	render_map(t_solong *utils)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (utils->map->map[x])
	{
		while (utils->map->map[x][y])
		{
			render_block(utils, x, y);
			y++;
		}
		x++;
		y = 0;
	}
}
