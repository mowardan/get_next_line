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
	char *str;

	i = 0;
	str = (char *)s;
	while(str[i])
	{
		if(str[i] == (const char)c)
			return (&str[i]);
		i++;
	}
	if(str[i] == (const char)c)
			return (&str[i]);
	return (NULL);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	length;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}
char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(str);
	ptr = malloc((len + 1) * (sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (ft_strdup(""));
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (0);
	j = 0;
	while (i > 0)
	{
		str[j++] = s[start++];
		i--;
	}
	str[j] = '\0';
	return (str);
}
