/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:14 by fmalungo          #+#    #+#             */
/*   Updated: 2025/02/12 11:11:18 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_pixel_put(t_display *screen, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = screen->img.data + (y * screen->img.line_size + x * (screen->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_display *game, int x, t_ray *ray)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		color;
	t_img	*texturas;
	double	wall_x;

	if (ray->side == 0 && ray->ray_dir_x > 0)
		texturas = &game->texturas[2];
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		texturas = &game->texturas[3];
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		texturas = &game->texturas[1];
	else
		texturas = &game->texturas[0];
	if (ray->side == 0)
		wall_x = game->map->play.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->map->play.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texturas->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = texturas->width - tex_x - 1;
	step = 1.0 * texturas->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (texturas->height - 1);
		tex_pos += step;
		color = *(int *)(texturas->data + (tex_y * texturas->line_size + tex_x
					* (texturas->bpp / 8)));
		my_pixel_put(game, x, y, color);
		y++;
	}
}

int	close_window(t_display *screen)
{
	free_and_exit(screen, true);
	return (0);
}
