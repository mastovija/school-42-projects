/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <jgarside@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:47:11 by jgarside          #+#    #+#             */
/*   Updated: 2023/09/27 20:47:12 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/**
 * 'ft_strchr': searches for the first occurrence of a character ('c') in a string ('s')
 * 'ft_strjoin': concatenates two strings ('line' and 'buff') and returns a newly allocated
 * string containing the combined content.
*/

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(line) + ft_strlen(buff)] = '\0';
	free(line);
	return (str);
}
