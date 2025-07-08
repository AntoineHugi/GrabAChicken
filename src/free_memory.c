/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:45:27 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:21:26 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

void	free_array(char **array)
{
	int	i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_img(t_map *map)
{
	mlx_destroy_image(map->mlx, map->chicken.xpm_ptr);
	mlx_destroy_image(map->mlx, map->player.xpm_ptr);
	mlx_destroy_image(map->mlx, map->exit.xpm_ptr);
	mlx_destroy_image(map->mlx, map->wall.xpm_ptr);
	mlx_destroy_image(map->mlx, map->floor.xpm_ptr);
	mlx_destroy_image(map->mlx, map->won.xpm_ptr);
}

void	free_map(t_map *map)
{
	free_array(map->map_array);
	free_array(map->map_path_check);
	free_array(map->map_reset);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free(map);
}
