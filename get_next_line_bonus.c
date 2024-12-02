/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowardan <mowardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:49:32 by mowardan          #+#    #+#             */
/*   Updated: 2024/11/30 14:53:24 by mowardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (str == NULL)
	{
		str = malloc(1);
		if (!str)
			return (free(buffer), NULL);
		str[0] = '\0';
	}
	while (!ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
}

char	*extract_line(char **str)
{
	char	*new_line_position;
	char	*valid_line;
	size_t	sub_line_lenght;
	char	*tmp;

	new_line_position = ft_strchr(*str, '\n');
	valid_line = NULL;
	if (!*str[0])
		return (NULL);
	if (new_line_position)
	{
		sub_line_lenght = (size_t)(new_line_position - *str + 1);
		valid_line = ft_substr(*str, 0, sub_line_lenght);
		tmp = ft_strdup(new_line_position + 1);
		free(*str);
		*str = tmp;
	}
	else
	{
		valid_line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (valid_line);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_line(fd, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	line = extract_line(&str[fd]);
	if (line == NULL)
	{
		free(str[fd]);
		str[fd] = 0;
	}
	return (line);
}
// int	main(void)
// {
// 	int		fd;
// 	int		fd1;
// 	char	*a;
// 	char	*b;

// 	fd = open("ami.txt", O_RDONLY);
// 	fd1 = open("a.txt", O_RDONLY);
// 	while ((a = get_next_line(fd)) != NULL && (b = get_next_line(fd1)) != NULL)
// 	{
// 		printf("%s", a);
// 		printf("%s", b);
// 		free(b);
// 		free(a);
// 	}
// }
