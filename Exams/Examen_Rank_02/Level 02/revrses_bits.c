#include <stdio.h>
#include <unistd.h>


unsigned char    reverse_bits(unsigned char octet)
{
    int bits = 7;
    unsigned char a = 0;
    int counter = 0;

    while (bits >= 0 && counter <= 7)
    {
        if ((octet >> bits) & 1)
            a = ((a << 1) | 1);    
        else
            a = (a << 1);  
        counter++;
        bits--;
    }
    return (a);
}

int main(void)
{
    unsigned char octet = 65;

    printf("%d\n", reverse_bits(octet));
}