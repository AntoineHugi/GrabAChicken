/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialization_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:54:44 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/10 15:54:48 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

static t_sprite	new_sprite(void *mlx, char *path, t_map *map)
{
	t_sprite	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_map("Couldn't find a sprite file.", map);
	return (sprite);
}

void	init_sprites(t_map *map)
{
	map->chicken = new_sprite(map->mlx, CHICKEN_XPM, map);
	map->player = new_sprite(map->mlx, PLAYER_XPM, map);
	map->wall = new_sprite(map->mlx, WALL_XPM, map);
	map->floor = new_sprite(map->mlx, FLOOR_XPM, map);
	map->exit = new_sprite(map->mlx, EXIT_XPM, map);
	map->won = new_sprite(map->mlx, WIN_XPM, map);
}
