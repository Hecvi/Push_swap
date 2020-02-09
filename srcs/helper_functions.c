/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/09 18:36:48 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		cardinality(t_ps **stack)
{
	int		count;
	t_ps	*tmp;
	int		block;

	count = 0;
	if (!(*stack))
		return (0);
	tmp = (*stack);
	block = (*stack)->block;
	while (tmp && tmp->block == block)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int		find_min(t_ps **stack)
{
	t_ps	*tmp;
	t_ps	*min;
	int		block;
	int		minimum;

	if (NULL == (*stack))
		return (0);
	tmp = (*stack);
	min = (*stack);
	block = (*stack)->block;
	minimum = (*stack)->index;
	while (tmp && tmp->block == block)
	{
		if (tmp->index < minimum)
		{
			minimum = tmp->index;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min->index);
}

int		find_mid(t_ps **stack)
{
	int		mid;
	int		count;
	t_ps	*tmp;
	int		block;

	mid = 0;
	count = 0;
	if (!(*stack))
		return (0);
	if ((*stack)->sort)
		return (0);
	tmp = (*stack);
	block = (*stack)->block;
	while (tmp && tmp->block == block && tmp->sort != 1)
	{
		count++;
		mid = mid + tmp->index;
		tmp = tmp->next;
	}
	return (mid / count);
}

int		find_max(t_ps **stack)
{
	t_ps	*tmp;
	t_ps	*max;
	int		block;
	int		maximum;

	if (NULL == (*stack))
		return (0);
	tmp = (*stack);
	max = (*stack);
	block = (*stack)->block;
	maximum = (*stack)->index;
	while (tmp && tmp->block == block)
	{
		if (tmp->index > maximum)
		{
			maximum = tmp->index;
			max = tmp;
		}
		tmp = tmp->next;
	}
	return (max->index);
}

int		check_order_in_stack(t_ps **a)
{
	t_ps *tmp;

	tmp = (*a);
	while (tmp)
	{
		if (tmp->next)
			if (tmp->num > tmp->next->num)
				return (0);
		tmp = tmp->next;
	}
	return (1);
}
