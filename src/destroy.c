/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:04:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 05:00:08 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

static	void	destroy_sprites(void *mlx, t_sprite *collectible, t_sprite *obstacle)
{
	my_mlx_destroy_img(mlx, &collectible->img);
	my_mlx_destroy_img(mlx, &obstacle->img);
	if (collectible->indexes)
		free(collectible->indexes);
	if (obstacle->indexes)
		free(obstacle->indexes);
}

static	void	destroy_mlx(void *mlx, void *win, t_img *img)
{
	my_mlx_destroy_img(mlx, img);
	if (mlx && win)
		mlx_destroy_window(mlx, win);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

void	destroy_snake(t_snake *snake, char *message, int status)
{
	if (status && message)
		ft_dprintf(2, "Error!\n%s\n", message);
	else if (message)
		ft_dprintf(1, "%s\n", message);
	destroy_sprites(snake->mlx, &snake->collectible, &snake->obstacle);
	free_tiles(&snake->tiles, snake->total_tiles.y);
	body_free(snake->mandatory.body);
	body_free(snake->bonus.body);
	ft_strfree(&snake->username);
	ft_strfree(&snake->line);
	destroy_mlx(snake->mlx, snake->win, &snake->img);
	exit(status);
}
