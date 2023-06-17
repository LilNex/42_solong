/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:11:55 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/17 12:31:26 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_solong *utils)
{
	int	width;
	int	height;

	utils->moves = 0;
	utils->c_collected = 0;
	width = utils->map->width * BLOCK_SIZE;
	height = utils->map->height * BLOCK_SIZE;
	utils->mlx = mlx_init();
	utils->mlx_window = mlx_new_window(utils->mlx,
			width, height, GAME_NAME);
	load_assets_file(utils);
}

void	render_window(t_solong *utils)
{
	mlx_clear_window(utils->mlx, utils->mlx_window);
	render_background(utils);
	render_map(utils);
}
