/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:03 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:12:27 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

/* If there still are targets left (Collectible or Exit) that could not be reached by the player, returns a non-zero value. */
static int	remaining_target(char **map)
{
	int	target;
	int	i;
	int	j;

	target = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				target++;
			j++;
		}
		i++;
	}
	return (target);
}
/* Starting from the player position, goes to every tile on the map accessible to the player and replaces it with a wall. */
static int	cover_map(char **map, int px, int py)
{
	map[px][py] = '1';
	if (map[px - 1][py] != '1')
		cover_map(map, px - 1, py);
	if (map[px][py + 1] != '1')
		cover_map(map, px, py + 1);
	if (map[px + 1][py] != '1')
		cover_map(map, px + 1, py);
	if (map[px][py - 1] != '1')
		cover_map(map, px, py - 1);
	return (0);
}

int	valid_path(t_map *map)
{
	cover_map(map->map_path_check, map->p_pos[0], map->p_pos[1]);
	if (remaining_target(map->map_path_check))
		return (0);
	else
		return (1);
}
