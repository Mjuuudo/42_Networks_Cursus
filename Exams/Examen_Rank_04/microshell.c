#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ft_execute(char **argv, int counter, int tmp_fd, char **envp)
{
	argv[counter] = NULL;  // This Line Is Used to make a mark on the end of the command ";" or a pipe "|"
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, envp);
	putstr("Error Cannot be executed", NULL);
	exit (1);
}


int main(int argc, char **argv, **envp)
{
	int counter = 0;
	int fd[2];
	int tmp_fd = dup(STDIN_FILENO);


	if (argc > 1)
	{
		while (argv[counter] && argv[counter + 1])
		{
			argv = &argv[counter + 1];
			counter++;
			while (argv[counter] && strcmp(argv[counter], ";") && strcmp(argv[counter], "|"))
				counter++;
			if (strcmp(argv[0], "cd") == 0) // In case of cd commande
			{
				if (counter != 2)
					putstr ("Error: cd: Bad arguments", NULL);
				else if (chdir(argv[1] != 0)
					putstr("error: cd: cannot change directory to ", argv[1]);
			}
			else if (counter != 0 (argv[counter] == NULL || strcmp(argv[counter], ";") == 0)) // In case Of A normal comamde 
			{
				if (fork() == 0)
					ft_execute(argv, counter, tmp_fd, env);
				else
				{
					close(tmp_fd);
					while (waitpid(-1, NULL, WUNTRACED) != -1));
					tmp_fd = dup(STDIN_FILENO);
				}
			}
	}

}
