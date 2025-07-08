/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:03 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/19 12:29:52 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grabachicken.h"

int	correct_file(char *filename)
{
	size_t	len;

	len = strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 1] != 'r')
		return (0);
	if (filename[len - 2] != 'e')
		return (0);
	if (filename[len - 3] != 'b')
		return (0);
	if (filename[len - 4] != '.')
		return (0);
	return (1);
}

int	input_validation(int argc, char **argv)
{
	if (argc == 1)
		error_input("Please provide a .ber map to start playing.");
	if (argc > 2)
		error_input("Please provide only one .ber map to start playing.");
	if (argc == 2)
	{
		if (!correct_file(argv[1]))
			error_input("Please provide a valid file in '.ber' format.");
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_map	*map;

	if (input_validation(argc, argv))
	{
		map = map_creation(argv[1]);
		if (!map)
			error_input("failed to open file");
		if (map_validation(map))
		{
			map->mlx = mlx_init();
			map->win = mlx_new_window(map->mlx, map->win_x, map->win_y, "./so_long");
			init_sprites(map);
			render_map(map);
			mlx_key_hook(map->win, key_hook, map);
			mlx_hook(map->win, 17, 0L, exit_app, map);
			mlx_loop(map->mlx);
		}
	}
	return (0);
}*/

int	main()
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_X, WIN_Y, "Grab a Chicken");
	//render_menu();
	//mlx_key_hook(map->win, key_hook_menu, map);
	mlx_hook(game.win, 17, 0L, exit_app, &game);
	mlx_loop(game.mlx);
	/*
	if (input_validation(argc, argv))
	{
		map = map_creation(argv[1]);
		if (!map)
			error_input("failed to open file");
		if (map_validation(map))
		{
			map->mlx = mlx_init();
			map->win = mlx_new_window(map->mlx, map->win_x, map->win_y, "./so_long");
			init_sprites(map);
			render_map(map);
			mlx_key_hook(map->win, key_hook, map);
			mlx_hook(map->win, 17, 0L, exit_app, map);
			mlx_loop(map->mlx);
		}
	}
	return (0);*/
}
