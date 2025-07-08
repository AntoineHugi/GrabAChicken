/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:45:34 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/10 14:45:36 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

static int	count_collectibles(char **map_array)
{
	int	i;
	int	j;
	int	collect_count;

	i = 0;
	collect_count = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'C')
				collect_count++;
			j++;
		}
		i++;
	}
	return (collect_count);
}

static void	init_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == 'P')
			{
				map->p_pos[0] = i;
				map->p_pos[1] = j;
			}
			if (map->map_array[i][j] == 'E')
			{
				map->e_pos[0] = i;
				map->e_pos[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_map *map)
{
	map->moves = 0;
	map->old_moves = 0;
	map->collect_count = count_collectibles(map->map_array);
	map->old_collect_count = 0;
	init_position(map);
	map->game_won = 0;
	map->win_clear = 0;
}
