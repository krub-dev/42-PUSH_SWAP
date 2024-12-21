/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:36:41 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/24 08:14:24 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprueba si hay duplicados
void	check_nbr_rep(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
}

// Comprueba si hay characteres invalidos (alfabeto + simbolos)
void	check_syntax(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == ' ')
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
}

// Comprueba que ningun argumento convertido sea > que MAX_INT o < que MIN_INT
void	check_limits_list(t_list *lst)
{
	t_list	*tmp;
	int		check;

	check = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->nbr > INT_MAX || tmp->nbr < INT_MIN)
			check = 1;
		tmp = tmp->next;
	}
	if (check != 0)
	{
		free_list(&lst);
		exit(write(2, "Error\n", 6));
	}
	else
		return ;
}

// Liberar memoria de todos los nodos de una lista
void	free_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*curr;

	if (lst == NULL)
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*lst = NULL;
}
