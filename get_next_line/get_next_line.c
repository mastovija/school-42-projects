/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <jgarside@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:45:21 by jgarside          #+#    #+#             */
/*   Updated: 2023/09/27 20:45:25 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/**
 * 'read_chunk': reads data from a file descriptor in chunks, concatenates it with the existing 'line',
 *  and continues until a newline character is encountered or the end of the file is reached.
 *  It dynamically allocates memory for the buffer and cleans up after reading.
*/

char	*read_chunk(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

/**
 * 'get_remainder': Extracts the remainder of a line after the first newline character.
 * 	Returns the remainder of the line.
*/

char	*get_remainder(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

/**
 * 'extract_line': isolates and return a complete line from the current line.
*/

char	*extract_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/**
 * A static variable in C is a variable that retains its value across function calls. 
 * This means that even if the 	function returns, the static variable will still keep its value.
 * This function uses a static variable to store the remaining data in the buffer. 
 * This is necessary because the function may need to read data from the file multiple times in order to extract a complete line.
 * If the function did not use a static variable to store the remaining data in the buffer, 
 * then the function would lose the remaining data when it returned from the first call. 
 * This would result in the function returning an incomplete line to the caller.
 * By using a static variable to store the remaining data in the buffer, the get_next_line() function is able to extract complete lines from the file,
 * even if the lines are longer than the buffer size.
*/

char	*get_next_line(int fd)
{
	static char			*line;
	char				*complete_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_chunk(fd, line);
	if (!line)
		return (NULL);
	complete_line = extract_line(line);
	line = get_remainder(line);
	return (complete_line);
}

/*
int main(void) 
{
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0) 
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
*/
