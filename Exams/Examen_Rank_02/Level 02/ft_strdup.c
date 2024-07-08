#include <stdio.h>
#include <unistd.h>

size_t ft_strlen(char *s)
{
    int length = 0;

    while (s[length])
    {
        length++;
    }
    return (length);
}

char    *ft_strdup(char *src)
{
    char *new_str;
    int counter;

    new_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (!new_str)
        return (src);
    while (src[counter])
    {
        new_str[counter] = src[counter];
        counter++;
    }
    return (new_str);
}
