/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:11:55 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 19:08:50 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void load_assets_data(t_solong *u, char *path,)

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
    puts("ft_calloc");
	
	utils->a_data = ft_calloc(1, sizeof(t_assets_data));
	utils->a_data->player = (t_asset *)ft_calloc(1, sizeof(t_asset));
	utils->a_data->wall = (t_asset *)ft_calloc(1, sizeof(t_asset));
	utils->a_data->background = (t_asset *)ft_calloc(1, sizeof(t_asset));
	utils->a_data->enemy = (t_asset *)ft_calloc(1, sizeof(t_asset));
	utils->a_data->exit = (t_asset *)ft_calloc(1, sizeof(t_asset));
	utils->a_data->collectible = ft_calloc(1, sizeof(t_asset*));

	ft_lstadd_back(&utils->a_data->player->img, load_xpm_file(utils, "./assets/images/char_1.xpm"));
	ft_lstadd_back(&utils->a_data->player->img, load_xpm_file(utils, "./assets/images/char_2.xpm"));
	ft_lstadd_back(&utils->a_data->player->img, load_xpm_file(utils, "./assets/images/char_3.xpm"));
    puts("t_asset");
	
	ft_lstadd_back(&utils->a_data->background->img, load_xpm_file(utils, "./assets/images/grass.xpm"));
	ft_lstadd_back(&utils->a_data->wall->img, load_xpm_file(utils, "./assets/images/rock.xpm"));
	// ft_lstadd_back(&utils->a_data->wall->img, load_xpm_file(utils, "./assets/images/wall.xpm"));
	ft_lstadd_back(&utils->a_data->enemy->img, load_xpm_file(utils, "./assets/images/enemy.xpm"));
	ft_lstadd_back(&utils->a_data->exit->img, load_xpm_file(utils, "./assets/images/exit.xpm"));

}
