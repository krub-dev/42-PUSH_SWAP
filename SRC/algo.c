/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:56:35 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/27 21:32:33 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// RADIX - Algoritmo general (argc > 5)
void	radix_algo(t_list **lst_a, t_list **lst_b)
{
	int		len;

	to_index(lst_a);
	while (is_sorted(*lst_a) == 1)
	{
		len = list_size(*lst_a);
		while (len--)
		{
			if ((*lst_a)->index & 1)
				rotate_a(lst_a);
			else
				push_b(lst_a, lst_b);
		}
		while (*lst_b)
			push_a(lst_b, lst_a);
		update_index(*lst_a);
	}
}

// Pasa al siguiente digito en el binario de index
void	update_index(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->index >>= 1;
		tmp = tmp->next;
	}
}
