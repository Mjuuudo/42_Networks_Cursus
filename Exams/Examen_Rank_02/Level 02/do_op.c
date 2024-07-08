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


int main(int argc, char **argv)
{
  int first_number = ft_atoi(argv[1]);
  int seconde_number = ft_atoi(argv[3]);
  int result = 0;

  if (argc == 4)
  {
      if (argv[2][0] == '+')
          result = first_number + seconde_number;
      else if (argv[2][0] == '-')
          result = first_number - seconde_number;
      else if (argv[2][0] == '*')
          result = first_number * seconde_number;
      else if (argv[2][0] == '/')
          result = first_number / seconde_number;
    printf("%d\n", result);
  }
  else
      printf("\n");
}