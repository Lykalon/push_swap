/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:54 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:27:54 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	direction_to_rotate(t_ps **a, int index)
{
	t_ps	*temp;
	int		count_r;
	int		count_rr;

	count_r = 0;
	count_rr = 0;
	temp = *a;
	while (temp->index != index)
	{
		temp = temp->next;
		++count_r;
	}
	temp = *a;
	while (temp->index != index)
	{
		temp = temp->prev;
		++count_rr;
	}
	if (count_r <= count_rr)
		return (1);
	else
		return (0);
}

static void	sort_three(t_ps **a)
{
	t_ps	*temp;
	int		first;
	int		second;
	int		third;

	temp = *a;
	first = temp->num;
	second = temp->next->num;
	third = temp->next->next->num;
	if (first < second && second < third)
		return ;
	if (third > first && third > second)
		sa(a, 1);
	else if (first > second && first > third)
	{
		ra(a, 1);
		if (second > third)
			sa(a, 1);
	}
	else if (second > first && second > third)
	{
		rra(a, 1);
		if (third > first)
			sa(a, 1);
	}
}

static void	sort_four(t_ps **a, t_ps **b, int index)
{
	if (direction_to_rotate(a, index))
		while ((*a)->index != index)
			ra(a, 1);
	else
		while ((*a)->index != index)
			rra(a, 1);
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

static void	sort_five(t_ps **a, t_ps **b)
{
	if (direction_to_rotate(a, 0))
		while ((*a)->index != 0)
			ra(a, 1);
	else
		while ((*a)->index != 0)
			rra(a, 1);
	pb(a, b, 1);
	sort_four(a, b, 1);
	pa(a, b, 1);
}

void	sort_small(t_ps **a, t_ps **b, int len)
{
	if (len == 2)
		sa(a, 1);
	if (len == 3)
		sort_three(a);
	if (len == 4)
		sort_four(a, b, 0);
	if (len == 5)
		sort_five(a, b);
}
