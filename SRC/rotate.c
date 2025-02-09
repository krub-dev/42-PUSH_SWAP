/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:34:21 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:22:24 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcion rotate general
void	rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	tail = *lst;
	tail = list_last(*lst);
	tail->next = head;
	*lst = head->next;
	head->next = NULL;
}

/* ra rotate a: Desplaza hacia arriba todos los elementos del stack a una 
 posición, de forma que el primer elemento se convierte en el último. */
void	rotate_a(t_list **lst_a)
{
	rotate(lst_a);
	ft_printf("ra\n");
}

/* rb rotate b: Desplaza hacia arriba todos los elementos del stack b una 
 posición, de forma que el primer elemento se convierte en el último. */
void	rotate_b(t_list **lst_b)
{
	rotate(lst_b);
	ft_printf("rb\n");
}

// rr ra y rb al mismo tiempo.
void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	ft_printf("rr\n");
}
