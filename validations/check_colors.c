/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:34 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/12 15:13:37 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_free(char **values)
{
	int	i;

	i = -1;
	while (values[++i])
		free(values[i]);
	free(values);
}

char	*extract_rgb(char *line, int rgb[3])
{
	char	**values;
	int		i;

	i = -1;
	values = ft_split(line, ',');
	if (!values || !values[0] || !values[1] || !values[2] || values[3])
		return ("Error\n Invalid Format to colors. Use F/C R,G,B.\n");
	while (++i < 3)
	{
		if (!is_valid_number(values[i]))
		{
			ft_free(values);
			return ("Error\nClolors values must be number.\n");
		}
		rgb[i] = atoi(values[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_free(values);
			return ("Error\nColors values must be among 0 and 255.\n");
		}
	}

	ft_free(values);
	return (NULL);
}

char	*check_colors(t_map *mapa, char **map)
{
	t_vars	v;
	char	*str;

	v.has_F = 0, v.has_C;
	v.has_F = 0, v.has_C = 0;
	v.i = -1;
	str = NULL;
	while (map[++v.i])
	{
		if (ft_strncmp(map[v.i], "F ", 2) == 0)
		{
			if (v.has_F)
				return ("Error\n Double line F.\n");
			str = extract_rgb(map[v.i] + 2, mapa->floor_color);
			v.values = ft_split(map[v.i] + 2, ',');
			v.j = -1; 
			while (++v.j < 3)
				mapa->f[v.j] = atoi(v.values[v.j]);
			if (str != NULL)
				return (str);
			v.has_F = 1;
		}
		else if (ft_strncmp(map[v.i], "C ", 2) == 0)
		{
			if (v.has_C)
				return ("Error\nDouble line C.\n");
			str = extract_rgb(map[v.i] + 2, mapa->ceiling_color);
			v.values = ft_split(map[v.i] + 2, ',');
			v.j = -1; 
			while (++v.j < 3)
				mapa->c[v.j] = atoi(v.values[v.j]);
			if (str != NULL)
				return (str);
			v.has_C = 1;
		}
	}
	if (!v.has_F || !v.has_C)
		return ("Error\nLake set colors (F e/ou C).\n");
	return (NULL);
}
