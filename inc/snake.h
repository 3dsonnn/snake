/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:26:22 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 05:17:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include "../my_mlx/Super-Libft/inc/libft.h"
# include "../my_mlx/inc/my_mlx.h"
# include "snake_structs.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/time.h>
# include <time.h>

# define WIDTH 1920
# define HEIGHT 1080

# define TILE 32

# define SPACE_KEY 32
# define ALT 65513
# define CTRL_KEY 65507
# define ESC_KEY 65307
# define AKEY 97
# define DKEY 100
# define SKEY 115
# define WKEY 119
# define EKEY 101
# define RIGHT 65363
# define DOWN 65364
# define LEFT 65361
# define UP 65362

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// INIT_AND_FREE
void				init_snake(t_snake *snake);
void				destroy_snake(t_snake *snake, char *message, int status);

// USER_INTERFACE
void				prompt_user(t_snake *snake);
void				check_line(t_snake *snake, char **line, char id);

// SETUP
void				setup_game(t_snake *snake);
void				set_mlx(t_snake *snake);

// CORE
void				move_snake(t_player *snake);
void				paint_snake(t_snake *snake, t_body *body);
void				did_snake_eat(t_snake *snake, t_sprite *collectible,
						t_sprite *obstacle);

// SPRITES
t_point				*is_head_at_sprite(t_sprite *sprite, t_tile *head);
void				put_sprite(t_sprite sprite, t_img *img, int back_color);
void				update_sprite_index(t_point *index, t_tile **tiles,
						t_point total_tiles, int back_color);

// HOOKS
void				my_mlx_hooks(t_snake *snake);

// TILES
void				init_tiles(t_tile ***tiles, t_point size);
void				free_tiles(t_tile ***tiles, int rows);
void				link_tiles(t_tile **tiles, t_point size);
void				set_tiles(t_tile **tiles, t_point size, int colors[3]);
void				set_tile(t_tile *tile, int color, char dir);
extern void			swap_tile_attr(t_tile *a, t_tile *z);
extern t_tile		*get_opposite_dir_tile(t_tile *ref);
extern t_tile		*get_same_dir_tile(t_tile *ref);

// T_BODY
t_body				*body_get_last(t_body *head);
t_body				*body_new(t_tile *tile);
void				body_free(t_body *head);
void				body_add(t_body **head, t_body *new_body);

// UTILS
unsigned long long	get_current_time(void);
void				clear_terminal(void);

#endif