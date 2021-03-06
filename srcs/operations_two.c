/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 17:07:26 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_ps **b, t_ps **a, t_operations **operations)
{
	t_ps *l;

	if ((*b) && (*b)->next)
	{
		l = (*b)->next;
		(*b)->next = l->next;
		l->next = (*b);
		(*b) = l;
		create_list_oper(operations, a, b, "sb");
	}
}

void	pb(t_ps **a, t_ps **b, t_operations **operations)
{
	t_ps *l;

	if (*a)
	{
		if (NULL == (*b))
		{
			(*b) = (*a);
			(*a) = (*a)->next;
			(*b)->next = NULL;
		}
		else
		{
			l = (*a)->next;
			(*a)->next = (*b);
			(*b) = (*a);
			(*a) = l;
		}
		create_list_oper(operations, a, b, "pb");
	}
}

void	rb(t_ps **b, t_ps **a, t_operations **operations)
{
	t_ps *l;
	t_ps *tmp;

	if ((*b) && (*b)->next)
	{
		l = (*b);
		tmp = (*b)->next;
		while (l->next)
			l = l->next;
		l->next = (*b);
		(*b)->next = NULL;
		(*b) = tmp;
		create_list_oper(operations, a, b, "rb");
	}
}

void	rrb(t_ps **b, t_ps **a, t_operations **operations)
{
	t_ps *l;
	t_ps *tmp;

	if ((*b) && (*b)->next)
	{
		l = (*b);
		while (l->next->next)
			l = l->next;
		tmp = l->next;
		l->next = NULL;
		tmp->next = (*b);
		(*b) = tmp;
		create_list_oper(operations, a, b, "rrb");
	}
}

void	ss(t_ps **a, t_ps **b, t_operations **operations)
{
	t_ps *l;

	if ((*b) && (*b)->next)
	{
		l = (*b)->next;
		(*b)->next = l->next;
		l->next = (*b);
		(*b) = l;
	}
	if ((*a) && (*a)->next)
	{
		l = (*a)->next;
		(*a)->next = l->next;
		l->next = (*a);
		(*a) = l;
	}
	create_list_oper(operations, a, b, "ss");
}
