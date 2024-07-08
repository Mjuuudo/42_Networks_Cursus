#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
    int bits = 7;

    while (bits >= 0)
    {
        if ((octet >> bits) & 1)
            printf("1");
        else
            printf("0");
        bits--;
    }
    printf("\n");
}

int main()
{
    print_bits(5);
}