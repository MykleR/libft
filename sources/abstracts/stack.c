/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:39:57 by mrouves           #+#    #+#             */
/*   Updated: 2025/02/20 23:09:07 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

void	stack_push(t_stack *stack, void *data)
{
	collection_append(stack, data);
}

void	stack_pops(t_stack *stack, uint32_t nb)
{
	while (stack->len && nb--)
		stack_pop(stack);
}

void	*stack_pop(t_stack *stack)
{
	return (collection_get(stack, --stack->len));
}

void	*stack_top(t_stack *stack)
{
	return (collection_get(stack, stack->len - 1));
}
