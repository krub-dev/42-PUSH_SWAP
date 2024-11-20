/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:03:30 by frubio-i          #+#    #+#             */
/*   Updated: 2024/11/20 23:58:41 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./LIBFT/libft.h"
# include "./LIBFT/ft_printf.h"

# include <stdio.h>		// printf original
# include <stdlib.h>	// malloc, atoi
# include <unistd.h>	// write
# include <fcntl.h>		// read
# include <limits.h>	// int_max / int_min
# include <string.h>	// strlen

// Struct List \\_________________________________________

typedef struct s_list
{
	long			nbr;
	int				index;
	struct s_list	*next;
}	t_list;

// Push_swap.c -> Funcion principal

int		main(int argc, char **argv);

// Check_error_free.c -> Funciones que manejan errores y libera nodos

void	check_errors(int argc, t_list **lst_a, t_list **lst_b);
void	check_nbr_rep(int argc, char **argv);
void	check_syntax(int argc, char **argv);
void	check_limits_list(t_list *lst);
void	free_list(t_list **lst);

// Utils.c -> Funciones de utilidad (listas)

t_list	*list_newnode(t_list **lst);
void	list_iter(t_list *lst);
t_list	*list_last(t_list *lst);
int		list_size(t_list *lst);

// Utils_extra.c -> Funciones de utilidad general

long	ft_atol(const char *str);
int		is_sorted(t_list *lst);
void	to_index(t_list **lst);
int		max_nbr(int curr, t_list *lst);
int		min_nbr(int curr, t_list *lst);

// Path_to_sort.c -> Comprobacion/preparacion preordenacion

void	sort_3(t_list **lst);
void	sort_4(t_list **lst_a, t_list **lst_b);
void	sort_5(t_list **lst_a, t_list **lst_b);
void	sort_algo(t_list **lst_a, t_list **lst_b, int argc);

//	Algo.c -> Algoritmo de ordenacion

void	radix_algo(t_list **lst_a, t_list **lst_b);

// Instrucciones \\_______________________________________

//	Push.c -> Empuja un nodo de una lista a otra lista

void	push(t_list **lst_src, t_list **lst_dst);
void	push_a(t_list **lst_b, t_list **lst_a);
void	push_b(t_list **lst_a, t_list **lst_b);

// Swap.c -> Cambia la posicion de un nodo por la de otro

void	swap(t_list **lst);
void	swap_a(t_list **lst_a);
void	swap_b(t_list **lst_b);
void	swap_ab(t_list **lst_a, t_list **lst_b);

/* Rotate.c -> Convierte el primer nodo en el ultimo, 
 desplazando todo una posicion arriba */

void	rotate(t_list **lst);
void	rotate_a(t_list **lst_a);
void	rotate_b(t_list **lst_b);
void	rotate_ab(t_list **lst_a, t_list **lst_b);

/* Reverse_rotate.c -> Convierte el ultimo nodo en el primero, 
 desplazando todo una posicion abajo */

void	reverse_rotate(t_list **lst);
void	reverse_rotate_a(t_list **lst_a);
void	reverse_rotate_b(t_list **lst_b);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);

#endif
