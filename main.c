/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:57 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:26:57 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps **a, t_ps **b)
{
	int	len;

	len = list_lenght(*a);
	if (len <= 5)
		sort_small(a, b, len);
	else if (len > 5 && len <= 100)
		sort_medium(a, b);
	else
		sort_large(a, b);
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	int		*index;

	a = 0;
	b = 0;
	if (argc > 1)
	{
		index = indexation(argv, argc);
		list_init(argv, &a, index);
		if (check_for_sort(a))
		{
			list_utilization(&a);
			return (0);
		}
		push_swap(&a, &b);
		list_utilization(&a);
	}
	return (0);
}
