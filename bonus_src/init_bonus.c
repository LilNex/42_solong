/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:11:55 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 00:17:50 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_window(t_solong *utils)
{
	int	width;
	int	height;

	utils->moves = 0;
	utils->c_collected = 0;
	utils->_c_collected = 0;
	utils->exitflag = 0;
	utils->counter = 0;
	width = utils->map->width * BLOCK_SIZE;
	height = utils->map->height * BLOCK_SIZE;
	utils->mlx = mlx_init();
	utils->mlx_window = mlx_new_window(utils->mlx,
			width, height, GAME_NAME);
	load_assets_file(utils);
}

int	render_window(t_solong *utils)
{
	char	*moves;
	char	*tmp;

	do_actions(utils);
	if (utils->str_moves)
		free_ptr(utils->str_moves);
	tmp = ft_strdup("Moves : ");
	moves = ft_itoa(utils->moves);
	utils->str_moves = ft_strjoin(tmp, moves);
	free(tmp);
	free(moves);
	mlx_clear_window(utils->mlx, utils->mlx_window);
	render_background(utils);
	render_map(utils);
	mlx_string_put(utils->mlx, utils->mlx_window, 64,
		64, 0xFFFFFF, utils->str_moves);
	return (1);
}
