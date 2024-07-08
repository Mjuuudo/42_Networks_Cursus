#include <unistd.h>


size_t	ft_strcspn(const char *s, const char *reject)
{
    int counter = 0;
    int counter_2 = 0;

    while (s[counter])
    {
        counter_2 = 0;
        while (reject[counter_2])
        {
            if (s[counter] == reject[counter_2])
                return (counter);
            counter_2++;
        }
        counter++;
    }
    return (counter);
}