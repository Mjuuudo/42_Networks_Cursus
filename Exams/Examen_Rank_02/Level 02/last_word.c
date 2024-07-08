#include <unistd.h>
#include <stdio.h>

void ft_lastword(char *s)
{
    int length = 0;
    int counter = 0;

    while (s[length])
        length++;
    while (1)
    {
        if (s[length - 1] == ' ')
                break ;
        length--;
    }
    while (s[length])
       printf("%c", s[length++]); 
    printf("\n");
}