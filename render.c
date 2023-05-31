/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:25:13 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/01 00:19:11 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *render_animation(t_asset *u)
{
    // puts("test");

	if (u->last_used && u->last_used->next)
    {
        u->last_used = u->last_used->next;
        return u->last_used->content;
    }
    else 
    {
        u->last_used = u->img;
        return u->img->content;
    }
}

void    render_block(t_solong *u, int *x, int *y)
{
    // puts("render_block");

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
    // puts("render_background");

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
	char *moves;
	char *tmp;
	
	mlx_clear_window(utils->mlx, utils->mlx_window);
	if(utils->str_moves)
		free_ptr(utils->str_moves);
	tmp = ft_strdup("Moves : ");
	moves = ft_itoa(utils->moves);
	utils->str_moves = ft_strjoin(tmp, moves);
	free(tmp);
	free(moves);
	render_background(utils);
	render_map(utils);
	mlx_string_put(utils->mlx,utils->mlx_window, 64 ,64,255,utils->str_moves);
	return (1);
}


