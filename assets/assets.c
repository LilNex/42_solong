/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:22:54 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/11 21:45:11 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_map(char *name, t_solong *utils)
{
	int	fd;

	(void)utils;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error("Error while opening the map");
	utils->map = init_map(get_count_lines(name));
	load_lines(name, utils);

}

t_list	*load_xpm_file(t_solong *utils, char *path)
{
	int		size;
	void	*t;
	size = BLOCK_SIZE;
	t = mlx_xpm_file_to_image(utils->mlx, path, &size, &size);
	if (!t)
		ft_error("Error while loading file\n");
	printf("t : %p\n",t);
	return (ft_lstnew(t));
}

void	*load_assets(t_solong *utils)
{
	int	fd;

	fd = open(utils->map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error while opening the map");
	if (!utils->map_name)
		ft_error("Error on map name");
	load_map(utils->map_name, utils);
	return (NULL);
}
