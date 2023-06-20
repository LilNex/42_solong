/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:52:53 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 17:17:34 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_counter(t_solong *utils)
{
	char	*str1;
	char	*result;
	char	*moves;

	str1 = ft_strdup("Moves : ");
	moves = ft_itoa(utils->moves);
	result = ft_strjoin(str1, moves);
	ft_putstr_fd(result, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free_ptr(str1);
	free_ptr(moves);
	free_ptr(result);
}

void	handle_exit(t_solong *utils, t_position *pos)
{
	if (utils->map->count_c == utils->c_collected)
	{
		free_ptr(pos);
		ft_error(utils, "You won!", 0);
	}
}

void	move_player(t_solong *utils, int x, int y)
{
	t_position	*p_pos;
	char		**map;

	p_pos = get_player_position(utils);
	map = utils->map->map;
	if (map[p_pos->x][p_pos->y] == 'P')
	{
		if (map[p_pos->x + x][p_pos->y + y] == 'E')
			handle_exit(utils, p_pos);
		else if (map[p_pos->x + x][p_pos->y + y] == 'B')
		{
			free_ptr(p_pos);
			ft_error(utils, "You hitted an enemy !", 0);
		}
		else if (map[p_pos->x + x][p_pos->y + y] != '1')
		{
			map[p_pos->x][p_pos->y] = '0';
			if (map[p_pos->x + x][p_pos->y + y] == 'C')
				utils->c_collected++;
			map[p_pos->x + x][p_pos->y + y] = 'P';
			utils->moves++;
		}
	}
	free_ptr(p_pos);
}

int	handle_press(int keycode, void *params)
{
	t_solong	*u;

	u = (t_solong *)params;
	if (keycode == 123)
		move_player(u, 0, -1);
	else if (keycode == 126)
		move_player(u, -1, 0);
	else if (keycode == 124)
		move_player(u, 0, 1);
	else if (keycode == 125)
		move_player(u, 1, 0);
	else if (keycode == 53)
		ft_error(u, "You exited the game.", 0);
	if (HARD_MODE)
		move_enemy(u, get_player_position(u));
	return (0);
}
