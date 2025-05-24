/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:08:45 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 09:38:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/snake.h"

static  void    set_window_and_main_img(t_snake *snake, t_img *img)
{
    t_point tmp;

    mlx_get_screen_size(snake->mlx, &tmp.x, &tmp.y);
    if (!snake->dft)
        snake->win_size = tmp;
    else
    {
        if (snake->win_size.x == -1)
            snake->win_size.x = tmp.x;
        if (snake->win_size.y == -1)
            snake->win_size.y = tmp.y;
    }
    snake->win_size.x -= (snake->win_size.x % TILE);
    snake->win_size.y -= (snake->win_size.y % TILE);
	snake->win = mlx_new_window(snake->mlx, snake->win_size.x, snake->win_size.y, "5N4K3");
	if (!snake->win)
		destroy_snake(snake, "Failed to open the window.", 1);
    my_mlx_new_img(snake->mlx, img, snake->win_size);
    if (!img)
        destroy_snake(snake, "Failed to create the background image.", 1);
    my_mlx_get_data_addr(img);
    if (!img->addr)
        destroy_snake(snake, "Failed to get the address of the background image.", 1);
    my_mlx_color_img(img, snake->colors[BACK]);
}

static  void    set_sprites(t_snake *snake, t_sprite *collectible, t_sprite *obstacle)
{
    collectible->img.img = mlx_xpm_file_to_image(snake->mlx, COLLECTIBLE_PATH, &collectible->img.size.x, &collectible->img.size.y);
	if (!collectible->img.img)
		destroy_snake(snake, "Failed to convert the collectible.xpm file into an image. Make sure the assets files weren't modified!", 1);
	my_mlx_get_data_addr(&collectible->img);
	if (!collectible->img.addr)
		destroy_snake(snake, "Failed to get the address of the collectible image. Make sure the assets files weren't modified!", 1);
    obstacle->img.img = mlx_xpm_file_to_image(snake->mlx, OBSTACLE_PATH, &obstacle->img.size.x, &obstacle->img.size.y);
    if (!obstacle->img.img)
        destroy_snake(snake, "Failed to convert the obstacle.xpm file into an image. Make sure the assets files weren't modified!", 1);
    my_mlx_get_data_addr(&obstacle->img);
    if (!obstacle->img.addr)
        destroy_snake(snake, "Failed to get the address of the obstacle image. Make sure the assets files weren't modified!", 1);
}

void    set_mlx(t_snake *snake)
{
	snake->mlx = mlx_init();
	if (!snake->mlx)
		destroy_snake(snake, "Failed to initialize minilibx.", 1);
    set_window_and_main_img(snake, &snake->img);
    set_sprites(snake, &snake->collectible, &snake->obstacle);
	my_mlx_resize_img(snake->mlx, &snake->collectible.img, (t_point){TILE, TILE});
	my_mlx_resize_img(snake->mlx, &snake->obstacle.img, (t_point){TILE, TILE});
}
