/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:59:15 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/01 00:00:19 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
	exit(0);
}

void f()
{
	system("leaks so_long");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(int ac, char **av)
{
	t_solong	*s_utils;
	(void)av;
	// atexit(f);
	s_utils = ft_calloc(1, sizeof(t_solong));
	if (ac >= 1)
	{
		if (av[1])
			s_utils->map_name = av[1];
		load_assets(s_utils);
		s_utils->c_collected = 0;
		s_utils->moves = 0;
		init_window(s_utils);
		render_window(s_utils);
		// render_moves(s_utils);
		mlx_key_hook(s_utils->mlx_window, handle_press, s_utils);
		// mlx_loop_hook(s_utils->mlx,render_window,s_utils);
		mlx_loop(s_utils->mlx);
		
	}
	else ft_error("You should specify the map");
}