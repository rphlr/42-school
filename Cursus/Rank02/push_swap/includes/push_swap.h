/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 08:13:08 by marvin            #+#    #+#             */
/*   Updated: 2023/04/16 08:13:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylib/includes/mylib.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define WHITE "\e[37m"
# define RESET "\e[0m"
# define BOLD "\e[1m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// file_utils.c
int		find_value_at_index(t_stack *stack, int index);
void	update_value_at_index(t_stack *stack, int index, int new_value);
void	swap_values(t_stack *stack, int i, int j);
int		stack_get_value(t_stack *stack, int index);
int		get_index(t_stack **stack, int num);

// main.c
char	**prepend_program_name(char *program_name, char **argv);
char	**split_arguments(char *arg);
int		main(int argc, char **argv);

// printing.c
void	print_stack(t_stack *stack, char *title);
void	print_stacks(t_stack *a, t_stack *b, char *title);

// push_swap.c
t_stack	*sort_copy(t_stack *stack);
void	push_swap(t_stack *a, t_stack *b);
int		count_args(char **argv);

// quicksort.c
t_stack	*sort_stack(t_stack *stack);
void	swap(int *a, int *b);
int		partition(t_stack *stack, int low, int high);
void	quicksort(t_stack *stack, int low, int high);

// reverse_rotation.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// rotation.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// sorting_stack.c
void	sort_small(t_stack **a, t_stack **b);
void	sort_large(t_stack **a, t_stack **b);
void	sort_three_elements(t_stack **a);
void	sort_chunks(t_stack **a, t_stack **b, t_stack *sorted_a, int size);
void	sort_remaining(t_stack **a, t_stack **b);

// stack_access.c
void	stack_push(t_stack **stack, int value);
bool	stack_contains(t_stack *stack, int value);
int		stack_size(t_stack *stack);
t_stack	*parse_and_create_stack(int argc, char **argv);

// stack_operations.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// stack_utility.c
bool	is_sorted(t_stack *stack);
bool	is_number(const char *str);
bool	is_int(const char *str);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);

// utils.c
int		find_key_nbr(t_stack *stack, int divider);
void	move_rb(t_stack **b, int *max_index);
void	move_rrb(t_stack **b, int *max_index);
void	approximity_b(t_stack **b, int num);
void	approximity(t_stack **a, int num);

#endif