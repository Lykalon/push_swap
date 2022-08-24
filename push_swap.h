/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:04 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 17:27:04 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	int			num;
	int			index;
	struct s_ps	*next;
	struct s_ps	*prev;
}				t_ps;

int		atoi_special(char *str, int *index);
int		*indexation(char **argv, int argc);
void	list_init(char **argv, t_ps **start, int *index);
void	list_push_back(t_ps **stack, t_ps *item);
int		check_for_sort(t_ps *stack);
void	swap(t_ps **stack);
void	push(t_ps **src, t_ps **dst);
void	rotate(t_ps **stack);
void	rev_rotate(t_ps **stack);
void	sa(t_ps **a, int to_write);
void	sb(t_ps **b, int to_write);
void	ss(t_ps **a, t_ps **b, int to_write);
void	pa(t_ps **a, t_ps **b, int to_write);
void	pb(t_ps **a, t_ps **b, int to_write);
void	ra(t_ps **a, int to_write);
void	rb(t_ps **b, int to_write);
void	rr(t_ps **a, t_ps **b, int to_write);
void	rra(t_ps **a, int to_write);
void	rrb(t_ps **b, int to_write);
void	rrr(t_ps **a, t_ps **b, int to_write);
int		list_lenght(t_ps *first);
void	first_run(t_ps **a, t_ps **b, int min, int max);
void	second_run(t_ps **a, t_ps **b, int max_index);
void	sort_small(t_ps **a, t_ps **b, int len);
void	sort_medium(t_ps **a, t_ps **b);
void	sort_large(t_ps **a, t_ps **b);
void	list_utilization(t_ps **list);

#endif
