/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:52:52 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/13 15:52:54 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	messages(t_vars *var, t_map *map_data)
{
	if (var->str_1 != NULL || var->str_2 != NULL || var->str_3 != NULL
		|| var->str_4 != NULL || !var->close)
	{
		if (!var->close)
			printf("Map is not closed\n");
		else if (var->str_1)
			printf("%s", var->str_1);
		else if (var->str_2)
			printf("%s", var->str_2);
		else if (var->str_3)
			printf("%s", var->str_3);
		else if (var->str_4)
			printf("%s", var->str_4);
		free_map(map_data);
	}
}
