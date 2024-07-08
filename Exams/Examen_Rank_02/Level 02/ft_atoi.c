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