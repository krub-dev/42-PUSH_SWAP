/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:58:48 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:00:59 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Algoritmo 3 
void	sort_3(t_list **lst)
{
	while (1)
	{
		if (is_sorted(*lst) == 0)
			return ;
		if ((*lst)->next != NULL && ((*lst)->nbr > (*lst)->next->nbr
				&& (*lst)->nbr > (*lst)->next->next->nbr))
			rotate_a(lst);
		else if ((*lst)->next != NULL && ((*lst)->nbr < (*lst)->next->nbr
				&& (*lst)->nbr > (*lst)->next->next->nbr))
			rotate_a(lst);
		else
			swap_a(lst);
	}
}

// Algoritmo 4 
void	sort_4(t_list **lst_a, t_list **lst_b)
{
	int		min;
	int		i;
	t_list	*tmp;

	tmp = *lst_a;
	min = INT_MIN;
	i = 0;
	min = min_nbr(min, *lst_a);
	while (tmp)
	{
		if (tmp->nbr != min)
		{
			rotate_a(lst_a);
			tmp = *lst_a;
		}
		else
			break ;
	}
	push_b(lst_a, lst_b);
	sort_3(lst_a);
	push_a(lst_b, lst_a);
}

// Algoritmo 5 
void	sort_5(t_list **lst_a, t_list **lst_b)
{
	int		min;
	t_list	*tmp;

	tmp = *lst_a;
	min = INT_MIN;
	min = min_nbr(min, *lst_a);
	while (tmp)
	{
		if (tmp->nbr != min)
		{
			rotate_a(lst_a);
			tmp = *lst_a;
		}
		else
			break ;
	}
	push_b(lst_a, lst_b);
	sort_4(lst_a, lst_b);
	sort_3(lst_a);
	push_a(lst_b, lst_a);
	push_a(lst_b, lst_a);
}

// Algoritmo (preparacion) general (argc > 5)
void	sort_algo(t_list **lst_a, t_list **lst_b, int argc)
{
	if (argc == 3) // ordenamos directamente 2 (1 mov max)
		swap_a(lst_a);
	if (argc == 4) // ordenamos directamente 3 (2/3 mov max)
		sort_3(lst_a);
	if (argc == 5) // ordenamos directamente 4 (?? mov max)
		sort_4(lst_a, lst_b);
	if (argc == 6) // ordenamos directamente 5 (12 mov max)
		sort_5(lst_a, lst_b);
	if (argc > 6) // ordenamos con algoritmo general (Radix)
		radix_algo(lst_a, lst_b);
}
