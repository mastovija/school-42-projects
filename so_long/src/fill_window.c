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

//defines several functions that renders different elements of your game world.
//Each function places a specific image (like walls,
//collectibles, player, or exit) on the game window
//based on the game's current state. 
//Let's dive into the details of each function:

void	put_walls(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_wall,
		game->tile_size * game->x, game->tile_size * game->y);
}

void	put_collectibles(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collectible,
		game->tile_size * game->x, game->tile_size * game->y);
}

void	put_player(t_game *game)
{
	game->img = game->player_sprites[game->current_frame];
	if (!game->img)
	{
		ft_printf("Error\nFailed to read the image.\n");
		exit(1);
	}
	game->p_y = game->y;
	game->p_x = game->x;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img,
		game->tile_size * game->x, game->tile_size * game->y);
}

void	put_exit(t_game *game)
{
	if (game->collectibles == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_exit_open, game->tile_size * game->x, game->tile_size
			* game->y);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_exit_closed, game->tile_size * game->x, game->tile_size
			* game->y);
}
