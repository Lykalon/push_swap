/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:25:44 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:25:44 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps	*extract(t_ps **stack)
{
	t_ps	*extracted;
	t_ps	*last;
	t_ps	*first;

	extracted = *stack;
	last = *stack;
	last = last->prev;
	first = *stack;
	first = first->next;
	extracted->next = extracted;
	extracted->prev = extracted;
	if (extracted == first)
	{
		*stack = NULL;
		return (extracted);
	}
	first->prev = last;
	last->next = first;
	*stack = first;
	return (extracted);
}

void	swap(t_ps **stack)
{
	t_ps	*first;
	t_ps	*second;

	first = extract(stack);
	second = extract(stack);
	list_push_back(stack, first);
	rev_rotate(stack);
	list_push_back(stack, second);
	rev_rotate(stack);
}

void	push(t_ps **src, t_ps **dst)
{
	t_ps	*temp;

	temp = extract(src);
	list_push_back(dst, temp);
	rev_rotate(dst);
}

void	rotate(t_ps **stack)
{
	t_ps	*temp;

	if (*stack != NULL)
	{
		temp = *stack;
		temp = temp->next;
		*stack = temp;
	}
}

void	rev_rotate(t_ps **stack)
{
	t_ps	*temp;

	if (*stack != NULL)
	{
		temp = *stack;
		temp = temp->prev;
		*stack = temp;
	}
}
