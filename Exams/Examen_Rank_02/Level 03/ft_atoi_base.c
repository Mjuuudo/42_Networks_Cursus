#include <stdio.h>
#include <unistd.h>


int ft_atoi_base(char *nb, int base)
{
    int signe = 1;
    int result = 0;
    int compteur = 0;
    
    if (nb[compteur] == '-')
        signe *= -1;
    if (nb[compteur] == '-' || nb[compteur] == '+')
        compteur++;
    while (nb[compteur])
    {
        result *= base;
        if (nb[compteur] >= '0' && nb[compteur] <= '9')
            result += nb[compteur] - '0';
        else if (nb[compteur] >= 'a' && nb[compteur] <= 'f')
            result += nb[compteur] - 87;
        else if (nb[compteur] >= 'A' && nb[compteur] <= 'F')
            result += nb[compteur] - 55 ;
            
        compteur++;
    }
    return (result * signe);
}


int main(int argc, char **argv)
{
    printf("%d", ft_atoi_base("2a", 16));
}