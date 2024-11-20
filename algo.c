/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:56:35 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/21 00:01:03 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// RADIX - Algoritmo general (argc > 5)
void	radix_algo(t_list **lst_a, t_list **lst_b)
{
	int		len;
	t_list	*tmp;

	to_index(lst_a);
	while (1) // En bucle mientras no esta ordenada
	{
		if (is_sorted(*lst_a) == 0) // En bucle mientras no esta ordenada
			break ;
		len = list_size(*lst_a); // Reinicializamos len con el len anterior que guardamos
		while (len--) // Iteramos aqui por optimizacion de lineas (norma)
		{
			if ((*lst_a)->index & 1) // Si el binario de su index termina en 1, hacemos rotate a (ra)
				rotate_a(lst_a);
			else // Si lo hace en 0, hacemos push b (pb)
				push_b(lst_a, lst_b);
		}
		while (*lst_b) // Hacemos push a (pa) cuando tengamos
			push_a(lst_b, lst_a);
		tmp = *lst_a; // Igualamos tmp a lst_a
		while (tmp)
		{
			tmp->index >>= 1; // Corremos 1 Bit en cada uno de los nodos (index) para next iteracion
			tmp = tmp->next;
		}
	}
}
