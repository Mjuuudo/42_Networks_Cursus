#include "../push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	compteur;

	compteur = 0;
	if (!s)
		return ;
	while (s[compteur])
	{
		ft_putchar_fd(s[compteur]);
		compteur++;
	}
}
