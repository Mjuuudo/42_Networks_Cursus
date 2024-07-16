#include <unistd.h>
#include <stdio.h>

void ft_snake_to_camel(char *str)
{
  int counter = 0;

  while (str[counter])
  {
      if (str[counter] == '_')
        printf("%c", str[counter++ + 1] - 32);
      else
         printf("%c", str[counter]);
    counter++;
  }
  printf("\n");
}