/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:33:54 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:22:57 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcion swap general.
void	swap(t_list **lst)
{
	t_list	*head;
	t_list	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	second = head->next;
	head->next = second->next;
	second->next = head;
	*lst = second;
}

/* sa swap a: Intercambia los dos primeros elementos del stack a. 
 No hace nada si hay uno o menos elementos. */
void	swap_a(t_list **lst_a)
{
	if (list_size(*lst_a) > 1)
	{
		swap(lst_a);
		ft_printf("sa\n");
	}
}

/* sb swap b: Intercambia los dos primeros elementos del stack b. 
 No hace nada si hay uno o menos elementos. */
void	swap_b(t_list **lst_b)
{
	if (list_size(*lst_b) > 1)
	{
		swap(lst_b);
		ft_printf("sb\n");
	}
}

// ss swap a y swap b a la vez.
void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	if (list_size(*lst_a) > 1)
		swap(lst_a);
	if (list_size(*lst_b) > 1)
		swap(lst_b);
	ft_printf("ss\n");
}
