/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:35:06 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 17:16:50 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_solong *utils)
{
	int		x;
	char	**map;

	x = 0;
	map = utils->map->map;
	while (map[x])
		free(map[x++]);
	x = 0;
	map = utils->map->_map;
	while (map[x])
		free(map[x++]);
	free(utils->map->map);
	free(utils->map->_map);
	free(utils->map);
}

void	free_mlx(t_solong *utils)
{
	if (utils->mlx && utils->mlx_window)
		mlx_destroy_window(utils->mlx, utils->mlx_window);
	if (utils->str_moves)
		free_ptr(utils->str_moves);
}

void	free_animations(void *mlx_ptr, t_animation *anim)
{
	int	x;

	x = 0;
	while (anim->img[x] && x < anim->len)
		mlx_destroy_image(mlx_ptr, anim->img[x++]);
	free_ptr(anim->img);
}

void	free_assets(t_solong *utils)
{
	mlx_destroy_image(utils->mlx, utils->a_data->backgroud);
	mlx_destroy_image(utils->mlx, utils->a_data->exit);
	mlx_destroy_image(utils->mlx, utils->a_data->wall);
	free_animations(utils->mlx, utils->a_data->player);
	free_animations(utils->mlx, utils->a_data->enemy);
	free_animations(utils->mlx, utils->a_data->collectible);
	free_ptr(utils->a_data->player);
	free_ptr(utils->a_data->enemy);
	free_ptr(utils->a_data->collectible);
	free_ptr(utils->a_data);
}

void	clean_exit(t_solong *utils)
{
	if (utils->map)
		free_map(utils);
	if (utils->a_data)
		free_assets(utils);
	free_mlx(utils);
	free(utils);
}
