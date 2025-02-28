/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:52:09 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/13 15:52:12 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_dir_and_pos(t_map *map, int x, int y, char c)
{
	map->new_map[y][x] = '0';
	if (c == 'N')
		map->play.angle = (3 * PI) / 2;
	else if (c == 'W')
		map->play.angle = PI;
	else if (c == 'E')
		map->play.angle = 0;
	else if (c == 'S')
		map->play.angle = PI / 2;
	map->play.i = 0;
}
char	*validate_map_components(t_map *map)
{
	t_vars	v;

	v.y = -1;
	v.player_count = 0;
	while (map->new_map[++v.y] != NULL)
	{
		v.x = -1;
		while (map->new_map[v.y][++v.x] != '\0')
		{
			v.ch = map->new_map[v.y][v.x];
			if (v.ch == 'N' || v.ch == 'S' || v.ch == 'E' || v.ch == 'W')
			{
				v.player_count++;
				map->play.pos_x = v.x + 0.5;
				map->play.pos_y = v.y + 0.5;
				map->play.dir = v.ch;
				set_player_dir_and_pos(map, v.x, v.y, map->play.dir);
			}
			else if (v.ch != '0' && v.ch != '1' && v.ch != ' ')
				return ("Erro:\nInvalid characther in Map.");
		}
	}
	if (v.player_count != 1)
		return ("Erro:\nMap must have only one Cardinal Point.");
	return (NULL);
}
