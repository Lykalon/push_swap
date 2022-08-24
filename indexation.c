/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:27 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:26:27 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_repeats(int *index, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (index[i] == index[i + 1])
		{
			write(2, "Error\n", 6);
			free(index);
			exit(1);
		}
		i++;
	}
}

static void	bubble_sort(int *index, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (j < len - 1)
	{
		while (i < len - 1)
		{
			if (index[i] > index[i + 1])
			{
				temp = index[i];
				index[i] = index[i + 1];
				index[i + 1] = temp;
			}
			++i;
		}
		--len;
		i = 0;
		j = 0;
	}
}

int	*indexation(char **argv, int argc)
{
	int	*index;
	int	i;

	i = 0;
	index = 0;
	index = malloc(sizeof(int) * (argc - 1));
	if (!index)
	{
		write(2, "Error\n", 6);
		exit (-1);
	}
	while (i < argc - 1)
	{
		index[i] = atoi_special(argv[i + 1], index);
		++i;
	}
	bubble_sort(index, argc - 1);
	check_repeats(index, argc);
	return (index);
}
