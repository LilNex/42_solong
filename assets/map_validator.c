/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:06:14 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/22 01:48:12 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_line(char *line)
{
    size_t i;
    
    printf("line : %s\n", line);
    i = 0;
    if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
        return (ft_error("Map should be closed by walls"), 0);
    while (i < ft_strlen(line))
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'P' &&
            line[i] != 'E' && line[i] != 'C' && line[i] != '1')
            return (ft_error("Map is invalid !"), 0);
        i++;
    }
    return (1);
}

int check_walls(t_map *map)
{
    int i;
    int y;

    i = 0;
    y = 0;
    while (map->map[y][i])
        if (map->map[0][i++] != '1')
            return 0;
    i = 0;
    while (map->map[map->height-1][i])
        if (map->map[0][i++] != '1')
            return 0;
    
    i = 0;
    while (map->map[y] != NULL && y < map->height)
    {
        if (!check_line(map->map[y++]))
            return (0);
    }
    
    return (1);
}


int validate_map(t_map *map)
{
    
    if ((map->count_e != 1) || (map->count_p != 1))
        return (ft_error("Map is invalid"), 0);
    if (!check_walls(map))
        return (ft_error("Map walls are invalid"), 0);

   


    return (1);
}
