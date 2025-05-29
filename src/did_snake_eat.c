/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_snake_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:06:53 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 19:42:47 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

static void	snake_ate_herself_or_obstacle(t_snake *snake, char id)
{
	if (id == 'H')
		game_over(snake, "YOU ATE YOURSELF, GAY");
		// destroy_snake(snake, "YOU ATE YOURSELF, GAY\n", 0);
	else
		game_over(snake, "YOU ATE AN OBSTACLE, GAY");
		// destroy_snake(snake, "YOU ATE AN OBSTACLE, GAY\n", 0);
}

static void	snake_ate_collectible(t_snake *snake, t_point *index, t_tile *ref)
{
	t_tile	*tmp;

	snake->mandatory.points++;
	tmp = get_opposite_dir_tile(ref);
	tmp->dir = ref->dir;
	body_add(&snake->mandatory.body, body_new(tmp));
	set_tile(tmp, snake->colors[BODY], tmp->dir);
	snake->mandatory.tail = body_get_last(snake->mandatory.body)->tile;
	update_sprite_index(index, snake->tiles, snake->total_tiles, snake->colors[BACK]);
}

void	did_snake_eat(t_snake *snake, t_sprite *collectible, t_sprite *obstacle)
{
	t_point	*index;
	t_tile	*new_head;

	new_head = get_same_dir_tile(snake->mandatory.head);
	index = is_head_at_sprite(collectible, new_head);
	if (index)
	{
		if (!snake->mandatory.points)
			snake_ate_collectible(snake, index, snake->mandatory.head);
		else
			snake_ate_collectible(snake, index, snake->mandatory.tail);
	}
	else if (is_head_at_sprite(obstacle, new_head))
		snake_ate_herself_or_obstacle(snake, 'O');
	else if (new_head->color == snake->colors[BODY])
		snake_ate_herself_or_obstacle(snake, 'H');
}
