/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:28:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 08:18:37 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/snake.h"

inline void	set_tile(t_tile *tile, int color, char dir)
{
	if (!tile)
		return ;
	tile->dir = dir;
	tile->color = color;
}

void	set_tiles(t_tile **tiles, t_point size, int colors[3])
{
	t_point	iter;

	iter = (t_point){-1, -1};
	if (!tiles || !(*tiles) || ft_origin(size))
		return ;
	while (++iter.y < size.y)
	{
		iter.x = -1;
		while (++iter.x < size.x)
		{
			tiles[iter.y][iter.x].crd = (t_point){.x = iter.x * TILE, .y = iter.y * TILE};
			set_tile(&tiles[iter.y][iter.x], colors[BACK], '\0');
		}
	}
}
