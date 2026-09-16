/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloalex <miloalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:19:46 by miloalex          #+#    #+#             */
/*   Updated: 2026/09/16 23:59:09 by miloalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	int				target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;
	int		b_size;
	int		moves;
}	t_data;

void	printlist(t_stack *head);
t_stack	*new_node(int value);
void	fill_stack_a(t_data *data, char **argv, int argc);
void	free_stack(t_stack *stack, int size);


void	update_pos(t_data *s, char sign);
void	pos_a(t_data *s);
void	pos_b(t_data *s);
int		find_target_pos(t_data *s);

int		main(int argc, char **argv);
void	add_to_stacktail(t_stack **head, t_stack *new);
long	ft_atol_checked(const char *str);
int		is_sorted(t_data *s);
int		check_sign(const char *str);

t_data	*sa(t_data *s);
t_data	*sb(t_data *s);
t_data	*ss(t_data *s);

t_data	*pa(t_data *s);
t_data	*pb(t_data *s);
void	fix_head_a(t_stack *a, t_stack *first);
void	fix_head_b(t_stack *b, t_stack *first);

t_data	*ra(t_data *s);
t_data	*rb(t_data *s);
t_data	*rr(t_data *s);

t_data	*rra(t_data *s);
t_data	*rrb(t_data *s);
t_data	*rrr(t_data *s);

void	determin_index(t_data *s);
int		find_pos(int *sorted, int arr_size, int value);
void	sort_array(int *arr, int arr_size);

void	find_targetnumber_a(t_data *s);
int		check_target_a(t_data *s, t_stack *temp_a);

void	find_targetnumber_b(t_data *s);
int		check_target_b(t_data *s, t_stack *temp_a);

void	rotation_cost(t_data *s);
void	r_cost_a(t_data *s);
void	r_cost_b(t_data *s);

t_stack	*cheapest(t_data *s);
int		target_cost(int a_cost, int b_cost);
t_stack	*find_target(t_stack *b, int target);

t_data	*rotate_push(t_data *s, t_stack *push_nbr);
void	positive_rotations(t_data *s, int a_cost, int b_cost);
void	negative_rotations(t_data *s, int a_cost, int b_cost);
void	a_negative_rotations(t_data *s, int a_cost, int b_cost);
void	b_negative_rotations(t_data *s, int a_cost, int b_cost);

t_data	*turk_sort(t_data *s);
void	sort_stack_of_3(t_data *s);
void	rotate_a_to_pos(t_data *s, int target_pos);
void	push_back_to_a(t_data *s);

int is_valid(char **argv, int argc);
int	is_valid_number(const char *str);

#endif