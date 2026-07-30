/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:19:46 by miloalex          #+#    #+#             */
/*   Updated: 2026/07/30 21:17:32 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	int		pos;
	int		cost;
	int		target;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;
	int 	b_size;
} t_data;

void	printlist(t_stack *head);
t_stack	*new_node(int value);
void	fill_stack_a(t_data *data, char **argv, int argc);
int	main(int argc, char **argv);
void	add_to_stacktail(t_stack **head, t_stack *new);
long    ft_atol_checked(const char *str);

#endif