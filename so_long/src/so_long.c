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
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

// Initializes the MiniLibX library and creates a new window with dimensions
// based on the game map size and a predefined tile size.
// Calls fill_window(game) to draw the initial
// state of the game world in the window
void	create_window(t_game *game)
{
	game->tile_size = 50;
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->tile_size
			* game->map_width, game->tile_size * game->map_height, "Burp");
	load_images(game);
	fill_window(game);
}
//Main function to validate a map
//First gets the whole map into one string (buffer)
//Checks that only valid chars form that string
//then creates the 2D map splitting the string with each \n
//gets the width of the map
//checks that map is rectangular
//checks that there is a possible path to play and finish the game
//frees the memory used for buffer and the game map

void	validate_map(char **argv, t_game *game)
{
	int		fd;
	char	*buffer;
	char	**map_lines;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error!\nUnable to read the file.\n");
		exit(1);
	}
	buffer = get_map(fd);
	check_characters(buffer, game);
	game->map = ft_split(buffer, '\n');
	map_lines = game->map;
	while (game->map[0][game->map_width] != '\0')
		game->map_width++;
	verify_map(buffer, game);
	check_path(game);
	game->map = ft_split(buffer, '\n');
	count_chars_and_free(buffer, map_lines, '\n');
	close(fd);
}

void	initialization(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->tile_size = 0;
	game->player = 0;
	game->player_moves = 0;
	game->current_frame = 0;
	game->collectibles = 0;
	game->exit = 0;
}
//checks that there are only 2 arguments and
//that the last 4 chars are .ber

void	check_args(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_printf("Error\n Invalid number of arguments.\n");
		exit(0);
	}
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 4] == '.' && argv[1][len - 3] == 'b' && argv[1][len
			- 2] == 'e' && argv[1][len - 1] == 'r'))
	{
		ft_printf("Error\nInvalid file extension, please use a .ber file\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	initialization(&game);
	validate_map(argv, &game);
	create_window(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, keyboard, (void *)&game);
	mlx_hook(game.mlx_win, 17, 0, close_window, (void *)&game);
	mlx_loop_hook(game.mlx_ptr, (void *)update_player_animation, &game);
	mlx_loop(game.mlx_ptr);
	exit(0);
	return (0);
}
