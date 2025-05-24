/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:33:27 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 05:22:13 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/snake.h"

static  void    check_confirmation(char *line, int *arg, int id)
{
    if (!ft_str_case_cmp(line, "y") || !ft_str_case_cmp(line, "yes"))
        *arg = 1;
    else if (!ft_str_case_cmp(line, "n") || !ft_str_case_cmp(line, "no"))
        *arg = 0;
    else
    {
        if (id == 'D')
            ft_printf("Sorry, I couldn't understand your answer, so I'm gonna set the game to default.\n");
        else if (id == 'A')
            ft_printf("Sorry, I couldn't understand your answer, so I'm not gonna set the game to autoplay.\n");
        else
            ft_printf("Sorry, I couldn't understand your answer, so I'm not gonna fight you.\n");
    }
}

static  void    check_size(char *line, int *value, const char *id, t_point limits)
{
    int tmp;

    if (!ft_strnbr(line))
    {
        ft_printf("Sorry, the %s passed is not a valid number, so I'm gonna set it to default.\n", id);
        *value = -1;
    }
    else if (!ft_strint(line))
    {
        ft_printf("Sorry, the %s passed not a valid integer, so I'm gonna set it to default.\n", id);
        *value = -1;
    }
    else
    {
        tmp = ft_atoi(line);
        if (tmp < limits.x || tmp > limits.y)
        {
            ft_printf("Sorry, the %s passed is out of the limits, so I'm gonna set it to default.\n", id);
            *value = -1;
        }
        *value = tmp;
    }
}

static  void    check_level(char *line, int *level)
{
    if (!ft_str_case_cmp(line, "1") || !ft_str_case_cmp(line, "easy"))
        *level = 200;
    else if (!ft_str_case_cmp(line, "1") || !ft_str_case_cmp(line, "medium"))
        *level = 100;
    else if (!ft_str_case_cmp(line, "1") || !ft_str_case_cmp(line, "hard"))
        *level = 50;
    else
    {
        ft_printf("Sorry, the level passed doesn't meet any available, so I'm gonna set it to medium.\n");
        *level = 100;
    }
}

static  void    check_colors(char *line, int colors[3], const char *id, int index)
{

    int color;
    
    color = my_mlx_get_color_from_name(line);
    if (color == -1)
    {
        ft_printf("Sorry, the %s color you chose doesn't name any color in the system, so a random color will be choosen instead.\n", id);
        colors[index] = my_mlx_get_rgb_color(rand() % 255, rand() % 255, rand() % 255);
    }
    else if (!index)
        colors[index] = color;
    else if (index == 1)
    {
        if (color == colors[0])
        {
            ft_printf("The color of the snake head provided is the same as the background color, that's why it will be set to a random color instead.\n");
            colors[index] = my_mlx_get_rgb_color(rand() % 255, rand() % 255, rand() % 255);
        }
        else
            colors[index] = color;
    }
    else if (index == 2)
    {
        if (color == colors[0] || color == colors[1])
        {
            if (color == colors[1])
                ft_printf("The color of the snake body provided is the same as the head color, that's why it will be set to a random color instead.\n");
            else
                ft_printf("The color of the snake body provided is the same as the background color, that's why it will be set to a random color instead.\n");
            colors[index] = my_mlx_get_rgb_color(rand() % 255, rand() % 255, rand() % 255);
        }
        else
            colors[index] = color;
    }
}

void    check_line(t_snake *snake, char **line, char id)
{
    char    *tmp;

    tmp = ft_strtrim(*line, "\a\b\t\n\v\f\r ");
    ft_swaptr((void **)line, (void **)&tmp);
    ft_strfree(&tmp);
    if (id == 'D')
        check_confirmation(*line, &snake->dft, id);
    else if (id == 'A')
        check_confirmation(*line, &snake->autoplay, id);
    else if (id == 'M')
        check_confirmation(*line, &snake->battle, id);
    else if (id == 'W')
        check_size(*line, &snake->win_size.x, "Width", (t_point){100, WIDTH});
    else if (id == 'H')
        check_size(*line, &snake->win_size.y, "Height", (t_point){100, HEIGHT});
    else if (id == 'L')
        check_level(*line, &snake->level);
    else if (id == 'B')
        check_colors(*line, snake->colors, "Background", BACK);
    else if (id == 'E')
        check_colors(*line, snake->colors, "Head", HEAD);
    else if (id == 'Y')
        check_colors(*line, snake->colors, "Body", BODY);
    ft_strfree(line);
}
