/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:34:35 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:21:51 by frubio-i         ###   ########.fr       */
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
	second_tail = *lst;
	while (i < list_size(*lst) - 2)
	{
		second_tail = second_tail->next;
		i++;
	}
	tail = second_tail->next;
	second_tail->next = NULL;
	tail->next = *lst;
	*lst = tail;
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
