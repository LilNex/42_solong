/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:49:07 by ichaiq            #+#    #+#             */
/*   Updated: 2023/06/20 02:25:11 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../includes/libft/libft.h"
# include "../includes/gnl/get_next_line_bonus.h"
# include <fcntl.h>
# include <mlx.h>

# define BLOCK_SIZE 64
# define GAME_NAME "so_long"
# define RANGE_ENEMY 5
# define SPEED_FACTOR 5
# define HARD_MODE 0

typedef struct s_map{
	char	**map;
	char	**_map;
	int		width;
	int		height;
	int		count_c;
	int		count_e;
	int		count_p;
}				t_map;

// typedef struct s_asset{
// 	void	*img;
// 	char	*name;
// 	int		w;
// 	int		h;
// 	char	*path;
// }				t_asset;

typedef struct s_animation{
	void	**img;
	int		len;
	int		last;
	int		current;
}				t_animation;

typedef struct s_assets_data{
	void		*wall;
	void		*backgroud;
	t_animation	*player;
	void		*exit;
	t_animation	*enemy;
	t_animation	*collectible;

}				t_assets_data;

typedef struct s_solong{
	char			*map_name;
	t_map			*map;
	t_assets_data	*a_data;
	void			*mlx;
	void			*mlx_window;
	int				c_collected;
	int				_c_collected;
	int				exitflag;
	int				moves;
	char			*str_moves;
	int				counter;

}				t_solong;

typedef struct s_position{
	int		x;
	int		y;

}				t_position;

// LOADERS
void		f(void);
int			ft_error(t_solong *utils, char *s, int error);
void		*load_assets(t_solong *utils);
void		load_map(char *name, t_solong *utils);
int			get_count_lines(char *name, t_solong *utils);
t_map		*init_map(int lines_count, t_solong *utils);
void		load_lines(int fd, t_solong *utils);
int			validate_map(t_map *map, t_solong *utils);
int			check_line(const char *line, t_solong *utils);
void		*load_xpm_file(t_solong *utils, char *path);
void		init_window(t_solong *utils);
int			render_window(t_solong *utils);
int			handle_press(int keycode, void *params);
void		render_background(t_solong *utils);
void		render_map(t_solong *utils);
void		load_assets_file(t_solong *utils);
void		update_counter(t_solong *utils);
void		free_map(t_solong *utils);
void		free_assets(t_solong *utils);
void		clean_exit(t_solong *utils);
int			has_valid_path(t_solong *u, char **map, int x, int y);
t_position	*get_position(int x, int y);
t_position	*get_player_position(t_solong *utils);
void		load_player_assets(t_solong *utils);
int			do_actions(t_solong *utils);
t_position	*search_nearest_enemy(t_solong *utils, t_position *p_pos);
void		move_enemy(t_solong *utils, t_position	*p_pos);


#endif