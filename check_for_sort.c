/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:25:18 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:25:18 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_sort(t_ps *stack)
{
	t_ps	*temp;

	temp = stack->next;
	while (temp != stack)
	{
		if (temp->prev->num > temp->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
