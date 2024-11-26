#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while(s[i])
	{
		i++;
	}
	return(i);
}
char *ft_strchr(const char *s, int c)
{
	size_t i;
	unsigned const char *str;

	i = 0;
	str = (unsigned const char *)s;
	while(str[i])
	{
		if(s[i] == (const char)c)
			return (&s[i]);
		i++;
	}
	if(s[i] == (const char)c)
			return (&s[i]);
	return (NULL);
}
