#include <stdio.h>
#include <unistd.h>

int check(char *holder, char c)
{
  int counter = 0;

  while (holder[counter])
  {
    if (holder[counter++] == c)
      return 1;    
  }
  return 0;
}

void  ft_union(char *s1, char *s2)
{
  char holder[1024];
  int counter = 0;
  int compteur = 0;
  
  while (s1[counter])
  {
    if (check(holder, s1[counter]) == 0)
    {
      holder[compteur] = s1[counter];
      printf("%c", s1[counter]);
      counter++;
      compteur++;
    }
    else
      counter++;
  }
  counter = 0;
  while (s2[counter])
    {
      if (check(holder, s2[counter]) == 0)
      {
        holder[compteur] = s2[counter];
        printf("%c", s2[counter]);
        counter++;
        compteur++;
      }
      else
        counter++;
    }
  printf("\n");
}