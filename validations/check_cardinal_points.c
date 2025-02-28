/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cardinal_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:23 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/12 15:13:26 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot open the file %s", path);
		exit(0);
	}
}

void	search_point(t_map *mapa, char *linha)
{
	char	**matriz;

	matriz = ft_split(linha, ' ');
	if (ft_strncmp(matriz[0], "NO", 3) == 0 && !mapa->no)
	{
		mapa->no = ft_strdup(matriz[1]);
		check_file_path(mapa->no);
	}
	else if (ft_strncmp(matriz[0], "SO", 3) == 0 && !mapa->so)
	{
		mapa->so = ft_strdup(matriz[1]);
		check_file_path(mapa->so);
	}
	else if (ft_strncmp(matriz[0], "WE", 3) == 0 && !mapa->we)
	{
		mapa->we = ft_strdup(matriz[1]);
		check_file_path(mapa->we);
	}
	else if (ft_strncmp(matriz[0], "EA", 3) == 0 && !mapa->ea)
	{
		mapa->ea = ft_strdup(matriz[1]);
		check_file_path(mapa->ea);
	}
	free_matrix(matriz);
}

char	*check_cardinal_points(t_map *mapa, char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		search_point(mapa, map[i]);
	if (!mapa->no || !mapa->so || !mapa->we || !mapa->ea)
		return ("Error\nFaltam pontos cardeais no arquivo.");
	return (NULL);
}
