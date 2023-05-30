/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:52:53 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 01:26:34 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_position *get_player_position(t_solong *utils)
{
    
    int x;
    int y;
    t_position *pos;

    x = 0;
    y = 0;
    pos = ft_calloc(1, sizeof(pos));
    while (utils->map->map[x])
    {
        while (utils->map->map[x][y])
        {
            
            if (utils->map->map[x][y] == 'P')
            {
                pos->x = x;
                pos->y = y;
                return pos;
            }
            y++;
        }
        x++;
        y = 0;
    }
    pos->x = -1;
    pos->y = -1;
    return pos;
}

void move_player(t_solong *utils, int x, int y)
{
    t_position *p_pos;
    char **map;

    p_pos = get_player_position(utils);
    map = utils->map->map;
    if (map[p_pos->x][p_pos->y] == 'P')
    {
        if (map[(p_pos->x) +x][(p_pos->y) +y] != '1')
        {
            map[(p_pos->x)][(p_pos->y)] = '0';
            if (map[(p_pos->x) +x][(p_pos->y) +y] == 'C')
                utils->c_collected++;
            if (map[(p_pos->x) +x][(p_pos->y) +y] == 'E')
                ft_error("You hitted an enemy !");
            
            map[(p_pos->x) +x][(p_pos->y) +y] = 'P';
        }
    }
}

int handle_press(int keycode, void* params)
{
    t_solong *u;

    u = (t_solong *)params;
    if (keycode == 123)
        move_player(u, 0, -1);
    else if (keycode == 126)
        move_player(u, -1, 0);
    else if (keycode == 124)
        move_player(u, 0, 1);
    else if (keycode == 125)
        move_player(u, 1, 0);

    //53 for ESC

    render_window(u);
    return (0);
}
