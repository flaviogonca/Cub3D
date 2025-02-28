# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:29:17 by fmalungo          #+#    #+#              #
#    Updated: 2025/01/20 13:48:17 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

CFLAGS = -g #-Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -L/mlx/lib -Imlx -lXext -lX11 -lm -lz

LIBFT = ./libft/libft.a

MLX = ./mlx

SRC = cub3d.c raycasting.c ./cub3d_utils/set_free.c ./cub3d_utils/window.c \
		cub3d_utils/ft_split.c validations/read_file.c \
		validations/check_components.c validations/check_cardinal_points.c \
		validations/check_colors.c validations/copy_map.c validations/messages.c \
		validations/is_map_surrounded_by_ones.c ./cub3d_utils/minimap.c \
		cub3d_utils/handle_keys.c cub3d_utils/textures.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/mlx -Imlx -O3 -c $< -o $@

$(NAME): minilib $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

minilib:
	make -C mlx

$(LIBFT):
	$(MAKE) -C ./libft

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./mlx
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re