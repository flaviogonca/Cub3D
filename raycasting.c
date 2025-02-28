/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:07:41 by fmalungo          #+#    #+#             */
/*   Updated: 2025/02/12 11:07:45 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_display *game, t_ray *ray)
{
	ray->ray_dir_x = game->angle_cos;
	ray->ray_dir_y = game->angle_sin;
	ray->map_x = (int)game->map->play.pos_x;
	ray->map_y = (int)game->map->play.pos_y;
	ray->delta_dist_x = fabsf(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabsf(1 / ray->ray_dir_y);
}

void	calc_step(t_display *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->map->play.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->map->play.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->map->play.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->map->play.pos_y)
			* ray->delta_dist_y;
	}
}

void	dda(t_display *d, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (d->map->new_map[ray->map_y][ray->map_x] > '0')
			break ;
	}
}

void	draw_line(t_display *game, float start_x, int i)
{
	t_ray	ray;
	float	ray_angle;

	game->angle_cos = cos(start_x);
	game->angle_sin = sin(start_x);
	init_ray(game, &ray);
	calc_step(game, &ray);
	dda(game, &ray);
	if (ray.side == 0)
		ray.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x);
	else
		ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y);
	ray_angle = start_x - game->map->play.angle;
	ray.perp_wall_dist *= cos(ray_angle);
	ray.line_height = (int)(HEIGHT / ray.perp_wall_dist);
	ray.draw_start = -ray.line_height / 2 + HEIGHT / 2;
	if (ray.draw_start < 0)
		ray.draw_start = 0;
	ray.draw_end = ray.line_height / 2 + HEIGHT / 2;
	if (ray.draw_end >= HEIGHT)
		ray.draw_end = HEIGHT - 1;
	draw_vertical_line(game, i, &ray);
}

void	raycasting(t_display *game)
{
	float	fraction;
	float	start_x;
	int		i;

	clear_image(game);
	floor_and_ceil(game);
	fraction = PI / 3 / WIDTH;
	start_x = game->map->play.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
	if (DEBUG)
		minimap(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
}
