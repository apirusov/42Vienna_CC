/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:06:19 by apirusov          #+#    #+#             */
/*   Updated: 2024/07/28 14:38:02 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_matrix(char **matrix)
{
	ssize_t	i;

	i = -1;
	if (!*matrix || !matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix - 1);
}

void	*free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!*stack || !stack)
		return (NULL);
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	return (NULL);
}

void	ft_free_error(t_stack_node **a, char **matrix, bool ac_2)
{
	free_stack(a);
	if (ac_2)
		free_matrix(matrix);
	ft_puterror("Error\n");
	exit(EXIT_FAILURE);
}

int	error_syntax(char *str_num)
{
	if (!*str_num || !str_num)
		return (1);
	if (!(*str_num == '-' || *str_num == '+' || ft_isdigit(*str_num)))
		return (1);
	if ((*str_num == '-' || *str_num == '+') && !ft_isdigit(*(str_num + 1)))
		return (1);
	while (*++str_num)
	{
		if (!ft_isdigit(*str_num))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}
