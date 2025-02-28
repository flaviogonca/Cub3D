/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:52 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/12 15:13:54 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_lines(char **lines)
{
	int	count;

	count = 0;
	while (lines[count] != NULL)
		count++;
	return (count);
}

char	*copy_map_from_line_6(t_map *map_data, char **map)
{
	int	start_line;
	int	num_lines;
	int	map_lines_count;
	int	i;

	i = -1;
	start_line = 6;
	num_lines = count_lines(map);
	if (num_lines <= start_line)
		return ("Error: Map have not enougth lines.\n");
	map_lines_count = num_lines - start_line;
	map_data->new_map = (char **)malloc((map_lines_count + 1) * sizeof(char *));
	while (++i < map_lines_count)
		map_data->new_map[i] = ft_strdup(map[start_line + i]);
	map_data->new_map[map_lines_count] = NULL;
	map_data->sizeMap = map_lines_count;
	return (NULL);
}
