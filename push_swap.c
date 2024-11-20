/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:56:29 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:02:33 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Usado de momento (mover a funcion principal, o no)
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		argctmp;

	a = NULL;
	b = NULL;
	argctmp = argc;
	check_nbr_rep(argc, argv);
	check_syntax(argc, argv);
	if (argc > 2)
	{
		while (argc > 1)
		{
			a = list_newnode(&a); // crea nuevo nodo
			a->nbr = ft_atol(argv[argc - 1]); // introduce contenido a lista
			argc--;
		}
	}
	else
		return (0); // No devuelve nada cuando no hay argumentos
	check_limits_list(a);
	if (is_sorted(a) == 1)
		sort_algo(&a, &b, argctmp);
	free_list(&a);
	return (0);
}
