#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char	*buffer;
	ssize_t	read_bytes;
	char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return NULL;
	read_bytes = 1;
	while(read_bytes != 0 && !strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes <= 0)
			break;
		buffer[read_bytes] = '\0';
	}
}

char *get_next_line(int fd)
{
	static char
}
