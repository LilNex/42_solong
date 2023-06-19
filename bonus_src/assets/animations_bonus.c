/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:09:33 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/19 18:41:56 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_player_animation(t_solong *utils)
{
	t_animation	*asset;

	asset = ft_calloc(1, sizeof(t_animation));
	asset->img = ft_calloc(4, sizeof(void *));
	asset->img[0] = load_xpm_file(utils,
			"./images/character_1.xpm");
	asset->img[1] = load_xpm_file(utils,
			"./images/character_2.xpm");
	asset->img[2] = load_xpm_file(utils,
			"./images/character_3.xpm");
	asset->len = 3;
	utils->a_data->player = asset;
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
	utils->a_data->enemy = asset;
}

void	load_player_assets(t_solong *utils)
{
	load_enemy_animation(utils);
	load_player_animation(utils);
}
