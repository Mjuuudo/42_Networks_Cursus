#include "../Push_swap.h"

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar_fd('-');
		n *= -1;
		ft_putnbr_fd(n);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10));
		ft_putnbr_fd((n % 10));
	}
	else
		ft_putchar_fd(n + 48);
}
