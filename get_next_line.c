#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return NULL;
	if(str == NULL)
	{
		str = malloc(1);
		if(!str)
			return (/*free(buffer),*/, NULL);
		str[0] = '\0';
	}
	read_bytes = 1;
	while(read_bytes != 0 && !ft_strchr(str , '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes == 0)
			break;
		if(read_bytes == -1)
			return(free(str), free(buffer), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return(free(buffer), str);
}
char *extract_line(char *str)
{
	char *new_line_position;
	char *valid_line;
	size_t sub_line_lenght;
	char *tmp;

	new_line_position = ft_strchr(str, '\n');
	valid_line = NULL;
	if(!str)
		return(NULL);
	if(new_line_position)
	{
		sub_line_lenght = (size_t)(new_line_position - str + 1);
		valid_line = ft_substr(str, 0, sub_line_lenght);
		tmp = ft_strdup(new_line_position + 1);
		free(str);
		str = tmp;
	}
	else
	{
			valid_line = ft_substr(str, 0, ft_strlen(str));
			free(str);
			// str = NULL;
	}
	return(valid_line);
}

char *get_next_line(int fd)
{
	static char *tr;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	tr = read_line(fd, tr);
	if(tr == NULL)
		return NULL;
	line = extract_line(tr);
	return(line);
}
// int main()
// {
// 	int fd = open("amine.txt", O_RDONLY);

// 	char *a;
// 	while((a = get_next_line(fd))!= NULL)
// 	{
// 		printf("%s", a);
// 	}
// }
