/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:57:07 by lpeng             #+#    #+#             */
/*   Updated: 2023/06/04 14:43:33 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_first(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read > 0)
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			free (line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	return (line);
}

char	*first_content(char *line)
{
	char	*first_line;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	first_line = (char *)malloc(i + 2);
	if (!first_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		first_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		first_line[i] = line[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}

char	*next_line(char *line)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		next[j++] = line[i++];
	next[j] = '\0';
	free (line);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*line[4096];
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = get_first(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	next = first_content(line[fd]);
	line[fd] = next_line(line[fd]);
	return (next);
}

/* TEST MULTIPLE FILES
int main()
{
	 int fd = open("text.txt", O_RDONLY);
	 int fd2 = open("text2.txt", O_RDONLY);
     char    *line;
	 char	*line2;
	
	 line = get_next_line(fd);
	 line2 = get_next_line(fd2);
	 while (line || line2)
	 {
		printf("1:%s", line2);
	 	printf("2:%s", line);
		if (line2 != NULL)
			line2 = get_next_line(fd2);
		if (line != NULL)
			line = get_next_line(fd);
	 }
     close(fd2);
     close(fd);
     return (0);
}
*/
