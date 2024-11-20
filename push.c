/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:34:11 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/20 23:59:49 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcion push general.
void	push(t_list **lst_src, t_list **lst_dst)
{
	t_list	*head;

	if (!lst_src || !*lst_src)
		return ;
	head = *lst_src; // Head apunta a primer nodo de src
	*lst_src = head->next; // Primer nodo de src apunta ahora al siguiente
	head->next = *lst_dst; // Primer nodo apunta a primero de destino
	*lst_dst = head; // Apuntamos inicio de destino a nuevo nodo (Head)
}

// pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
// a. No hace nada si b está vacío.
void	push_a(t_list **lst_b, t_list **lst_a)
{
	if (list_size(*lst_b) != 0)
	{
		push(lst_b, lst_a);
		ft_printf("pa\n");
	}
	return ;
}

// pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
// b. No hace nada si a está vacío.
void	push_b(t_list **lst_a, t_list **lst_b)
{
	if (list_size(*lst_a) != 0)
	{
		push(lst_a, lst_b);
		ft_printf("pb\n");
	}
	return ;
}
