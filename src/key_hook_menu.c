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

/* Checks for WASD of arrow buttons on keyboard, as well as R for reset and ESC for exit. */
int	key_hook(int keycode, t_map *map)
{
	if (keycode == 65362 || keycode == 119)
		menu_move(map, UP);
	else if (keycode == 65364 || keycode == 115)
		menu_move(map, DOWN);
	else if (keycode == 65307)
		exit_app(map);
	else
		return (0);
	render_map(map);
	return (0);
}
