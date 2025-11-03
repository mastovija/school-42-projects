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

// This file contains functions to check the integrity
// of the map's boundaries in the game
// ensuring that the map is surrounded by walls ('1')
// X: checks horizontal limits (top and bottom rows)
// Y: checks vertical limits (left and right rows)

void	error_in_limits(void)
{
	ft_printf("Error!\nThe number of barrels is insufficient.\n");
	exit(1);
}

void	check_limit_x(t_game *game)
{
	while ((game->x) < (game->map_width))
	{
		if (game->map[0][game->x] != '1')
			error_in_limits();
		game->x++;
	}
	game->y = game->map_height - 1;
	game->x = 0;
	while ((game->x) < (game->map_width))
	{
		if (game->map[game->y][game->x] != '1')
			error_in_limits();
		game->x++;
	}
}

void	check_limit_y(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while ((game->y) < (game->map_height))
	{
		if (game->map[game->y][0] != '1')
			error_in_limits();
		game->y++;
	}
	game->y = 0;
	game->x = game->map_width - 1;
	while ((game->y) < (game->map_height))
	{
		if (game->map[game->y][game->x] != '1')
			error_in_limits();
		game->y++;
	}
}
