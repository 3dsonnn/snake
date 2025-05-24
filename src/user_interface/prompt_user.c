/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:32:05 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 05:18:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/snake.h"

static  void    welcome_user(void)
{
    clear_terminal();
    printf(BLUE_ANSI);
    printf("  ██████  ██▓  ▒ ██▓ ▄▄▄       ██ ▄█▀▓█████  ▓  ░\n");
    printf("▒██    ▒ ▓██▀█▄  ██▒▒████▄     ██▄█▒ ▓█   ▀▓ ▒░░\n");
    printf("░ ▓██▄   ▓██  █▄ ██░▒██  ▀█▄  ▓███▄░ ▒███   ▓   ░\n");
    printf("  ▒   ██▒▒██   █▄██ ░██▄▄▄▄██ ▓██ █▄ ▒▓█  ▄ ▒░░\n");
    printf("▒██████▒▒▒██▒   ▓██▒ ▓█   ▓██▒▒██▒ █▄░▒████▒░\n");
    printf("▒ ▒▓▒ ▒ ░░ ▒░   ░  ░ ▒▒   ▓▒█░▒ ▒▒ ▓▒░░ ▒░ ░▒░ ░\n");
    printf("░ ░▒  ░ ░░  ░      ░  ▒   ▒▒ ░░ ░▒ ▒░ ░ ░  ░░ ░\n");
    printf("░  ░  ░  ░      ░     ░   ▒   ░ ░░ ░    ░   ░ ░░\n");
    printf("      ░         ░         ░  ░░  ░      ░  ░  ░  ░\n\n");
    printf(CYAN_ANSI BOLD_ANSI "          Welcome to the Snake Game!\n\n" RESET_ANSI);
    usleep(.5 * 1000000);
    // clear_terminal();
}

static  void    prompt_available_colors(void)
{
    char    *color;

    ft_printf("The available colors in this system are:\n");
    while (-42)
    {
        color = my_mlx_get_available_color();
        if (!color)
            return ;
        ft_printf("%s\t", color);
    }
}

static  void    ft_readline(t_snake *snake, const char *prompt)
{
    snake->line = readline(prompt);
    if (!snake->line)
        destroy_snake(snake, "Ctrl-D pressed. Exiting the game...", 0);
}

void    prompt_user(t_snake *snake)
{
    welcome_user();
    ft_readline(snake, "Do you want to configure you game or leave it to default? [Y/n]: ");
    check_line(snake, &snake->line, 'D');
    if (!snake->dft)
        return ;
    ft_readline(snake, "Insert your username, please: ");
    snake->username = snake->line;
    ft_readline(snake, "Insert the width of the window you want to play on [ranging from 100 to 1920], please: ");
    check_line(snake, &snake->line, 'W');
    ft_readline(snake, "Insert the height of the window you want to play on [ranging from 100 to 1080], please: ");
    check_line(snake, &snake->line, 'H');
    ft_readline(snake, "Insert the level of difficulty you want to start playing [1 - easy | 2 - medium | 3 - hard], please: ");
    check_line(snake, &snake->line, 'L');
    prompt_available_colors();
    ft_readline(snake, "Based on the available colors, tell me what you want to see on the background, please: ");
    check_line(snake, &snake->line, 'B');
    ft_readline(snake, "Based on the available colors, choose one for me to paint the head of the snake with (make sure it's different from the previous one), please: ");
    check_line(snake, &snake->line, 'E');
    ft_readline(snake, "Based on the available colors, the color (not the same as the background nor the head colors previously chosen) you want me to paint the body of the snake is: ");
    check_line(snake, &snake->line, 'Y');
    ft_readline(snake, "Would you like to watch the game on autoplay? [Y/n]: ");
    check_line(snake, &snake->line, 'A');
    if (snake->autoplay)
        return ;
    ft_readline(snake, "Would you like to play against me? [Y/n]: ");
    check_line(snake, &snake->line, 'M');
}
