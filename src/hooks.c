/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:17:12 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 08:49:19 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

static int	my_mlx_close(t_snake *snake)
{
	destroy_snake(snake, "The Game Was Closed Through The Window's Close Button.", 0);
	return (0);
}

static int	my_mlx_key_press(int keycode, t_snake *snake)
{
	if (keycode == ESC)
		my_mlx_close(snake);
		// destroy_snake(snake, "The Game Was Closed Through The ESC Key Press.", 0);
	if (keycode == UP && snake->mandatory.head->dir != 'S')
		snake->mandatory.head->dir = 'N';
	if (keycode == DOWN && snake->mandatory.head->dir != 'N')
		snake->mandatory.head->dir = 'S';
	if (keycode == RIGHT && snake->mandatory.head->dir != 'W')
		snake->mandatory.head->dir = 'E';
	if (keycode == LEFT && snake->mandatory.head->dir != 'E')
		snake->mandatory.head->dir = 'W';
	return (0);
}

static int	my_mlx_loop_hook(t_snake *snake)
{
	if (get_current_time() - snake->last_time < (unsigned long long)snake->level)
		return (0);
	did_snake_eat(snake, &snake->collectible, &snake->obstacle);
	move_snake(&snake->mandatory);
	paint_snake(snake, snake->mandatory.body);
	put_sprite(snake->collectible, &snake->img, snake->colors[BACK]);
	put_sprite(snake->obstacle, &snake->img, snake->colors[BACK]);
	mlx_put_image_to_window(snake->mlx, snake->win, snake->img.img, 0, 0);
	snake->last_time = get_current_time();
	return (0);
}

void	my_mlx_hooks(t_snake *snake)
{
	mlx_hook(snake->win, 2, 1L << 0, my_mlx_key_press, snake);
	mlx_hook(snake->win, 17, 1L << 17, my_mlx_close, snake);
	mlx_loop_hook(snake->mlx, my_mlx_loop_hook, snake);
}
