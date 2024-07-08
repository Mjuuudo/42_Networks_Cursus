#include <stdio.h>
#include <unistd.h>

void camel_case(char *str)
{
  int compteur = 0;

  while (str[compteur])
    {
      if (str[compteur] >= 'a' && str[compteur] <= 'z')
        printf("%c", str[compteur]);
      else if (str[compteur] >= 'A' && str[compteur] <= 'Z')
      {
        printf("_");
        printf("%c", str[compteur] + 32);
      }
      else
          printf("%c", str[compteur]);
      compteur++;
    }
  printf("\n");
}

int main(int argc, char **argv)
{
  camel_case(argv[1]);
}