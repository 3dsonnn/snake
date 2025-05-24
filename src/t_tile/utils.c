/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:25:49 by efinda            #+#    #+#             */
/*   Updated: 2025/05/22 17:44:03 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/snake.h"

inline void swap_tile_attr(t_tile *a, t_tile *z)
{
    t_tile tmp;

    tmp = *a;
    a->dir = z->dir;
    a->color = z->color;
    z->dir = tmp.dir;
    z->color = tmp.color;
}

inline t_tile	*get_opposite_dir_tile(t_tile *tile)
{
	if (!tile)
		return (tile);
	if (tile->dir == 'N')
		return (tile->down);
	if (tile->dir == 'S')
		return (tile->up);
	if (tile->dir == 'E')
		return (tile->left);
	if (tile->dir == 'W')
		return (tile->right);
	return (NULL);
}

inline t_tile	*get_same_dir_tile(t_tile *tile)
{
	if (!tile)
		return (tile);
	if (tile->dir == 'N')
		return (tile->up);
	if (tile->dir == 'S')
		return (tile->down);
	if (tile->dir == 'E')
		return (tile->right);
	if (tile->dir == 'W')
		return (tile->left);
	return (NULL);
}
