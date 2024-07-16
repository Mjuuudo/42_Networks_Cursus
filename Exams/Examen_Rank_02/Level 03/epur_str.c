#include <stdio.h>
#include <unistd.h>

void print(char *str)
{
  int counter = 0;

  while (str[counter])
  {
    if (str[counter] == ' ')
    {
      write(1, " ", 1);
      while (str[counter] && str[counter] == ' ')
          counter++;
    }
    write(1, &str[counter], 1);
    counter++;
  }
  printf("\n");
}


int main(int argc, char **argv)
{
  print(argv[1]);
}