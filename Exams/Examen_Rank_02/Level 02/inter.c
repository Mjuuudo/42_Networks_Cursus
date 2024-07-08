#include <stdio.h>
#include <unistd.h>

void insert(char *s, int compteur, char a)
{
    s[compteur] = a;
}

void ft_inter(char *s1, char *accept, char *s)
{
    int counter = 0;
    int counter_1 = 0;
    int flag = 0;
    int compteur = 0;
    int mini_cmp = 0;

    while (s1[counter])
    {
        counter_1 = 0;
        flag = 0;
        while (accept[counter_1])
        {
            if (s1[counter] == accept[counter_1])
            {  
                flag = 1;
                insert(s, compteur, s1[counter]);
                compteur++;
            }
            while (s[mini_cmp])
            {
                    if (s1[counter] == s[mini_cmp])
                        flag = 0;
                    mini_cmp++;
            }
             counter_1++;
        }
        if (flag == 1)
            printf("%c", s1[counter]);
        counter++;
    } 
    
}

int main(int argc, char **argv)
{
    char s[1024];
    
    if (argc == 3)
    {
        ft_inter(argv[1], argv[2] , s);
    }
        printf("\n");
}