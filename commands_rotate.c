/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:03 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:26:03 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps **a, int to_write)
{
	rotate(a);
	if (to_write)
		write(1, "ra\n", 3);
}

void	rb(t_ps **b, int to_write)
{
	rotate(b);
	if (to_write)
		write(1, "rb\n", 3);
}

void	rr(t_ps **a, t_ps **b, int to_write)
{
	rotate(a);
	rotate(b);
	if (to_write)
		write(1, "rr\n", 3);
}
