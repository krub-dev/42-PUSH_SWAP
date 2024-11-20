/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:42:24 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:00:57 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Atol (basado en Atoi de LIBFT) que convierte str a long
long	ft_atol(const char *str)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

// Comprobacion si esta ordenado
int	is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (1);
	while (tmp->next != NULL)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (1); // No esta ordenada
		else
			tmp = tmp->next;
	}
	return (0); // Esta ordenada
}

// Indexar cada valor a su correspondiente indice
void	to_index(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		curr;

	tmp = *lst;
	i = 0;
	curr = INT_MIN; // Descomentar cuando queramos min
	//curr = INT_MAX; // Descomentar cuando queramos max
	while (i < list_size(tmp))
	{
		curr = min_nbr(curr, tmp); // Ordenamos de menor a mayor
		//max_nbr(curr, tmp); // Ordenamos de mayor a menor
		while (tmp->nbr != curr)
			tmp = tmp->next;
		tmp->index = i++;
		tmp = *lst;
	}
}

// Determina el nbr maximo de un nodo en una lista
int	max_nbr(int curr, t_list *lst)
{
	t_list	*tmp;
	int		max;

	max = INT_MIN;
	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->nbr < curr && tmp->nbr > max) // Encuentro el min excluyendo el anterior encontrado (curr)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

// Determina el nbr minimo de un nodo en una lista
int	min_nbr(int curr, t_list *lst)
{
	t_list	*tmp;
	int		min;

	min = INT_MAX;
	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->nbr > curr && tmp->nbr < min) // Encuentro el min excluyendo el anterior encontrado (curr)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}
