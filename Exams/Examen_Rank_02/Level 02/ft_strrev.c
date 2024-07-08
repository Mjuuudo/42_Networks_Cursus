#include <sdtio.h>
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


char    *ft_strrev(char *str)
{
    int counter = 0;
    int length = ft_strlen(str);
    char tmp;

    while (str[counter] && counter < (length/2))
    {
        tmp = str[counter];
        str[counter] = str[length - 1];
        str[length - 1] = tmp;
        counter++;
        length--;
    }
    return (str);
}