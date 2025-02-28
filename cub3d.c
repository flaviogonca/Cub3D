/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:04:18 by fmalungo          #+#    #+#             */
/*   Updated: 2025/01/20 13:05:24 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_var(t_display *screen)
{
	screen->mlx = mlx_init();
	if (!screen->mlx)
		exit(1);
	screen->mlx_win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "cub3D");
	screen->img.img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->img.data = mlx_get_data_addr(screen->img.img, &screen->img.bpp,
			&screen->img.line_size, &screen->img.endian);
	screen->map->play.key_l = false;
	screen->map->play.key_r = false;
	screen->map->play.key_d = false;
	screen->map->play.key_u = false;
	screen->map->play.l_rotate = false;
	screen->map->play.r_rotate = false;
	screen->plane_x = 0;
	screen->plane_y = 0.66;
	load_texturas(screen);
}

int	game_loop(t_display *screen)
{
	move(screen);
	raycasting(screen);
	return (0);
}

int	main(int ac, char *map[])
{
	t_display	screen;
	t_map		map_data;
	t_vars		var;

	if (ac != 2)
		exit(1);
	ft_memset(&var, 0, sizeof(t_vars));
	ft_memset(&screen, 0, sizeof(t_display));
	ft_memset(&map_data, 0, sizeof(t_map));
	screen.map = &map_data;
	map_data.map = read_file(map[1]);
	var.str_1 = check_cardinal_points(&map_data, map_data.map);
	var.str_2 = check_colors(&map_data, map_data.map);
	var.str_3 = copy_map_from_line_6(&map_data, map_data.map);
	var.str_4 = validate_map_components(&map_data);
	var.close = is_map_surrounded_by_ones(&map_data);
	messages(&var, &map_data);
	init_game_var(&screen);
	mlx_hook(screen.mlx_win, 2, 1L << 0, key_press, &screen);
	mlx_hook(screen.mlx_win, 3, 1L << 1, key_release, &screen);
	mlx_hook(screen.mlx_win, 17, 0, close_window, &screen);
	mlx_loop_hook(screen.mlx, game_loop, &screen);
	mlx_loop(screen.mlx);
	return (0);
}
