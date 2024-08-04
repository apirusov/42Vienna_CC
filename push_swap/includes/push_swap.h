/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:54:07 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 15:56:44 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/printf/includes/ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					final_index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Errors-free
void			free_matrix(char **av);
void			ft_free_error(t_stack_node **a, char **matrix, bool ac_2);
void			*free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int num);
int				error_syntax(char *str_num);

// Stack creation
void			stack_init(t_stack_node **a, char **av, bool ac_2);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_index(t_stack_node *stack);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

// Linked list utils
void			append_node(t_stack_node **stack, int value_to_pass);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
size_t			stack_size(t_stack_node *stack);
void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);
void			rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
//void	move_nodes(t_stack_node **a, t_stack_node **b);

// Algorithms
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

// Commands
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

#endif
