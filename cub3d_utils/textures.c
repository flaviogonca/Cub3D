/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:32:33 by fmalungo          #+#    #+#             */
/*   Updated: 2025/02/26 16:32:38 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_texturas(t_display *game)
{
	game->texturas[0].img = mlx_xpm_file_to_image(game->mlx, game->map->no,
			&game->texturas[0].width, &game->texturas[0].height);
	game->texturas[1].img = mlx_xpm_file_to_image(game->mlx, game->map->so,
			&game->texturas[1].width, &game->texturas[1].height);
	game->texturas[2].img = mlx_xpm_file_to_image(game->mlx, game->map->we,
			&game->texturas[2].width, &game->texturas[2].height);
	game->texturas[3].img = mlx_xpm_file_to_image(game->mlx, game->map->ea,
			&game->texturas[3].width, &game->texturas[3].height);
	game->texturas[0].data = mlx_get_data_addr(game->texturas[0].img,
			&game->texturas[0].bpp, &game->texturas[0].line_size,
			&game->texturas[0].endian);
	game->texturas[1].data = mlx_get_data_addr(game->texturas[1].img,
			&game->texturas[1].bpp, &game->texturas[1].line_size,
			&game->texturas[0].endian);
	game->texturas[2].data = mlx_get_data_addr(game->texturas[2].img,
			&game->texturas[2].bpp, &game->texturas[2].line_size,
			&game->texturas[0].endian);
	game->texturas[3].data = mlx_get_data_addr(game->texturas[3].img,
			&game->texturas[3].bpp, &game->texturas[3].line_size,
			&game->texturas[0].endian);
}

int rgb_to_int(int r, int g, int b)
{
    return (r<< 16 | g << 8 | b);
}

void	floor_and_ceil(t_display *game)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	color = rgb_to_int(game->map->c[0], game->map->c[1], game->map->c[2]);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y >= (HEIGHT / 2))
				color = rgb_to_int(game->map->f[0], game->map->f[1], game->map->f[2]);
			my_pixel_put(game, x, y, color);
		}
	}
}
