
#include "../cub3d.h"

void	clear_image(t_display *game)
{
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			my_pixel_put(game, x, y, 0);
}

void	draw_square(t_display *d, int c, int l, int color, int size)
{
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			if (x == 0 || x == (size - 1) || y == 0 || y == size - 1)
				my_pixel_put(d, x + c, y + l, 0xFF0000);
			else
				my_pixel_put(d, x + c, y + l, color);
		}
	}
}

void	minimap(t_display *screen)
{
	char **map;

	float pos_x, pos_y;
	// floor_and_ceil(&screen);
	pos_x = screen->map->play.pos_x;
	pos_y = screen->map->play.pos_y;
	map = screen->map->new_map;
	for (int y = 0; map[y]; y++)
		for (int x = 0; map[y][x]; x++)
			if (map[y][x] == '1')
				draw_square(screen, x * BLOCK, y * BLOCK, 0x6495ED, BLOCK);
	draw_square(screen, pos_x * BLOCK, pos_y * BLOCK, 0x00FF00, 5);
}