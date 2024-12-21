/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:50 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/27 03:52:37 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Crear e inicializar nuevo nodo
t_list	*list_newnode(t_list **lst)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = (*lst);
	return (new_node);
}

// Recorrer lista para sacar ultimo nodo
t_list	*list_last(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

// Recorrer lista haciendo X cosa (utilizada durante proyecto)
void	list_iter(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
}

// Mide el size de la lista
int	list_size(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	if (!tmp)
		return (i);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
