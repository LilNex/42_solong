/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:22:54 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 17:23:30 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_assets_file(t_solong *utils)
{
	utils->a_data = ft_calloc(1, sizeof(t_assets_data));
	utils->a_data->collectible = load_xpm_file(utils,
			"./images/c1.xpm");
	utils->a_data->backgroud = load_xpm_file(utils, "./images/grass.xpm");
	utils->a_data->wall = load_xpm_file(utils, "./images/tree.xpm");
	utils->a_data->enemy = load_xpm_file(utils, "./images/enemy_1.xpm");
	utils->a_data->player = load_xpm_file(utils,
			"./images/u1.xpm");
	utils->a_data->exit = load_xpm_file(utils,
			"./images/exit.xpm");
}

void	load_map(char *name, t_solong *utils)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error(utils, "Error while opening the map", 1);
	utils->map = init_map(get_count_lines(name, utils), utils);
	load_lines(fd, utils);
}

void	*load_xpm_file(t_solong *utils, char *path)
{
	int		size;
	void	*t;

	size = BLOCK_SIZE;
	t = mlx_xpm_file_to_image(utils->mlx, path, &size, &size);
	if (!t)
		ft_error(utils, "Error while loading an image file\n", 1);
	return (t);
}

void	*load_assets(t_solong *utils)
{
	int	fd;

	fd = open(utils->map_name, O_RDONLY);
	if (fd < 0)
		ft_error(utils, "Error while opening the map", 1);
	if (!utils->map_name)
		ft_error(utils, "Error on map name", 1);
	load_map(utils->map_name, utils);
	return (NULL);
}
