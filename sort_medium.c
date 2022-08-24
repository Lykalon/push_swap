/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:41 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:27:41 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_ps **a, t_ps **b)
{
	int	min;
	int	max;
	int	max_index;

	min = 0;
	max = 15;
	first_run(a, b, min, max);
	max_index = list_lenght(*b) - 1;
	second_run(a, b, max_index);
}
