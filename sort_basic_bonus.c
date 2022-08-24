/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:26 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:27:26 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	direction_to_rotate(t_ps **b, int max_index)
{
	t_ps	*temp;
	int		count_rb;

	count_rb = 0;
	temp = *b;
	while (temp->index != max_index)
	{
		temp = temp->next;
		++count_rb;
	}
	if (count_rb <= (list_lenght(*b) / 2))
		return (1);
	else
		return (0);
}

void	second_run(t_ps **a, t_ps **b, int max_index)
{
	int	direction;

	while (*b != NULL)
	{
		direction = direction_to_rotate(b, max_index);
		if (direction)
			while ((*b)->index != max_index)
				rb(b, 1);
		else
			while ((*b)->index != max_index)
				rrb(b, 1);
		pa(a, b, 1);
		--max_index;
	}
}

void	first_run(t_ps **a, t_ps **b, int min, int max)
{
	while (*a != NULL)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			pb(a, b, 1);
			++min;
			++max;
		}
		else if ((*a)->index > max)
			ra(a, 1);
		else if ((*a)->index < min)
		{
			pb(a, b, 1);
			rb(b, 1);
			++min;
			++max;
		}
	}
}