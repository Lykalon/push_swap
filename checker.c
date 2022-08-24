/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:25:30 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:25:30 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	status(int stat)
{
	if (stat == 0)
		write(1, "OK\n", 3);
	else if (stat == 1)
		write(1, "KO\n", 3);
	else
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

int	set_value(char a)
{
	if (a == 'a')
		return (1);
	else if (a == 'b')
		return (2);
	else if (a == 's')
		return (3);
	else if (a == 'p')
		return (4);
	else if (a == 'r')
		return (5);
	else
		return (-1000);
}

void	func_map(int func, t_ps **a, t_ps **b)
{
	if (func == 31)
		sa(a, 0);
	else if (func == 32)
		sb(b, 0);
	else if (func == 33)
		ss(a, b, 0);
	else if (func == 41)
		pa(a, b, 0);
	else if (func == 42)
		pb(a, b, 0);
	else if (func == 51)
		ra(a, 0);
	else if (func == 52)
		rb(b, 0);
	else if (func == 55)
		rr(a, b, 0);
	else if (func == 551)
		rra(a, 0);
	else if (func == 552)
		rrb(b, 0);
	else if (func == 555)
		rrr(a, b, 0);
	else
		status(2);
}

void	perform(t_ps **a, t_ps **b)
{
	char		one[1];
	long		was_red;
	int			func;
	int			mod;

	func = 0;
	while (1)
	{
		was_red = read(0, one, 1);
		if (was_red == 0)
			break ;
		if (one[0] == '\n')
		{
			func_map(func, a, b);
			func = 0;
		}
		else
		{
			mod = set_value(one[0]);
			func = func * 10 + mod;
		}
	}
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
		perform(&a, &b);
		if (check_for_sort(a) && !b)
			status(0);
		else
			status(1);
		if (b != NULL)
			list_utilization(&b);
		list_utilization(&a);
	}
	exit (0);
}
