/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:25:13 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 19:09:24 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *render_animation(t_asset *u)
{
    puts("test");

	if (u->last_used && u->last_used->next)
    {
        u->last_used = u->last_used->next;
        puts("if render_animation");
        return u->last_used->content;
    }
    else 
    {
        u->last_used = u->img;
        puts("else render_animation");
		printf("ptr returned : %p\n",u->img->content);
        return u->img->content;
    }
}

void    render_block(t_solong *u, int *x, int *y)
{
    puts("render_block");

	if (u->map->map[*x][*y] == '1')
		mlx_put_image_to_window(u->mlx, u->mlx_window,
			render_animation(u->a_data->wall), (*y*BLOCK_SIZE), (*x*BLOCK_SIZE));
	else if (u->map->map[*x][*y] == 'P')
		mlx_put_image_to_window(u->mlx, u->mlx_window,
			render_animation(u->a_data->player), (*y*BLOCK_SIZE), (*x*BLOCK_SIZE));
	else if (u->map->map[*x][*y] == 'E')
		mlx_put_image_to_window(u->mlx, u->mlx_window,
			render_animation(u->a_data->enemy), (*y*BLOCK_SIZE), (*x*BLOCK_SIZE));
	else if (u->map->map[*x][*y] == 'C')
		mlx_put_image_to_window(u->mlx, u->mlx_window,
			render_animation(u->a_data->player), (*y*BLOCK_SIZE), (*x*BLOCK_SIZE));
}
void    render_background(t_solong *utils)
{
    puts("render_background");

	int x;
	int y;

	x = 0;
	y = 0;
	while (utils->map->map[x])
	{
		while (utils->map->map[x][y])
		{
			if (utils->map->map[x][y])
			mlx_put_image_to_window(utils->mlx, utils->mlx_window,
				render_animation(utils->a_data->background), (y*BLOCK_SIZE), (x*BLOCK_SIZE));
			y++;
		}
		x++;
		y = 0;
	}
	
	
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
			render_block(utils, &x, &y);
			y++;
		}
		x++;
		y = 0;
	}
}


int render_window(t_solong *utils)
{
	mlx_clear_window(utils->mlx, utils->mlx_window);
	render_background(utils);
	render_map(utils);
	return (1);
}

