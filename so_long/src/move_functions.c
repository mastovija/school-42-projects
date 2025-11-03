/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <jgarside@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:28:56 by jgarside          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:06 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
#include "../printf/ft_printf.h"

// Contains the logic for handling player movements
// It defines how the player character responds to keyboard inputs
// including moving in the four cardinal directions,
// closing the game, and winning the game

void	move_up(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y - 1][game->p_x] = 'P';
	game->player_moves++;
	fill_window(game);
}

void	move_down(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y + 1][game->p_x] = 'P';
	game->player_moves++;
	fill_window(game);
}

void	move_left(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x - 1] = 'P';
	game->player_moves++;
	fill_window(game);
}

void	move_right(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x + 1] = 'P';
	game->player_moves++;
	fill_window(game);
}

int	keyboard(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (game->collectibles == 0
		&& ((keycode == 119 && game->map[game->p_y][game->p_x + 1] == 'E')
		|| (keycode == 115 && game->map[game->p_y + 1][game->p_x] == 'E')
		|| (keycode == 97 && game->map[game->p_y][game->p_x - 1] == 'E')
		|| (keycode == 100 && game->map[game->p_y - 1][game->p_x] == 'E')))
	{
		ft_printf("YOU WIN\n");
		close_window(game);
	}
	if (keycode == 119 && game->map[game->p_y - 1][game->p_x] != '1'
		&& game->map[game->p_y - 1][game->p_x] != 'E')
		move_up(game);
	if (keycode == 97 && game->map[game->p_y][game->p_x - 1] != '1'
		&& game->map[game->p_y][game->p_x - 1] != 'E')
		move_left(game);
	if (keycode == 115 && game->map[game->p_y + 1][game->p_x] != '1'
		&& game->map[game->p_y + 1][game->p_x] != 'E')
		move_down(game);
	if (keycode == 100 && game->map[game->p_y][game->p_x + 1] != '1'
		&& game->map[game->p_y][game->p_x + 1] != 'E')
		move_right(game);
	return (0);
}
