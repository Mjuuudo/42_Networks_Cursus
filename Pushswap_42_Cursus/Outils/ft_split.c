#include "../Push_swap.h"

static int  count_word(const char* string, char sep)
{
  int words = 0;
  int compteur = 0;

  if (!string || string[0] == '\0')
      return (words);
  while (string[compteur])
  {
    if (string[compteur] == sep)
    {
      compteur++;
      words++;
      while (string[compteur] == sep)
          compteur++;
    }
    else
      compteur++;
  }
  if (string[compteur] == '\0')
      words++;
  return (words);
}

static int check_spaces(const char *s, char c, int index)
{
  int compteur;

  compteur = index;
  while (s[compteur] == c)
  {
    compteur++;
  }
  return (compteur);
}

static char    *ft_substr(char const *s, unsigned int start, int len)
{
    unsigned int    index;
    char            *res;

    res = malloc(sizeof(char) * (len + 1));
    if (!res || !s)
        return (NULL);
    index = 0;
    while (start < strlen((char *)s) && s[start + index] && index < len)
    {
        res[index] = s[start + index];
        index++;
    }
    res[index] = '\0';
    return (res);
}

static char *get_next_word(const char *s, char c)
{
  static int index_start = 0;
  static int index_end = 0;
  char*      sub_string;

  index_end = check_spaces(s, c, index_end);
  index_start = check_spaces(s, c, index_end);
  while (s[index_end] != c && s[index_end])
          index_end++;
  sub_string = (char *)malloc(sizeof(char) * (index_end - index_start) + 1);
  if (!sub_string)
      return (free(sub_string), NULL);
  sub_string = ft_substr(s, index_start, (index_end - index_start));
  index_end = check_spaces(s, c, index_end);
  index_start = index_end;
  return (sub_string);
}

char	**ft_split(char const *s, char c)
{
  char **new_array;
  int     compteur;
  int      rows;

  compteur = 0;
  if (!s && !c)
    return (NULL); 
  rows = count_word(s, c);
  new_array = (char **)malloc((rows + 1)  * sizeof(char *));
  if (!new_array)
      return (free(new_array), NULL);
  while (compteur < rows)
  {
    new_array[compteur++] = get_next_word(s, c);
    if (!new_array[compteur - 1]) 
    {// Free previously allocated memory if get_next_word fails
            while (--compteur >= 0)
                free(new_array[compteur]);
            free(new_array);
            return (NULL);
    }
  }
  new_array[compteur] = NULL;
  return (new_array);
}

// int main(int argc, char **argv) {

//   char **str1;
//   int i = 0;
  
//   str1 = ft_split(argv[1], ' ');

//   while (str1[i])
//   {
//     printf("%s  ", str1[i]);
//     free(str1[i]);
//     i++;
//   }
//   printf ("\n");
  
//   return 0;
// }


