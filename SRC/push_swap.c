/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:56:29 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/25 22:06:41 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcion que determina nuevo argc cuando hay split
int	new_argc_count(char *s)
{
	int		i;
	int		nargc;

	i = 0;
	nargc = 0;
	if (!s || !*s)
		return (0);
	if (s[0] != ' ')
		nargc++;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0')
			nargc++;
		i++;
	}
	return (nargc);
}

// Funcion que inicializa la lista segun si ha hecho split o normal (con flag)
void	init_list(int argc, char **argv, t_list **a, int flag)
{
	if (flag == 0)
	{
		while (argc >= 2)
		{
			*a = list_newnode(a);
			(*a)->nbr = ft_atol(argv[argc - 1]);
			argc--;
		}
	}
	else
	{
		while (argc >= 1)
		{
			*a = list_newnode(a);
			(*a)->nbr = ft_atol(argv[argc - 1]);
			argc--;
		}
		ft_free_mem(argv);
	}
}

// Funcion principal que gestiona comportamiento, errores, free y final
int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	int			flag;

	a = NULL;
	b = NULL;
	flag = 0;
	if (argc == 2)
	{
		argc = new_argc_count(argv[1]);
		argv = ft_split(argv[1], ' ');
		flag = 1;
	}
	check_nbr_rep(argc, argv);
	check_syntax(argc, argv);
	init_list(argc, argv, &a, flag);
	check_limits_list(a);
	if (is_sorted(a) == 1)
		sort_algo(&a, &b, argc, flag);
	free_list(&a);
	return (0);
}
