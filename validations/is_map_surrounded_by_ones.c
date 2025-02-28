/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_surrounded_by_ones.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:14:40 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/12 15:14:43 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	verify_left_and_rigth_side(int x, int i, char **map, int line_len)
{
	if ((x > 0 && map[i][x] == '0' && map[i][x - 1] == ' ') || (x < line_len - 1
			&& map[i][x] == '0' && map[i][x + 1] == ' '))
		return (0);
	return (1);
}

int	check_first_and_last_line(t_map *map)
{
	int	first_line_len;
	int	last_line_len;
	int	i;

	first_line_len = ft_strlen(map->new_map[0]);
	i = -1;
	while (++i < first_line_len)
	{
		while (map->new_map[0][i] == ' ' || map->new_map[0][i] == '\t')
			i++;
		if (map->new_map[0][i] != '1')
			return (0);
	}
	last_line_len = map->sizeMap - 1;
	i = -1;
	while (++i < last_line_len)
	{
		while (map->new_map[last_line_len][i] == ' '
			|| map->new_map[last_line_len][i] == '\t')
			i++;
		if (map->new_map[last_line_len][i] != '1')
			return (0);
	}
	return (1);
}

int	check_up_and_down(int x, int i, t_map *map)
{
	if (map->new_map[i][x] == '1')
		return (1);
	if (map->new_map[i][x] == '0' && (ft_strlen(map->new_map[i - 1]) < x
			|| ft_strlen(map->new_map[i + 1]) < x))
		return (0);
	if ((i > 0 && (map->new_map[i - 1][x] == ' ' || map->new_map[i
				- 1][x] == '\0') && map->new_map[i][x] == '0')
		|| (i < map->sizeMap - 1 && (map->new_map[i + 1][x] == '\0'
				|| map->new_map[i + 1][x] == ' ') && map->new_map[i][x] == '0'))
		return (0);
	return (1);
}

int	is_map_surrounded_by_ones(t_map *map)
{
	int	i;
	int	x;
	int	line_len;

	i = 0;
	if (!check_first_and_last_line(map))
		return (0);
	while (++i < (map->sizeMap - 1))
	{
		x = -1;
		line_len = ft_strlen(map->new_map[i]);
		while (map->new_map[i][++x] != '\0')
		{
			if (x == 0 && map->new_map[i][x] == '0' && map->new_map[i][x] != ' '
				&& map->new_map[i][x] != '\t')
				return (0);
			if (!check_up_and_down(x, i, map))
				return (0);
			if (x == line_len - 1 && map->new_map[i][x] == '0')
				return (0);
			if (!verify_left_and_rigth_side(x, i, map->new_map, line_len))
				return (0);
		}
	}
	return (1);
}
