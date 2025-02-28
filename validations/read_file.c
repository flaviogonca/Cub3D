/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:14:48 by gbravo-f          #+#    #+#             */
/*   Updated: 2025/02/12 15:14:51 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	params_validation(int ac, char **argv)
{
	int	fd;

	if (ac < 2)
		exit(0);
	if (check_extension(argv[1]) == 0)
	{
		ft_putendl_fd("Error\nMap extension must be 'example.cub'", 2);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Open");
		exit(0);
	}
	close(fd);
}

void	valid_file(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (str[len - 2] != '1')
	{
		ft_putendl_fd("Error\nLast line must contain only 1", 2);
		exit(1);
	}
}

int	check_extension(char *map_n)
{
	int	i;

	i = ft_strlen(map_n);
	if (map_n[i - 4] == '.' && map_n[i - 3] == 'c' && map_n[i - 2] == 'u'
		&& map_n[i - 1] == 'b')
		return (1);
	ft_putendl_fd("Error\nWrong extension", 2);
	exit(1);
}

char	**read_file(char *file)
{
	int		fd;
	int		size;
	char	**map;
	char	buffer[BUFFER_SIZE];

	check_extension(file);
	fd = open(file, O_RDONLY);
	size = 0;
	if (fd < 0)
		printf("Nao consegui abrir o arquivo");
	else
	{
		size = read(fd, buffer, sizeof(buffer));
		buffer[size] = '\0';
		if (ft_strlen(buffer) == 0)
		{
			ft_putendl_fd("Error\nEmpty map", 2);
			exit(1);
		}
		valid_file(buffer);
		map = ft_split(buffer, '\n');
	}
	close(fd);
	return (map);
}
