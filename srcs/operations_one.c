/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 17:06:41 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_ps **a, t_ps **b, t_operations **operations)
{
	t_ps *l;

	if ((*a) && (*a)->next)
	{
		l = (*a)->next;
		(*a)->next = l->next;
		l->next = (*a);
		(*a) = l;
		create_list_oper(operations, a, b, "sa");
	}
}

void	pa(t_ps **b, t_ps **a, t_operations **operations)
{
	t_ps *l;

	if (*b)
	{
		l = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = l;
		create_list_oper(operations, a, b, "pa");
	}
}

void	ra(t_ps **a, t_ps **b, t_operations **operations)
{
	t_ps *l;
	t_ps *tmp;

	if ((*a) && (*a)->next)
	{
		l = (*a);
		tmp = (*a)->next;
		while (l->next)
			l = l->next;
		l->next = (*a);
		(*a)->next = NULL;
		(*a) = tmp;
		create_list_oper(operations, a, b, "ra");
	}
}

void	rr(t_ps **a, t_ps **b, t_operations **operations)
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
	}
	if ((*a) && (*a)->next)
	{
		l = (*a);
		tmp = (*a)->next;
		while (l->next)
			l = l->next;
		l->next = (*a);
		(*a)->next = NULL;
		(*a) = tmp;
	}
	create_list_oper(operations, a, b, "rr");
}

void	rra(t_ps **a, t_ps **b, t_operations **operations)
{
	t_ps *l;
	t_ps *tmp;

	if ((*a) && (*a)->next)
	{
		l = (*a);
		while (l->next->next)
			l = l->next;
		tmp = l->next;
		l->next = NULL;
		tmp->next = (*a);
		(*a) = tmp;
		create_list_oper(operations, a, b, "rra");
	}
}
