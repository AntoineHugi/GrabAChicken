/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:52 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:12:36 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

static int	has_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	unique_elements(t_map *map, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == c && flag == 0)
				flag = 1;
			else if (map->map_array[i][j] == c && flag == 1)
				return (0);
			j++;
		}
		i++;
	}
	if (flag == 1)
		return (1);
	else
		return (0);
}

static int	edge_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if ((i == 0 || i == map->height - 1) && map->map_array[i][j] != '1')
				return (0);
			if ((j == 0 || j == map->width - 1) && map->map_array[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_rectangle(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[j])
		{
			if (strlen(map->map_array[i]) != strlen(map->map_array[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_validation(t_map *map)
{
	if (!is_rectangle(map))
		error_map("The map is not rectangular.", map);
	if (!edge_walls(map))
		error_map("The map is not surrounded by walls.", map);
	if (!unique_elements(map, 'P'))
		error_map("The map has no or more than one player.", map);
	if (!unique_elements(map, 'E'))
		error_map("The map has no or more than one exit.", map);
	if (!has_collectibles(map))
		error_map("The map has no collectibles.", map);
	if (!valid_path(map))
		error_map("The map doesn't have a valid path.", map);
	return (1);
}
