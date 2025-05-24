/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:42:58 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 09:29:24 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

static void	paint_tile(t_tile tile, t_img *img)
{
	t_point	iter;

	iter = (t_point){-1, -1};
	while (++iter.y < TILE)
	{
		iter.x = -1;
		while (++iter.x < TILE)
			my_mlx_pixel_put(img, tile.crd.x + iter.x, tile.crd.y + iter.y,
				tile.color);
	}
}

static void	paint_edge_case(t_snake *snake, t_tile *tail)
{
	if (tail->up->color == snake->colors[BACK])
		paint_tile(*tail->up, &snake->img);
	if (tail->down->color == snake->colors[BACK])
		paint_tile(*tail->down, &snake->img);
	if (tail->right->color == snake->colors[BACK])
		paint_tile(*tail->right, &snake->img);
	if (tail->left->color == snake->colors[BACK])
		paint_tile(*tail->left, &snake->img);
}

void	paint_snake(t_snake *snake, t_body *body)
{
	paint_edge_case(snake, snake->mandatory.tail);
	while (body)
	{
		if (body->tile->color != my_mlx_get_pixel(snake->img,
			body->tile->crd.x + TILE / 2, body->tile->crd.y + TILE / 2))
			paint_tile(*body->tile, &snake->img);
		body = body->next;
	}
}
