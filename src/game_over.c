/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:40:54 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 19:48:24 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

void	game_over(t_snake *snake, char *reason)
{
	t_point				iter;
	unsigned long long	last_time;

    iter = (t_point){.x = -1, .y = -1};
	last_time = get_current_time();
	while (iter.y < HEIGHT)
	{
		if (get_current_time() - last_time > 1000)
		{
			mlx_put_image_to_window(snake->mlx, snake->win, snake->img.img, 0, 0);
            iter.y++;
		}
        my_mlx_draw
	}
}
