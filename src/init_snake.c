/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_snake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:52:13 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 01:59:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

void	init_snake(t_snake *snake)
{
	srand(time(NULL));
	snake->mlx = NULL;
	snake->win = NULL;
	snake->win_size = (t_point){0, 0};
	my_mlx_init_img(&snake->img);
	snake->obstacle.amount = 0;
	snake->obstacle.indexes = NULL;
	my_mlx_init_img(&snake->obstacle.img);
	snake->collectible.amount = 0;
	snake->collectible.indexes = NULL;
	my_mlx_init_img(&snake->collectible.img);
	snake->tiles = NULL;
	snake->total_tiles = (t_point){0, 0};
	snake->mandatory = (t_player){.body = NULL, .head = NULL, .tail = NULL, 0};
	snake->bonus = (t_player){.body = NULL, .head = NULL, .tail = NULL, 0};
	snake->level = 0;
	snake->colors[0] = 0;
	snake->colors[1] = 0;
	snake->colors[2] = 0;
	snake->autoplay = 0;
	snake->battle = 0;
	snake->dft = 0;
	snake->line = NULL;
	snake->username = NULL;
	snake->last_time = 0;
}
