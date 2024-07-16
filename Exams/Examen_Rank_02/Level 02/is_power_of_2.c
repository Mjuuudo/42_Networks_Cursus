#include <stdio.h>
#include <unistd.h>

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        retunr 0;
    if (n % 2 == 0)
        return 1;
    else 
        return 0;
}