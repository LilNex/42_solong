/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:09:45 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 00:20:06 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	action_one(t_solong *utils)
{
	printf("Doing action ...\n");
	move_enemy(utils, get_player_position(utils));
}

int	do_actions(t_solong *utils)
{
	if (utils->counter % 100 == 0)
		action_one(utils);
	utils->counter++;
	if (utils->counter > 1000)
		utils->counter = 0;
	return (0);
}
