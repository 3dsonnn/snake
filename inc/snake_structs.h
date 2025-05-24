/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:48:37 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 04:59:11 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_STRUCTS_H
# define SNAKE_STRUCTS_H

# define COLLECTIBLE_PATH "assets/collectible.xpm"
# define OBSTACLE_PATH "assets/obstacle.xpm"

# define BACK 0
# define HEAD 1
# define BODY 2

# define RED_ANSI "\x1b[31m"
# define GREEN_ANSI "\x1b[32m"
# define YELLOW_ANSI "\x1b[33m"
# define BLUE_ANSI "\x1b[34m"
# define MAGENTA_ANSI "\x1b[35m"
# define CYAN_ANSI "\x1b[36m"
# define BOLD_ANSI "\x1b[1m"
# define RESET_ANSI "\x1b[0m"

typedef struct s_tile
{
	char				dir;
	int					color;
	t_point				crd;
	struct s_tile		*up;
	struct s_tile		*down;
	struct s_tile		*left;
	struct s_tile		*right;
}						t_tile;

typedef struct s_body
{
	t_tile				*tile;
	struct s_body		*prev;
	struct s_body		*next;
}						t_body;

typedef struct s_sprite
{
	int					amount;
	t_point				*indexes;
	t_img				img;
}						t_sprite;

typedef struct s_player
{
	t_body				*body;
	t_tile				*head;
	t_tile				*tail;
	int					points;
}						t_player;

typedef struct s_snake
{
	void				*mlx;
	void				*win;
	t_point				win_size;
	t_img				img;
	t_sprite			obstacle;
	t_sprite			collectible;
	t_tile				**tiles;
	t_point				total_tiles;
	t_player			mandatory;
	t_player			bonus;
	int					level;
	int					colors[3];
	int					autoplay;
	int					battle;
	int					dft;
	char				*line;
	char				*username;
	unsigned long long	last_time;
}						t_snake;

#endif