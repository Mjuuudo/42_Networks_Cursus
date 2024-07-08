#include <stdio.h>
#include <unistd.h>

void alpha_mirror(char c)
{
  int res; 


  if ((c >= 'a' && c <= 'z'))
  {
      res = c - 97;
      printf("%c", ('z' - res));
  }
  else if (c >= 'A' && c <= 'Z')
  {
    res = c - 65;
    printf("%c", ('Z' - res));
  }
  else
    printf("%c", c);
}

int main(int argc, char **argv)
{
  int counter = 0;

  if (argc == 2)
  {
    while (argv[1][counter])
      {
        alpha_mirror(argv[1][counter++]);
      }
  }
  else
    printf("\n");
}