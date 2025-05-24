/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:40:23 by efinda            #+#    #+#             */
/*   Updated: 2025/05/23 22:09:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/snake.h"

int	main(int ac, char **av)
{
	t_snake	snake;

	(void)ac;
	(void)av;
	init_snake(&snake);
	prompt_user(&snake);
	setup_game(&snake);
	my_mlx_hooks(&snake);
	mlx_loop(snake.mlx);
	return (0);
}
