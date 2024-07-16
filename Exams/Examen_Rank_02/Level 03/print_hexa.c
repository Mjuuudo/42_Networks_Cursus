#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
  int res = 0;
  int signe = 1;
  int compteur = 0;

  if (str[compteur] == '-')
  {   signe *= -1;
      compteur++;
  }
   while (str[compteur] >= '0' && str[compteur] <= '9')
  {
      res *= 10;
      res += str[compteur++] - '0';
  }
  return (res * signe);
}

void print_hexa(int n)
{
  char a[16] = {"0123456789abcdef"};
  int counter = 0;

  if (n >= 16)
    print_hexa(n / 16);
  printf("%c",a[n%16]);
}



int main(int argc, char **argv)
{
  print_hexa(ft_atoi(argv[1]));
}