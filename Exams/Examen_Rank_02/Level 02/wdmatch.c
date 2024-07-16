#include <stdio.h>
#include <unistd.h>

int wd_match(char *str, char *str2)
{
  int compteur = 0;
  int counter = 0;

  while (str2[compteur] != '\0')
  {
      if (str[counter] == str2[compteur])
          counter++;
      compteur++;
  }
  if (str[counter] == '\0')
      return 1;
  else 
      return 0;
}


int main(int argc, char **argv)
{
  if (wd_match(argv[1], argv[2]) == 1)
  {
    printf("%s", argv[1]);
  }
  printf("\n");
}