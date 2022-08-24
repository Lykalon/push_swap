/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:38 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:26:38 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps	*new_list_item(int num, int index)
{
	t_ps	*new;

	new = malloc(sizeof(t_ps));
	new->next = new;
	new->prev = new;
	new->num = num;
	new->index = index;
	return (new);
}

void	list_push_back(t_ps **stack, t_ps *item)
{
	t_ps	*temp;
	t_ps	*first;

	if (!*stack)
	{
		*stack = item;
		return ;
	}
	first = *stack;
	temp = first->prev;
	first->prev = item;
	item->next = first;
	temp->next = item;
	item->prev = temp;
}

void	list_init(char **argv, t_ps **start, int *index)
{
	int		i;
	int		j;
	t_ps	*temp;
	int		num;

	i = 1;
	j = 0;
	while (argv[i])
	{
		num = atoi_special(argv[i], index);
		while (index[j] != num)
			++j;
		temp = new_list_item(num, j);
		list_push_back(start, temp);
		j = 0;
		++i;
	}
	free(index);
}
