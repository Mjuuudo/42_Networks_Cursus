#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

void ft_putstr_fd2(char *str, char *arg)
{
    while (*str)
        write(2, str++, 1);
    if (arg)
        while(*arg)
            write(2, arg++, 1);
    write(2, "\n", 1);
}

void ft_execute(char **av, char **ev, int counter, int tmp_fd)
{
    av[counter] = 0;
    dup2(tmp_fd, STDIN_FILENO);
    close(tmp_fd);
    execve(av[0], av, ev);
    ft_putstr_fd2("error: cannot execute ", av[0]);
    exit(1);
}

int main(int ac, char **av, char **ev)
{
    int counter = 0;
    int fd[2];
    int tmp_fd;
    
    if (ac <= 1)
        return(1);
    tmp_fd = dup(STDIN_FILENO);
    while (av[counter] && av[counter + 1])
    {
        av = &av[counter + 1];
        counter = 0;
        while (av[counter] && strcmp(av[counter], ";") && strcmp(av[counter], "|"))
            counter++;
        if (!strcmp(av[0], "cd"))
        {
            if (counter != 2)
                ft_putstr_fd2("error: cd: bad arguments", NULL);
            else if (chdir(av[1]) != 0)
                ft_putstr_fd2("error: cd: cannot change directory to ", av[1]);
        }
        else if (counter != 0 && (av[counter] == NULL || strcmp(av[counter], ";") == 0))
        {
            if (fork() == 0)
                ft_execute(av, ev, counter, tmp_fd);
            else
            {
                close(tmp_fd);
                while (waitpid(-1, NULL, WUNTRACED) != -1);
                tmp_fd = dup(STDIN_FILENO);
            }
        }
        else if (counter != 0 && strcmp(av[counter], "|") == 0)
        {
            pipe(fd);
            if (fork() == 0)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
                ft_execute(av, ev, counter, tmp_fd);
            }
            else
            {
                close(fd[1]);
                close(tmp_fd);
                tmp_fd = fd[0];
            }
        }
    }
    close(tmp_fd);
    return 0;
}