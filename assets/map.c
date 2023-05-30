/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:37:48 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 00:48:52 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map *init_map(int lines_count)
{
    t_map *map;

    map = malloc(1* sizeof(t_map));
    if (!map)
        return (ft_error("Error while mallocing !"), NULL);
    map->height = lines_count;
    map->map = ft_calloc((map->height + 1), sizeof(char*));
    map->count_c = 0;
    map->count_p = 0;
    map->count_e = 0;
    return (map);
}

int get_count_lines(char *name)
{
    int fd;
	int nbrLines;
    
	fd = open(name, O_RDONLY);
    if (fd < 0)
		ft_error("Error while opening the map");
    nbrLines = 0;
    while (get_next_line(fd))
        nbrLines++;
    return nbrLines;
}

void update_counts(char *line, t_map *map)
{
    int i;

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

void load_lines(char *mapname, t_solong *utils)
{
    int     fd;
    char    *raw_line;
    char    *line;
    char    *tmp;
    int     i;

    i = 0;
    line = NULL;
    fd = open(mapname, O_RDONLY);
	if (fd < 0)
		ft_error("Error while opening the map");
    while ((raw_line = get_next_line(fd)) != NULL )
    {   
        tmp = ft_strtrim(raw_line, "\n");
        if (i == 0)
            utils->map->width = ft_strlen(tmp);
        if (ft_strlen(tmp) != (size_t)utils->map->width)
		    ft_error("Dimension of map is invalid");
        update_counts(tmp, utils->map);
        utils->map->map[i++] = tmp;
        free_ptr(raw_line);
    }
    free_ptr(raw_line);
    validate_map(utils->map);

}