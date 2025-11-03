/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <jgarside@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:28:56 by jgarside          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:06 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../printf/ft_printf.h"

// Loads an image from an XPM file specified by 'path' using MiniLibX
// and associates it with a game element by storing the image pointer 
//in 'img_ptr'

void	load_image_to_game(t_game *game, void **img_ptr, char *path)
{
	*img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &game->tile_size,
			&game->tile_size);
	if (!(*img_ptr))
	{
		ft_printf("Error\nFailed to read image from %s.\n", path);
		exit(1);
	}
}
// loads all the XPM's of the game inside the corresponding game variables
// that then are converted to images

void	load_images(t_game *game)
{
	char	*player_sprites_paths[4];
	int		i;

	player_sprites_paths[0] = "./images/alkie2.xpm";
	player_sprites_paths[1] = "./images/alkie3.xpm";
	player_sprites_paths[2] = "./images/alkie4.xpm";
	player_sprites_paths[3] = "./images/alkie5.xpm";
	i = 0;
	load_image_to_game(game, &game->img_wall, "./images/barrel.xpm");
	load_image_to_game(game, &game->img_collectible, "./images/beer.xpm");
	load_image_to_game(game, &game->img_exit_open, "./images/door_open.xpm");
	load_image_to_game(game, &game->img_exit_closed,
		"./images/door_closed.xpm");
	load_image_to_game(game, &game->img_floor, "./images/brick.xpm");
	while (i < 4)
	{
		load_image_to_game(game, &game->player_sprites[i],
			player_sprites_paths[i]);
		i++;
	}
}
// Updates the player's animation frame based on elapsed time
// cycling through frames every 1/100th of a second

void	update_player_animation(t_game *game)
{
	static clock_t	last_time = 0;
	clock_t			current_time;

	current_time = clock();
	if ((current_time - last_time) / (CLOCKS_PER_SEC / 100) >= 1)
	{
		game->current_frame = (game->current_frame + 1) % 4;
		last_time = current_time;
	}
}
