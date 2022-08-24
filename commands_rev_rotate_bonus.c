/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rev_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:25:57 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:25:57 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_ps **a, int to_write)
{
	rev_rotate(a);
	if (to_write)
		write(1, "rra\n", 4);
}

void	rrb(t_ps **b, int to_write)
{
	rev_rotate(b);
	if (to_write)
		write(1, "rrb\n", 4);
}

void	rrr(t_ps **a, t_ps **b, int to_write)
{
	rev_rotate(a);
	rev_rotate(b);
	if (to_write)
		write(1, "rrr\n", 4);
}
