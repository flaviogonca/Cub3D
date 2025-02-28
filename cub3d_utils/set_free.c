/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:17:01 by fmalungo          #+#    #+#             */
/*   Updated: 2025/02/12 11:17:04 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (!av)
		return ;
	while (av[++i] != NULL)
		free(av[i]);
	free(av);
}

void	free_and_exit(t_display *screen, bool status)
{
	if (screen->img.img)
		mlx_destroy_image(screen->mlx, screen->img.img);
	if (screen->texturas[0].img)
		mlx_destroy_image(screen->mlx, screen->texturas[0].img);
	if (screen->texturas[1].img)
		mlx_destroy_image(screen->mlx, screen->texturas[1].img);
	if (screen->texturas[2].img)
		mlx_destroy_image(screen->mlx, screen->texturas[2].img);
	if (screen->texturas[3].img)
		mlx_destroy_image(screen->mlx, screen->texturas[3].img);
	if (screen->mlx_win)
		mlx_destroy_window(screen->mlx, screen->mlx_win);
	if (screen->mlx)
		mlx_destroy_display(screen->mlx);
	if (screen->mlx)
		free(screen->mlx);
	if (NULL != screen->map->new_map)
		free_matrix(screen->map->new_map);
	if (NULL != screen->map->map)
		free_matrix(screen->map->map);
	if (status == true)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map_data)
{
	int i;

	i = -1;
	while (map_data->map[++i])
		free(map_data->map[i]);
	i = -1;
	while (map_data->new_map[++i] != NULL)
		free(map_data->new_map[i]);
	free(map_data->map);
	free(map_data->no);
	free(map_data->so);
	free(map_data->we);
	free(map_data->ea);
	free(map_data->new_map);
	exit(0);
}