/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:37:48 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/17 13:03:39 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*init_map(int lines_count, t_solong *utils)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (ft_error(utils, "Error while mallocing !"), NULL);
	map->height = lines_count;
	map->map = ft_calloc((map->height + 1), sizeof(char *));
	map->count_c = 0;
	map->count_p = 0;
	map->count_e = 0;
	return (map);
}

int	get_count_lines(char *name, t_solong *utils)
{
	int		fd;
	int		nbr_lines;
	char	*tmp;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error(utils, "Error while opening the map");
	nbr_lines = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		nbr_lines++ ;
		free_ptr(tmp);
		tmp = get_next_line(fd);
	}
	free_ptr(tmp);
	return (nbr_lines);
}

void	update_counts(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && i < map->width - 1)
	{
		if (line[i] == 'P')
			map->count_p++;
		else if (line[i] == 'E')
			map->count_e++;
		else if (line[i] == 'C')
			map->count_c++;
		i++;
	}
}

void	load_lines(int fd, t_solong *utils)
{
	char	*raw_line;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = NULL;
	raw_line = get_next_line(fd);
	while (raw_line != NULL)
	{
		tmp = ft_strtrim(raw_line, "\n");
		if (i == 0)
			utils->map->width = ft_strlen(tmp);
		if (ft_strlen(tmp) != (size_t)utils->map->width)
			ft_error(utils, "Dimension of map is invalid");
		update_counts(tmp, utils->map);
		utils->map->map[i++] = tmp;
		free_ptr(raw_line);
		raw_line = get_next_line(fd);
	}
	free_ptr(raw_line);
	validate_map(utils->map, utils);
}
