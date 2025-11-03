/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <jgarside@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:28:56 by jgarside          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:06 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../printf/ft_printf.h"

//This file primarily focuses on setting up 
//the graphical window for the game using MinilibX.
//it initializes the graphics library,
//creates a window based on the game map's size,
//and fills that window with graphical elements
//representing the game world.
//It includes functions for drawing the game's base surface
//and other components like walls,
//collectibles, the player, and exit.

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(1);
	return (0);
}
//iterates over the game map's width and height,
//filling each "tile" with an image of the floor loaded from an XPM file.
//It uses mlx_xpm_file_to_image to load the image and 
//mlx_put_image_to_window to draw it at the calculated position.

void	fill_surface(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_height))
	{
		game->x = 0;
		while ((game->x) < (game->map_width))
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_floor, game->tile_size * game->x, game->tile_size
				* game->y);
			game->x++;
		}
		game->y++;
	}
}

// Counts and returns the number of collectible 
//items ('C') present in the game map.

int	max_collectibles(t_game *game)
{
	int	i;

	i = 0;
	game->y = 0;
	while ((game->y) < (game->map_height))
	{
		game->x = 0;
		while ((game->x) < (game->map_width))
		{
			if (game->map[game->y][game->x] == 'C')
				i++;
			game->x++;
		}
		game->y++;
	}
	return (i);
}

//This function sets up the game window by first determining
//the total number of collectibles with max_collectibles(game),
//filling the surface/background,
//and then iterating over the map to place game elements based
//on their character representation ('1' for walls, 'C' for collectibles,
//'P' for the player,
//and 'E' for the exit). The final line outputs the number of player movements.

void	fill_window(t_game *game)
{
	game->collectibles = max_collectibles(game);
	fill_surface(game);
	game->y = 0;
	while ((game->y) < (game->map_height))
	{
		game->x = 0;
		while ((game->x) < (game->map_width))
		{
			if (game->map[game->y][game->x] == '1')
				put_walls(game);
			if (game->map[game->y][game->x] == 'C')
				put_collectibles(game);
			if (game->map[game->y][game->x] == 'P')
				put_player(game);
			if (game->map[game->y][game->x] == 'E')
				put_exit(game);
			game->x++;
		}
		game->y++;
	}
	ft_printf("Movement: %d\n", game->player_moves);
}
