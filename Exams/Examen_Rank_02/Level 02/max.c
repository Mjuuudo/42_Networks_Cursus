#include <stdio.h>
#include <unistd.h>

int		max(int* tab, unsigned int len)
{
    int counter = 0;
    int holder;

    if (len == 0)
        return 0;
    holder = tab[counter++];
    while (counter < len)
    {
        if (tab[counter] > holder)
            holder = tab[counter];
        counter++;
    }
    return (holder);
}