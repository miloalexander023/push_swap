/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:19:46 by miloalex          #+#    #+#             */
/*   Updated: 2026/08/08 16:40:24 by miloalex         ###   ########.fr       */
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
void	fill_stack_b(t_data *data);

void	update_pos(t_data *s, char sign);
void	pos_a(t_data *s);
void	pos_b(t_data *s);


int	main(int argc, char **argv);
void	add_to_stacktail(t_stack **head, t_stack *new);
long    ft_atol_checked(const char *str);

t_data	*sa(t_data *s);
t_data	*sb(t_data *s);
t_data *ss(t_data *s);
t_data	*pa(t_data *s);
t_data	*pb(t_data *s);
t_data	*ra(t_data *s);
t_data	*rb(t_data *s);
t_data *rr(t_data *s);
t_data *rra(t_data *s);
t_data *rrb(t_data *s);
t_data *rrr(t_data *s);

void	determin_index(t_data *s, char sign);
void index_a(t_data *s);
void index_b(t_data *s);
int find_pos(int *sorted, int arr_size, int value);
void	sort_array(int *arr, int arr_size);

void	find_targetnumber(t_data *s);

#endif