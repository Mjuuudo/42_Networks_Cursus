#include <stdio.h>
#include <unistd.h>

void print(char *str)
{
  int counter = 0;

  while (str[counter])
  {
    if ((str[counter + 1] ==  ' ' || str[counter + 1] == '\t' || str[counter + 1] == '\0')
           && (str[counter] >= 'a' && str[counter] <= 'z'))
      printf("%c", str[counter++] - 32);
    else if ((str[counter] >= 'A' && str[counter] <= 'Z') && str[counter + 1] !=  ' ')
        printf("%c", str[counter++] + 32);
    else
      printf("%c", str[counter++]);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  int counter = 1;

  while (counter < argc)
  {
    print(argv[counter]);
    printf("\n");
    counter++;
  }
}