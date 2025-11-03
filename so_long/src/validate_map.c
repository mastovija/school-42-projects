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
//checks that the map is rectangular
//counts the number of tiles by counting each char
//minus the /n and then if map_area is not width * height
//means is not rectangular
void	verify_map(char *buffer, t_game *game)
{
	int	x;

	x = ft_strlen(buffer);
	if (game->invalid_character)
	{
		ft_printf("Error\nInvalid character");
		exit(1);
	}
	game->map_area = x - game->map_height;
	if (buffer[--x] != '\n')
		game->map_height++;
	if (game->map_area != game->map_width * game->map_height)
	{
		ft_printf("Error!\nThe map has to be rectangular.\n");
		exit(1);
	}
	check_limit_x(game);
	check_limit_y(game);
}
//Checks all the chars that represent a map
//Only 1 P, at least 1 C, only 1 E and only 0's and 1's

void	check_characters(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	game->invalid_character = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		else if (buffer[i] == 'C')
			game->collectibles++;
		else if (buffer[i] == 'E')
			game->exit++;
		else if (buffer[i] == '\n')
			game->map_height++;
		else if (buffer[i] != '0' && buffer[i] != '1')
			game->invalid_character++;
		i++;
	}
	if (game->player != 1 || game->collectibles < 1 || game->exit != 1)
	{
		ft_printf("Error\nThe number of Players,");
		ft_printf(" collectibles, or exits is Incorrect.\n");
		exit(1);
	}
}
// Takes a string (line) and adds a new char to it (c)
// then frees the old string (line) and returns the new one

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}
// reads a file (map) from the fd
// constructs a string byte per byte with all the characters
//(1, 0, E, C, P) that make up the map and then returns
// the string for further processing

char	*get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;
	char	*temp;

	line = malloc(1);
	line[0] = '\0';
	rd_bytes = read(fd, &buffer, 1);
	while (rd_bytes > 0)
	{
		temp = ft_join(line, buffer);
		line = temp;
		rd_bytes = read(fd, &buffer, 1);
	}
	if (rd_bytes < 0 || (rd_bytes == 0 && line[0] == '\0'))
	{
		free(line);
		ft_printf("Error\nEmpty map or read error\n");
		exit(1);
	}
	return (line);
}
