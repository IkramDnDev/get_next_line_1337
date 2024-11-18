#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char    *ft_strdup(const char *src)
{
	char	*copy;
	size_t	len;
	char	*ptr;

	len = ft_strlen(src);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ptr = copy;
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	int		i;
	int		j;
	char	*total_str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	total_str = (char *)malloc(total_len + 1);
	if (!total_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		total_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		total_str[i + j] = s2[j];
	total_str[i + j] = '\0';
	return (total_str);
}

char    *extract_line(char *buff)
{
    int i;
    char *line;

	i = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    line = malloc((i + 2) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (buff[i] && buff[i] != '\n')
    {
        line[i] = buff[i];
        i++;
    }
    if (buff[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *save_remainder(char *remainder)
{
    int     i;
    int     j;
    char    *new_remainder = NULL;

    i = 0;
    j = 0;
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (!remainder)
    {
        free(remainder);
        remainder = NULL;
    }
    new_remainder = malloc(ft_strlen(remainder) - i + 1);
	if (!new_remainder)
        return (NULL);
    i++;
    while (remainder[i])
    {
        new_remainder[j++] = remainder[i++];
    }
    new_remainder[j] = '\0';
    free(remainder);
    return (new_remainder);
}