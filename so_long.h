/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:49:07 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/30 16:21:33 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"
# include <fcntl.h>
# include <mlx.h>

#define BLOCK_SIZE 64

int	ft_error(char *s);

typedef struct s_map{
	char	**map;
	int 	width;
	int		height;
	int		count_c;
	int		count_e;
	int		count_p;
}				t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// typedef struct	s_asset {
// 	void	*img;
// 	char	*name;
// 	int 	w;
// 	int 	h;
// 	char	*path;
// }				t_asset;

typedef struct	s_asset {
	t_list	*img;
	t_list 	*last_used;
}				t_asset;
typedef struct s_assets_data{
	t_asset	*wall;
	t_asset	*player;
	t_asset	*exit;
	t_asset	*enemy;
	t_asset	*collectible;

}				t_assets_data;

typedef struct s_solong{
	char			*map_name;
	t_map			*map;
	t_assets_data 	*a_data;
	void			*mlx;
	void			*mlx_window;
	int 			c_collected;


}				t_solong;


typedef struct s_position{
	int		x;
	int		y;

}				t_position;


// LOADERS
void	*load_assets(t_solong *utils);
void	load_map(char *name, t_solong *utils);
int		get_count_lines(char *name);
t_map 	*init_map(int lines_count);
void 	load_lines(char *mapname, t_solong *utils);
int		validate_map(t_map *map);
t_list 	*load_xpm_file(t_solong *utils, char *path);

void init_window(t_solong *utils);
int render_window(t_solong *utils);
int handle_press(int keycode, void* params);

#endif