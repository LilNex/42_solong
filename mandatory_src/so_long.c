/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:59:15 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/17 12:56:34 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_solong *utils, char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
	clean_exit(utils);
	exit(500);
}

void	f(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_solong	*s_utils;

	atexit(f);
	s_utils = ft_calloc(1, sizeof(t_solong));
	if (ac >= 2)
	{
		if (av[1])
			s_utils->map_name = av[1];
		load_assets(s_utils);
		init_window(s_utils);
		render_window(s_utils);
		mlx_key_hook(s_utils->mlx_window, handle_press, s_utils);
		mlx_loop(s_utils->mlx);
		clean_exit(s_utils);
	}
	else
		ft_error(s_utils, "You should specify the map");
	clean_exit(s_utils);
}
