#include <stdio.h>
#include <unistd.h>

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


int ft_pgcd(int a, int b){


  while (a != b)
    {
      if (a > b)
        a -= b;
      else
        b -= a;
    }
  printf("%d\n", a);
  return a;
}


int main(int argc, char **argv){
  int res = ft_pgcd(ft_atoi(argv[1]), ft_atoi(argv[2]));
}