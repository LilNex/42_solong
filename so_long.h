/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:49:07 by ichaiq            #+#    #+#             */
/*   Updated: 2023/05/22 01:15:35 by ichaiq           ###   ########.fr       */
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

int	ft_error(char *s);

typedef struct s_map{
	char	**map;
	int 	width;
	int		height;
	int		count_c;
	int		count_e;
	int		count_p;
}				t_map;

typedef struct s_solong{
	char	*map_name;
	t_map	*map;

}				t_solong;


// LOADERS
void	load_assets(t_solong *utils);
void	load_map(char *name, t_solong *utils);
int		get_count_lines(char *name);
t_map 	*init_map(int lines_count);
void 	load_lines(char *mapname, t_solong *utils);
int		validate_map(t_map *map);


#endif