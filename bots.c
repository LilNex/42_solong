/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:02:16 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/07 17:36:56 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position *search_nearest_enemy(t_solong *utils,t_position *p_pos)
{
    char    **map;
    int     x;
    int     y;

    x = 0;
    y = 0;
    map = utils->map->map;
    while (x < RANGE_ENEMY)
    {
        while (y < RANGE_ENEMY)
        {
            printf("x : %d; y : %d\n",p_pos->x + x, p_pos->y + y);
            if (map[p_pos->x + x] && map[p_pos->x + x][p_pos->y + y] == 'E')
                return (get_position(x, y));
            else y++;
        }
        
        x++;
    }
    
    return (NULL);
}

void move_enemy(t_solong *utils,t_position	*p_pos)
{   
    t_position *e_pos;

    e_pos = search_nearest_enemy(utils, p_pos);
    if (e_pos)
    {
        printf("x : %d; y : %d\n",e_pos->x, e_pos->y);
    }
}
