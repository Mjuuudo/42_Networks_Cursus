#include <stdio.h>
#include <unistd.h>


char	*ft_strpbrk(const char *s1, const char *s2)
{
    int counter = 0;
    int counter_1 = 0;

    while (s1[counter])
    {
        counter_1 = 0;
        while (s2[counter_1])
        {
            if (s1[counter] == s2[counter_1])
                return (s1 + counter);
            counter_1++;
        }
        counter++
    }
    return (NULL);
}