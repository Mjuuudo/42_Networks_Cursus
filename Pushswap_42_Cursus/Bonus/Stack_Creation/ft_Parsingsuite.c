/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Parsingsuite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:01 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/23 15:17:49 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_creationofstack(t_stack_list **a, char *buffer, int flag_heapornot,
		char **buffer_big)
{
	long long	n;

	if (syntaxe_error(buffer))
		ft_freeerrors(a, buffer_big, flag_heapornot);
	n = ft_atol(buffer);
	if (n > INT_MAX || n < INT_MIN)
		ft_freeerrors(a, buffer_big, flag_heapornot);
	if (ft_checkrepetition(*a, (int)n))
		ft_freeerrors(a, buffer_big, flag_heapornot);
	ft_addnode(a, (int)n);
}

int	ft_checkargtype(char *arg)
{
	int	compteur;
	int	flag;

	compteur = 0;
	flag = 0;
	while (arg[compteur])
	{
		if (arg[compteur] == ' ')
			compteur++;
		else
			break ;
	}
	while (arg[compteur])
	{
		if ((arg[compteur] >= 48 && arg[compteur] <= 57))
			compteur++;
		else if (arg[compteur] == ' ')
		{
			flag = 1;
			break ;
		}
	}
	return (flag);
}

void	ft_hardcreation(t_stack_list **a, char *arg, int flag_heapornot)
{
	int			compteur;
	char		**buffer;
	long long	n;

	buffer = ft_split(arg, ' ');
	compteur = 0;
	while (buffer[compteur])
	{
		if (syntaxe_error(buffer[compteur]))
			ft_freeerrors(a, buffer, flag_heapornot);
		n = ft_atol(buffer[compteur]);
		if (n > INT_MAX || n < INT_MIN)
			ft_freeerrors(a, buffer, flag_heapornot);
		if (ft_checkrepetition(*a, (int)n))
			ft_freeerrors(a, buffer, flag_heapornot);
		ft_addnode(a, (int)n);
		compteur++;
	}
	ft_freeheapargv(buffer);
}

void	ft_stack_init_1(t_stack_list **a, char **argv, int flag_heapornot)
{
	long long	n;
	int			i;

	if (flag_heapornot == 1)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (syntaxe_error(argv[i]))
			ft_freeerrors(a, argv, flag_heapornot);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_freeerrors(a, argv, flag_heapornot);
		if (ft_checkrepetition(*a, (int)n))
			ft_freeerrors(a, argv, flag_heapornot);
		ft_addnode(a, (int)n);
		i++;
	}
	if (flag_heapornot)
		ft_freeheapargv(argv);
}

int  ft_check_space(const char *s)
{
	int compteur;
	int flag;

	compteur = 0;
	flag     = 1;
	while (s[compteur])
	{
		if (s[compteur] != ' ')
				return (0);
		compteur ++;
	}
	return (flag);
}