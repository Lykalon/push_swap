/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:50 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:26:50 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	list_utilization(t_ps **list)
{
	t_ps	*first;
	t_ps	*temp;

	first = *list;
	first->prev->next = NULL;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		free(temp);
	}
	*list = NULL;
}

int	list_lenght(t_ps *first)
{
	t_ps	*temp;
	int		count;

	count = 1;
	if (first == NULL)
		return (0);
	temp = first;
	while (temp->next != first)
	{
		count += 1;
		temp = temp->next;
	}
	return (count);
}
