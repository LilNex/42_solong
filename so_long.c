/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:59:15 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/22 00:39:07 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_error(char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
	exit(0);
}


int main(int ac, char **av)
{
	t_solong	*s_utils;

	s_utils = ft_calloc(1, sizeof(t_solong));
	if (ac >= 2)
	{
		if (av[1])
			s_utils->map_name = av[1];

		load_assets(s_utils);

		printf("hello world !");
	}
	else ft_error("You should specify the map");
}