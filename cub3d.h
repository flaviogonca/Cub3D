/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:57:42 by fmalungo          #+#    #+#             */
/*   Updated: 2025/01/20 13:03:55 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEBUG 1
# define BLOCK 10

# define speed 0.01

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define WIDTH 1201
# define HEIGHT 801

# define PI 3.14159265359
# define BUFFER_SIZE 1024

typedef struct s_vars
{
	char		*str_1;
	char		*str_2;
	char		*str_3;
	char		*str_4;
	int			close;
	int			player_count;
	char		**values;
	int			y;
	int			x;
	char		ch;
	int			i;
	int			j;
	int			has_F;
	int			has_C;
}				t_vars;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;

	int			map_x;
	int			map_y;

	double		delta_dist_x;
	double		delta_dist_y;

	int			step_x;
	int			step_y;

	double		side_dist_x;
	double		side_dist_y;

	int			side;
	double		perp_wall_dist;

	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_player
{
	double		dir_x;
	double		dir_y;
	double		pos_x;
	double		pos_y;
	float		angle;
	char		dir;
	int			i;

	bool		key_u;
	bool		key_d;
	bool		key_l;
	bool		key_r;

	bool		l_rotate;
	bool		r_rotate;
}				t_player;

typedef struct s_img
{
	void		*img;
	char		*path;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_map_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	char		**map;
	char		**new_map;
	int			ceiling_color[3];
	int			floor_color[3];
	int			sizeMap;
	t_player	play;
}				t_map;

typedef struct s_dispaly
{
	void		*mlx;
	void		*mlx_win;
	double		plane_x;
	double		plane_y;
	float		angle_speed;
	float		angle_cos;
	float		angle_sin;
	t_img		img;
	t_img		texturas[4];
	t_map		*map;

}				t_display;

int				close_window(t_display *screen);
int				key_press(int key_code, t_display *screen);
int				key_release(int key_code, t_display *screen);
void			load_texturas(t_display *game);
void			params_validation(int ac, char **argv);
void			move(t_display *d);
void			floor_and_ceil(t_display *game);
void			raycasting(t_display *d);
void			free_and_exit(t_display *screen, bool status);
void			my_pixel_put(t_display *screen, int x, int y, int color);
void			draw_vertical_line(t_display *d, int x, t_ray *ray);
void			init_game_var(t_display *screen);

char			**ft_split(char const *s, char c);
int				check_extension(char *map_n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			**read_file(char *file);
char			*check_cardinal_points(t_map *mapa, char **linhas);
char			*check_colors(t_map *mapa, char **map);
char			*copy_map_from_line_6(t_map *map_data, char **map);
char			*validate_map_components(t_map *map);
int				is_map_surrounded_by_ones(t_map *map_data);
void			free_map(t_map *map_data);
void			free_matrix(char **av);
void			messages(t_vars *var, t_map *map_data);
void			minimap(t_display *screen);
void			clear_image(t_display *game);

#endif
