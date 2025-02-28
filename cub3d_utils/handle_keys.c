/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:22 by fmalungo          #+#    #+#             */
/*   Updated: 2025/02/26 16:33:24 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key_code, t_display *screen)
{
	if ((char)key_code == 27)
		free_and_exit(screen, true);
	if (key_code == RIGHT)
		screen->map->play.r_rotate = true;
	if (key_code == LEFT)
		screen->map->play.l_rotate = true;
	if (key_code == 68 || key_code == 100)
		screen->map->play.key_r = true;
	if (key_code == 65 || key_code == 97)
		screen->map->play.key_l = true;
	if (key_code == 87 || key_code == 119 || key_code == UP)
		screen->map->play.key_u = true;
	if (key_code == 83 || key_code == 115 || key_code == DOWN)
		screen->map->play.key_d = true;
	return (0);
}

int	key_release(int key_code, t_display *screen)
{
	if (key_code == RIGHT)
		screen->map->play.r_rotate = false;
	if (key_code == LEFT)
		screen->map->play.l_rotate = false;
	if (key_code == 68 || key_code == 100)
		screen->map->play.key_r = false;
	if (key_code == 65 || key_code == 97)
		screen->map->play.key_l = false;
	if (key_code == 87 || key_code == 119 || key_code == UP)
		screen->map->play.key_u = false;
	if (key_code == 83 || key_code == 115 || key_code == DOWN)
		screen->map->play.key_d = false;
	return (0);
}

void	move_left_and_right(t_display *game, int x, int y)
{
	game->angle_cos = cos(game->map->play.angle);
	game->angle_sin = sin(game->map->play.angle);
	if (game->map->play.key_l)
	{
		x = (int)(game->map->play.pos_x + game->angle_sin * speed);
		y = (int)(game->map->play.pos_y - game->angle_cos * speed);
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_x += game->angle_sin * speed;
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_y -= game->angle_cos * speed;
	}
	if (game->map->play.key_r)
	{
		x = (int)(game->map->play.pos_x - game->angle_sin * speed);
		y = (int)(game->map->play.pos_y + game->angle_cos * speed);
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_x -= game->angle_sin * speed;
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_y += game->angle_cos * speed;
	}
}

void	rotate(t_display *game)
{
	if (game->map->play.l_rotate)
		game->map->play.angle -= speed;
	if (game->map->play.r_rotate)
		game->map->play.angle += speed;
	if (game->map->play.angle > 2 * PI)
		game->map->play.angle = 0;
	if (game->map->play.angle < 0)
		game->map->play.angle = 2 * PI;
}

void	move(t_display *game)
{
	int	x;
	int	y;

	game->angle_cos = cos(game->map->play.angle);
	game->angle_sin = sin(game->map->play.angle);
	rotate(game);
	if (game->map->play.key_u)
	{
		x = (int)(game->map->play.pos_x + game->angle_cos * speed);
		y = (int)(game->map->play.pos_y + game->angle_sin * speed);
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_x += game->angle_cos * speed;
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_y += game->angle_sin * speed;
	}
	if (game->map->play.key_d)
	{
		x = (int)(game->map->play.pos_x - game->angle_cos * speed);
		y = (int)(game->map->play.pos_y - game->angle_sin * speed);
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_x -= game->angle_cos * speed;
		if (game->map->new_map[y][x] == '0')
			game->map->play.pos_y -= game->angle_sin * speed;
	}
	move_left_and_right(game, x, y);
}
