/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:11:55 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 01:22:52 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void init_window(t_solong *utils)
{
    int width;
    int height;

    width = utils->map->width * BLOCK_SIZE;
    height = utils->map->height * BLOCK_SIZE;
    
    printf("width :  %d\n",width);
    printf("height : %d\n",height);

    utils->mlx = mlx_init();
    utils->mlx_window = mlx_new_window(utils->mlx, width, height, "Hello World!");
    
    utils->a_data = ft_calloc(1, sizeof(t_assets_data));
	utils->a_data->wall = load_xpm_file(utils, "./assets/images/wall.xpm");
	utils->a_data->enemy = load_xpm_file(utils, "./assets/images/enemy.xpm");
	utils->a_data->player = load_xpm_file(utils, "./assets/images/character.xpm");

}

void render_map(t_solong *utils)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (utils->map->map[x])
    {
        while (utils->map->map[x][y])
        {
            if (utils->map->map[x][y] == '1')
                mlx_put_image_to_window(utils->mlx, utils->mlx_window,
                    utils->a_data->wall, (y*BLOCK_SIZE), (x*BLOCK_SIZE));
            else if (utils->map->map[x][y] == 'P')
                mlx_put_image_to_window(utils->mlx, utils->mlx_window,
                    utils->a_data->player, (y*BLOCK_SIZE), (x*BLOCK_SIZE));
            else if (utils->map->map[x][y] == 'E')
                mlx_put_image_to_window(utils->mlx, utils->mlx_window,
                    utils->a_data->enemy, (y*BLOCK_SIZE), (x*BLOCK_SIZE));
                    else if (utils->map->map[x][y] == 'C')
                mlx_put_image_to_window(utils->mlx, utils->mlx_window,
                    utils->a_data->player, (y*BLOCK_SIZE), (x*BLOCK_SIZE));
            
            y++;
        }
        x++;
        y = 0;
    }
}


void render_window(t_solong *utils)
{
    mlx_clear_window(utils->mlx, utils->mlx_window);
    render_map(utils);
    
}


