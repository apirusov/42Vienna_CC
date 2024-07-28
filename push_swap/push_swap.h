#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
//# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../printf/includes/ft_printf.h"

typedef struct s_stack_mode
{
    int value;
    int index;
    int final_index;
    int push_cost;
    bool above_median;
    bool cheapest;

    struct s_stuck_node *target_node;
    struct s_stuck_node *next;
    struct s_stuck_node *prev;
}   t_stack_node;

// Errors-free
void free_matrix(char **av);
void error_free(t_stack_node **a, char **av, bool flag_ac_2);
void free_stack(t_stack_node **stack);
int error_repetition(t_stack_node *a, int num);
int error_syntax(char *str_num);

// Stack creation
void stack_init(t_stack_node **a, char **av, bool flag_ac_2);
void init_nodes(t_stack_node *a, t_stack_node *b);
void set_cur_pos(t_stack_node *stack);
void set_price(t_stack_node *a, t_stack_node *b);
void set_cheapest(t_stack_node *b);

// Linked list utils
void append_node(t_stack_node **stack, int num);
t_stack_node *find_last(t_stack_node *head);
t_stack_node *find_smallest(t_stack_node *stack);
t_stack_node *return_cheapest(t_stack_node *stack);
bool stack_sorted(t_stack_node *stack);
int stack_len(t_stack_node *stack);
void finish_rotation(t_stack_node **s, t_stack_node *n, char c);

// Algorithms
void tiny_sort(t_stack_node **a);
void handle_five(t_stack_node **a, t_stack_node **b);
void push_swap(t_stack_node **a, t_stack_node **b);

// Commands
void sa(t_stack_node **a, bool checker);
void sb(t_stack_node **b, bool checker);
void ss(t_stack_node **a, t_stack_node **b, bool checker);
void ra(t_stack_node **a, bool checker);
void rb(t_stack_node **b, bool checker);
void rr(t_stack_node **a, t_stack_node **b, bool checker);
void rra(t_stack_node **a, bool checker);
void rrb(t_stack_node **b, bool checker);
void rrr(t_stack_node **a, t_stack_node **b, bool checker);
void pa(t_stack_node **a, t_stack_node **b, bool checker);
void pb(t_stack_node **b, t_stack_node **a, bool checker);

#endif