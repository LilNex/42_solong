/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:09:33 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/21 18:58:15 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_player_animation(t_solong *utils)
{
	t_animation	*a;

	a = ft_calloc(1, sizeof(t_animation));
	a->img = ft_calloc(9, sizeof(void *));
	a->img[0] = load_xpm_file(utils, "./images/u1.xpm");
	a->img[1] = load_xpm_file(utils, "./images/u2.xpm");
	a->img[2] = load_xpm_file(utils, "./images/u3.xpm");
	a->img[3] = load_xpm_file(utils, "./images/u4.xpm");
	a->img[4] = load_xpm_file(utils, "./images/u5.xpm");
	a->img[5] = load_xpm_file(utils, "./images/u6.xpm");
	a->img[6] = load_xpm_file(utils, "./images/u7.xpm");
	a->img[7] = load_xpm_file(utils, "./images/u8.xpm");
	a->len = 8;
	a->last = 0;
	utils->a_data->player = a;
}

void	load_enemy_animation(t_solong *utils)
{
	t_animation	*asset;

	asset = ft_calloc(1, sizeof(t_animation));
	asset->img = ft_calloc(4, sizeof(void *));
	asset->img[0] = load_xpm_file(utils,
			"./images/enemy_1.xpm");
	asset->img[1] = load_xpm_file(utils,
			"./images/enemy_2.xpm");
	asset->img[2] = load_xpm_file(utils,
			"./images/enemy_3.xpm");
	asset->len = 3;
	asset->last = 0;
	utils->a_data->enemy = asset;
}

void	load_collectible_asset(t_solong *utils)
{
	t_animation	*asset;

	asset = ft_calloc(1, sizeof(t_animation));
	asset->img = ft_calloc(5, sizeof(void *));
	asset->img[0] = load_xpm_file(utils,
			"./images/c1.xpm");
	asset->img[1] = load_xpm_file(utils,
			"./images/c2.xpm");
	asset->img[2] = load_xpm_file(utils,
			"./images/c3.xpm");
	asset->img[3] = load_xpm_file(utils,
			"./images/c4.xpm");
	asset->len = 4;
	asset->last = 0;
	utils->a_data->collectible = asset;
}

void	load_anims_assets(t_solong *utils)
{
	load_collectible_asset(utils);
	load_enemy_animation(utils);
	load_player_animation(utils);
}
