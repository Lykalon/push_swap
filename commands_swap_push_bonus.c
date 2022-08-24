/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap_push_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:18 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:26:18 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_ps **a, int to_write)
{
	if (list_lenght(*a) > 1)
		swap(a);
	if (to_write)
		write(1, "sa\n", 3);
}

void	sb(t_ps **b, int to_write)
{
	if (list_lenght(*b) > 1)
		swap(b);
	if (to_write)
		write(1, "sb\n", 3);
}

void	ss(t_ps **a, t_ps **b, int to_write)
{
	if (list_lenght(*a) > 1)
		swap(a);
	if (list_lenght(*b) > 1)
		swap(b);
	if (to_write)
		write(1, "ss\n", 3);
}

void	pa(t_ps **a, t_ps **b, int to_write)
{
	if (list_lenght(*b) > 0)
		push(b, a);
	if (to_write)
		write(1, "pa\n", 3);
}

void	pb(t_ps **a, t_ps **b, int to_write)
{
	if (list_lenght(*a) > 0)
		push(a, b);
	if (to_write)
		write(1, "pb\n", 3);
}
