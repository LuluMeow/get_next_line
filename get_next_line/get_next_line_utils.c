/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:02 by lpeng             #+#    #+#             */
/*   Updated: 2023/05/18 11:26:23 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return (&s[len]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buff)
{
	char		*new;
	size_t		i;
	size_t		j;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	new = (char *)malloc(sizeof(char)
			* (1 + ft_strlen(line) + ft_strlen(buff)));
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			new[i] = line[i];
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[ft_strlen(line) + ft_strlen(buff)] = '\0';
	free(line);
	return (new);
}

/*int main()
{
	char line[50] = "mimi";
	char buff[100] = "lala";
	char *new = ft_strjoin(line, buff);
	printf("%s\n", new);	
	return (0);
}*/
