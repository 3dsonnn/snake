/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:11:55 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 09:23:46 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

static void	update_direction(t_player *snake)
{
    t_body	*tmp;
    char    prev;
    char    cur;

    prev = snake->body->tile->dir;
    tmp = snake->body->next;
	while (tmp)
	{
        cur = tmp->tile->dir;
        tmp->tile->dir = prev;
        prev = cur;
		tmp = tmp->next;
	}
}

void	move_snake(t_player *snake)
{
	t_body	*tmp;
	t_tile	*aux;

	tmp = snake->body;
	while (tmp)
	{
		aux = get_same_dir_tile(tmp->tile);
		swap_tile_attr(tmp->tile, aux);
		tmp->tile = aux;
		tmp = tmp->next;
	}
	update_direction(snake);
	snake->head = snake->body->tile;
	snake->tail = body_get_last(snake->body)->tile;
}
