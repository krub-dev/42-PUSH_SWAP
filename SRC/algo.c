/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:56:35 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:25:56 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// RADIX - Algoritmo general (argc > 5)
void	radix_algo(t_list **lst_a, t_list **lst_b)
{
	int		len;
	t_list	*tmp;

	to_index(lst_a);
	while (1)
	{
		if (is_sorted(*lst_a) == 0)
			break ;
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
		tmp = *lst_a;
		while (tmp)
		{
			tmp->index >>= 1;
			tmp = tmp->next;
		}
	}
}
