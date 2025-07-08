/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:34 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:19:56 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

void	error_input(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

void	error_map(char *str, t_map *map)
{
	printf("Error\n%s\n", str);
	free_array(map->map_array);
	free_array(map->map_path_check);
	free_array(map->map_reset);
	free(map);
	exit(1);
}
