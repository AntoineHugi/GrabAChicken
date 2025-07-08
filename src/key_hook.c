/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:45:13 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:04:23 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

int	exit_app(t_map *map)
{
	free_img(map);
	free_map(map);
	exit(1);
}
/* Resets moves and collectible count, and reinitialises the map. */
static void	reset_game(t_map *map)
{
	int	i;
	int	j;
	int	temp_move;
	int	temp_collect;

	i = 0;
	while (map->map_reset[i])
	{
		j = 0;
		while (map->map_reset[i][j])
		{
			map->map_array[i][j] = map->map_reset[i][j];
			j++;
		}
		i++;
	}
	temp_collect = map->collect_count;
	temp_move = map->moves;
	init_game(map);
	map->old_collect_count = temp_collect;
	map->old_moves = temp_move;
}
/* Checks for WASD of arrow buttons on keyboard, as well as R for reset and ESC for exit. */
int	key_hook(int keycode, t_map *map)
{
	if (keycode == 65362 || keycode == 119)
		check_move(map, UP);
	if (keycode == 65364 || keycode == 115)
		check_move(map, DOWN);
	if (keycode == 65361 || keycode == 97)
		check_move(map, LEFT);
	if (keycode == 65363 || keycode == 100)
		check_move(map, RIGHT);
	if (keycode == 114)
		reset_game(map);
	if (keycode == 65307)
		exit_app(map);
	render_map(map);
	return (0);
}
