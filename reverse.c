/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:34:35 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/20 23:59:37 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcion reverse rotate general
void	reverse_rotate(t_list **lst)
{
	t_list	*tail;
	t_list	*second_tail;
	int		i;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	i = 0;
	second_tail = *lst; // Penultimo apunta a primer nodo
	while (i < list_size(*lst) - 2) // - 2 porque es penultimo o SEG.FAULT
	{
		second_tail = second_tail->next; // Recorremos hasta penultimo
		i++;
	}
	tail = second_tail->next; // Guardamos el ultimo nodo
	second_tail->next = NULL; // Penultimo apunta a NULL (se convierte en ultimo)
	tail->next = *lst; // Ultimo apunta a primer nodo
	*lst = tail; // Inicio de lista ahora apunta al ultimo nodo
}

/* rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a 
 una posición, de forma que el último elemento se convierte en el primero. */
void	reverse_rotate_a(t_list **lst_a)
{
	reverse_rotate(lst_a);
	ft_printf("rra\n");
}

/* rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b 
 una posición, de forma que el último elemento se convierte en el primero. */
void	reverse_rotate_b(t_list **lst_b)
{
	reverse_rotate(lst_b);
	ft_printf("rrb\n");
}

// rrr rra y rrb al mismo tiempo.
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	ft_printf("rrr\n");
}
