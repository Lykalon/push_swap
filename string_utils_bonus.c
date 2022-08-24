/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:28:05 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:28:05 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_char(char ch, int *index)
{
	if (ch < 48 || ch > 57)
	{
		write(2, "Error\n", 6);
		free(index);
		exit(1);
	}
}

static void	ft_isnegative(const char *str, int *i, int *sign)
{
	int	count;

	count = 0;
	if (str[*i] == '-')
	{
		*sign = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
	while (str[*i] == '0')
	{
		*i = *i + 1;
		count += 1;
	}
	if (str[*i] == '\0' && count > 0)
		*i = *i - 1;
}

int	atoi_special(char *str, int *index)
{
	int			i;
	int			ch;
	int			sgn;
	long long	result;

	i = 0;
	sgn = 1;
	result = 0;
	ch = 0;
	ft_isnegative(str, &i, &sgn);
	if (str[i] == '\0' || *str == ' ')
		check_char(0, index);
	while (str[i] && ch <= 11)
	{
		check_char(str[i], index);
		result = result * 10 + str[i] - 48;
		i++;
		ch++;
	}
	result *= sgn;
	if (result > 2147483647 || result < -2147483648)
		check_char(0, index);
	return ((int)result);
}
