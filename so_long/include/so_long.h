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
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	char	*img;
	int		map_width;
	int		map_height;
	int		map_area;
	int		x;
	int		y;
	int		tile_size;
	int		player;
	int		p_x;
	int		p_y;
	int		player_moves;
	void	*player_sprites[4];
	int		current_frame;
	int		collectibles;
	int		exit;
	int		collectible_path;
	int		exit_path;
	int		invalid_character;
	void	*img_wall;
	void	*img_collectible;
	void	*img_player;
	void	*img_exit_open;
	void	*img_exit_closed;
	void	*img_floor;
}			t_game;

void		check_args(int argc, char **argv);
void		initialization(t_game *game);
void		validate_map(char **argv, t_game *game);
void		create_window(t_game *game);
char		*get_map(int fd);
int			verify(char *line);
char		*ft_join(char *line, char c);
void		check_characters(char *buffer, t_game *game);
void		verify_map(char *buffer, t_game *game);
void		check_limit_y(t_game *game);
void		check_limit_x(t_game *game);
void		error_in_limits(void);
void		fill_window(t_game *game);
int			max_collectibles(t_game *game);
void		fill_surface(t_game *game);
int			close_window(t_game *game);
void		put_walls(t_game *game);
void		put_surface(t_game *game);
void		put_collectibles(t_game *game);
void		put_player(t_game *game);
void		put_exit(t_game *game);
int			keyboard(int keycode, t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		validate_path(int y, int x, t_game *game);
void		check_path(t_game *game);
void		free_array(char **ptr, int i);
void		count_chars_and_free(char *str, char **ptr, char c);
void		load_image_to_game(t_game *game, void **img_ptr, char *path);
void		load_images(t_game *game);
void		update_player_animation(t_game *game);

#endif
