/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:06:14 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/17 13:10:13 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_line(const char *line, t_solong *utils)
{
	size_t	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		return (ft_error(utils, "Map should be closed by walls"), 0);
	while (i < ft_strlen(line))
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C' && line[i] != '1')
			return (ft_error(utils, "Map is invalid !"), 0);
		i++;
	}
	return (1);
}

int	check_walls(t_map *map, t_solong *utils)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map->map[y] != NULL && y < map->height)
		if (!check_line(map->map[y++], utils))
			return (0);
	y = 0;
	i = 0;
	while (map->map[y][i])
		if (map->map[0][i++] != '1')
			return (0);
	i = 0;
	while (map->map[map->height - 1][i])
		if (map->map[map->height - 1][i++] != '1')
			return (0);
	return (1);
}

int	validate_map(t_map *map, t_solong *utils)
{
	if ((map->count_e != 1) || (map->count_p != 1))
		return (ft_error(utils, "Map is invalid"), 0);
	if (!check_walls(map, utils))
		return (ft_error(utils, "Map walls are invalid"), 0);
	return (1);
}
/*
int	has_valid_path(t_solong *u, char **map, int x, int y)
{
	if (map[x][y] == '1')
		return (0);
	else if (map[x][y] == 'C')
	{
		map[x][y] = '0';
		u->_c_collected++;
	}
	if (map[x][y] == 'E' && u->_c_collected == u->map->count_c)
		return (1);
	if (has_valid_path(u, map, x + 1, y))
		return (1);
	else if (has_valid_path(u, map, x - 1, y))
		return (1);
	else if (has_valid_path(u, map, x, y + 1))
		return (1);
	else if (has_valid_path(u, map, x, y - 1))
		return (1);
	else
		return (0);
}
*/
