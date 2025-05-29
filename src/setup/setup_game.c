/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:13:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 19:43:34 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/snake.h"

static inline char	get_initial_direction(int x)
{
	if (x == 1)
		return ('S');
	if (x == 2)
		return ('E');
	if (x == 3)
		return ('W');
	return ('N');
}

static	void	set_dft(t_snake *snake)
{
	snake->level = 100;
	snake->colors[0] = my_mlx_get_rgb_color(rand() % 255, rand() % 255, rand() % 255);
	snake->colors[1] = my_mlx_get_rgb_color(rand() % 255, rand() % 255, rand() % 255);
	snake->colors[2] = my_mlx_get_rgb_color(rand() % 255, rand() % 255, rand() % 255);
}

static	void	set_sprites(t_snake *snake, t_sprite *collectible, t_sprite *obstacle)
{
	t_point	iter;

	iter = (t_point){-1, -1};
	if (snake->battle)
		collectible->amount = 3;
	else
		collectible->amount = 1;
	collectible->indexes = (t_point *)malloc(sizeof(t_point) * collectible->amount);
	if (!collectible->indexes)
		destroy_snake(snake, "Malloc failed to allocate memory for the indexes of the collectible", 1);
	obstacle->amount = (int)((snake->total_tiles.x * snake->total_tiles.y) * .5) / 100;
	// if (snake->battle)
	// 	obstacle->amount /= 2;
	obstacle->indexes = (t_point *)malloc(sizeof(t_point) * obstacle->amount);
	if (!obstacle->indexes)
		destroy_snake(snake, "Malloc failed to allocate memory for the indexes of the obstacles", 1);
	while (++iter.x < collectible->amount)
		update_sprite_index(&collectible->indexes[iter.x], snake->tiles, snake->total_tiles, snake->colors[BACK]);
	while (++iter.y < obstacle->amount)
	{
		update_sprite_index(&obstacle->indexes[iter.y], snake->tiles, snake->total_tiles, snake->colors[BACK]);
		ft_printf("%d-%d\n", obstacle->indexes[iter.y].x, obstacle->indexes[iter.y].y);
	}
}

static	void	setup_tiles(t_snake *snake)
{
	t_point	aux;

	init_tiles(&snake->tiles, snake->total_tiles);
    link_tiles(snake->tiles, snake->total_tiles);
	set_tiles(snake->tiles, snake->total_tiles, snake->colors);
	aux = (t_point){.x = (rand() % snake->total_tiles.x), .y = (rand() % snake->total_tiles.y)};
	if (!(aux.x > 0 && aux.x < snake->total_tiles.x && aux.y > 0 && aux.y < snake->total_tiles.y))
		aux = (t_point){.x = (int)(snake->total_tiles.x / 2), .y = (int)(snake->total_tiles.y / 2)};
	snake->mandatory.head = &snake->tiles[aux.y][aux.x];
	set_tile(snake->mandatory.head, snake->colors[HEAD], get_initial_direction(rand() % 4));
	snake->mandatory.body = body_new(snake->mandatory.head);
}

void	setup_game(t_snake *snake)
{
	if (!snake->dft)
		set_dft(snake);
	set_mlx(snake);
	snake->total_tiles = (t_point){snake->win_size.x / TILE, snake->win_size.y / TILE};
    setup_tiles(snake);
	set_sprites(snake, &snake->collectible, &snake->obstacle);
}
