/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:48:19 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:19:23 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAB_A_CHICKEN_H
# define GRAB_A_CHICKEN_H

# define WIN_X 1024
# define WIN_Y 512
# define PIX 32
# define UP	1
# define DOWN	2
# define RIGHT	3
# define LEFT	4
# define RED 16711680
# define GREEN 65280
# define BLUE 255

# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define CHICKEN_XPM		"assets/sprites/chicken.xpm"
# define PLAYER_XPM			"assets/sprites/player.xpm"
# define EXIT_XPM			"assets/sprites/exit.xpm"
# define WIN_XPM			"assets/sprites/win.xpm"

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_sprite {
	void	*xpm_ptr;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_game {
	void		*mlx;
	void		*win;
}				t_game;

typedef struct s_menu {
	void		*mlx;
	void		*win;
}				t_menu;

typedef struct s_map {
	char		*map_raw;
	char		*line;
	char		**map_array;
	char		**map_path_check;
	char		**map_reset;
	int			height;
	int			width;
	int			win_x;
	int			win_y;
	int			p_pos[2];
	int			e_pos[2];
	int			moves;
	int			old_moves;
	int			collect_count;
	int			old_collect_count;
	int			game_won;
	int			win_clear;
	void		*mlx;
	void		*win;
//	t_img		*img;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	player;
	t_sprite	chicken;
	t_sprite	exit;
	t_sprite	won;
}				t_map;

int		map_validation(t_map *map);
int		key_hook(int keycode, t_map *map);
int		valid_path(t_map *map);
int		exit_app(t_map *map);
int		render_map(t_map *map);
void	render_win_screen(t_map *map);
void	render_sprite(t_map *map, t_sprite sprite, int height, int width);
void	check_move(t_map *map, int direction);
void	error_input(char *str);
void	error_map(char *str, t_map *map);
void	init_game(t_map *map);
void	init_sprites(t_map *map);
void	free_array(char **array);
void	free_img(t_map *map);
void	free_map(t_map *map);
t_map	*map_creation(char *map_file);

#endif
