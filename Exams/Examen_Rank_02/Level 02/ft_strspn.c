#include <stdio.h>
#include <unistd.h>


size_t	ft_strspn(const char *s, const char *accept)
{
    int counter = 0;
    int counter_1 = 0;
    int flag = 0;

    while (s[counter])
    {
        counter_1 = 0;
        flag = 0;
        while (accept[counter_1])
        {
            if (s[counter] == accept[counter_1])
                flag = 1;
            counter_1++;
        }
        if (flag == 0)
            return (counter);
        counter++;
    }
    return (counter);
}