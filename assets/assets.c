/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:22:54 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 01:24:31 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_map(char *name, t_solong *utils)
{
	int fd;

	(void)utils;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error("Error while opening the map");
	utils->map = init_map(get_count_lines(name));
	load_lines(name, utils);

}

void *load_xpm_file(t_solong *utils, char *path)
{
	int size;
	
	size = BLOCK_SIZE;
	puts("before");

	void *t = mlx_xpm_file_to_image(utils->mlx, path, &size, &size);
	puts("after");
	if (!t)
		printf("Error while loading file\n");
	return (t);
}

void*	load_assets(t_solong *utils)
{
	int fd;
	fd = open(utils->map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error while opening the map");
	if (!utils->map_name)
		ft_error("Error on map name");
	load_map(utils->map_name, utils);
	
	return NULL;
}
