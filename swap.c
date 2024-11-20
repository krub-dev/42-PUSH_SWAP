/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:33:54 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/20 23:59:00 by frubio-i         ###   ########.fr       */
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
	head = *lst; // Head apunta a primer nodo
	second = head->next; // Second apunta a segundo nodo
	head->next = second->next; // Primer nodo (Head) apunta al tercero
	second->next = head; // Segundo nodo apunta al primero (Head)
	*lst = second; // Segundo nodo se convierte en el nuevo primer nodo (Head)
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
