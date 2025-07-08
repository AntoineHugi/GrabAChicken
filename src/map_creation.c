/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:17 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:07:29 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

void	init_map(t_map *map)
{
	int	i;

	map->width = (int)strlen(map->map_array[0]);
	i = 0;
	while (map->map_array[i])
		i++;
	map->height = i;
	map->win_x = PIX * map->width + 150;
	map->win_y = PIX * map->height;
	init_game(map);
}
/* Reads the .ber map file and generates the array to be used in the rendering of the map. */
t_map	*map_creation(char *map_file)
{
	t_map	*map;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (t_map *)malloc(sizeof(t_map));
	map->map_raw = NULL;
	map->line = get_next_line(fd);
	while (map->line)
	{
		map->map_raw = ft_gnl_strjoin(map->map_raw, map->line);
		free(map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
	map->map_array = ft_split(map->map_raw, '\n');
	map->map_path_check = ft_split(map->map_raw, '\n');
	map->map_reset = ft_split(map->map_raw, '\n');
	free(map->map_raw);
	init_map(map);
	return (map);
}
