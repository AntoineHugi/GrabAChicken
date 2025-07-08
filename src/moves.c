/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:08 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:14:08 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

static void	move_up(t_map *map)
{
	if (map->map_array[map->p_pos[0] - 1][map->p_pos[1]] != '1')
	{
		if (map->map_array[map->p_pos[0] - 1][map->p_pos[1]] == 'C')
		{
			map->old_collect_count = map->collect_count;
			map->collect_count--;
		}
		if (map->map_array[map->p_pos[0] - 1][map->p_pos[1]] == 'E' && map->collect_count == 0)
			map->game_won = 1;
		map->map_array[map->p_pos[0] - 1][map->p_pos[1]] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[0]--;
		map->old_moves = map->moves;
		map->moves++;
	}
}

static void	move_down(t_map *map)
{
	if (map->map_array[map->p_pos[0] + 1][map->p_pos[1]] != '1')
	{
		if (map->map_array[map->p_pos[0] + 1][map->p_pos[1]] == 'C')
		{
			map->old_collect_count = map->collect_count;
			map->collect_count--;
		}
		if (map->map_array[map->p_pos[0] + 1][map->p_pos[1]] == 'E' && map->collect_count == 0)
			map->game_won = 1;
		map->map_array[map->p_pos[0] + 1][map->p_pos[1]] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[0]++;
		map->old_moves = map->moves;
		map->moves++;
	}
}

static void	move_right(t_map *map)
{
	if (map->map_array[map->p_pos[0]][map->p_pos[1] + 1] != '1')
	{
		if (map->map_array[map->p_pos[0]][map->p_pos[1] + 1] == 'C')
		{
			map->old_collect_count = map->collect_count;
			map->collect_count--;
		}
		if (map->map_array[map->p_pos[0]][map->p_pos[1] + 1] == 'E' && map->collect_count == 0)
			map->game_won = 1;
		map->map_array[map->p_pos[0]][map->p_pos[1] + 1] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[1]++;
		map->old_moves = map->moves;
		map->moves++;
	}
}

static void	move_left(t_map *map)
{
	if (map->map_array[map->p_pos[0]][map->p_pos[1] - 1] != '1')
	{
		if (map->map_array[map->p_pos[0]][map->p_pos[1] - 1] == 'C')
		{
			map->old_collect_count = map->collect_count;
			map->collect_count--;
		}
		if (map->map_array[map->p_pos[0]][map->p_pos[1] - 1] == 'E' && map->collect_count == 0)
			map->game_won = 1;
		map->map_array[map->p_pos[0]][map->p_pos[1] - 1] = 'P';
		if (map->p_pos[0] == map->e_pos[0] && map->p_pos[1] == map->e_pos[1])
			map->map_array[map->p_pos[0]][map->p_pos[1]] = 'E';
		else
			map->map_array[map->p_pos[0]][map->p_pos[1]] = '0';
		map->p_pos[1]--;
		map->old_moves = map->moves;
		map->moves++;
	}
}

void	check_move(t_map *map, int direction)
{
	if (direction == UP)
		move_up(map);
	if (direction == DOWN)
		move_down(map);
	if (direction == LEFT)
		move_left(map);
	if (direction == RIGHT)
		move_right(map);
}
