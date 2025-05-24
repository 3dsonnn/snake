/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:03:31 by efinda            #+#    #+#             */
/*   Updated: 2025/05/22 20:05:24 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

t_body  *body_new(t_tile *tile)
{
    t_body  *res;

    res = (t_body *)malloc(sizeof(t_body));
    if (!res)
        return (res);
    *res = (t_body){.prev = NULL, .tile = tile, .next = NULL};
    return (res);
}

void    body_add(t_body **head, t_body *new_body)
{
    t_body  *tmp;

    if (!head || !new_body)
        return ;
    if (!*head)
    {
        *head = new_body;
        return ;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_body;
    new_body->prev = tmp;
}

t_body  *body_get_last(t_body *head)
{
    while (head && head->next)
        head = head->next;
    return (head);
}

void    body_free(t_body *head)
{
    t_body  *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
