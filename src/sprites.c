/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:43:11 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 08:20:20 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

void    update_sprite_index(t_point *index, t_tile **tiles, t_point total_tiles, int back_color)
{
    while (-42)
    {
        index->x = rand() % total_tiles.x;
        index->y = rand() % total_tiles.y;
        if (tiles[index->y][index->x].color == back_color)
        {
            index->x *= TILE;
            index->y *= TILE;
            return ;
        }
    }
}

void	put_sprite(t_sprite sprite, t_img *img, int back_color)
{
    int i;

    i = -1;
    while (++i < sprite.amount)
    {
        my_mlx_put_img_to_img((t_img_to_img){
            .dst = img,
            .src = sprite.img,
            .aux = NULL,
            .dst_point = sprite.indexes[i],
            .src_point = (t_point){.x = 0, .y = 0},
            .size = sprite.img.size,
            .filter = 1,
            .color_aux = back_color,
            .skip = 0
        });
    }
}

t_point *is_head_at_sprite(t_sprite *sprite, t_tile *head)
{
    int i;

    i = -1;
    while (++i < sprite->amount)
    {
        if (head->crd.x == sprite->indexes[i].x
            && head->crd.y == sprite->indexes[i].y)
            return (&sprite->indexes[i]);
    }
    return (NULL);
}
