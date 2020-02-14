/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 18:31:43 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	general_sort_one(t_ps **a, t_ps **b, char **av)
{
	int				count;
	int				center;
	int				numbers;
	t_operations	*operations;

	count = 0;
	operations = NULL;
	numbers = cardinality(a);
	center = find_mid(a);
	five_num(a, b, &operations, av);
	if (check_order_in_stack(a))
		the_end_of_sorting(a, &operations, av);
	while (++count <= (numbers / 2))
		sort_first_part(a, b, &operations, center);
	count = 0;
	if (!check_large_elem(a, center))
		while (++count <= (numbers / 2 + 1) && !check_large_elem(a, center))
			sort_first_part(a, b, &operations, center);
	gen_sort_two(a, b, &operations, av);
}

void	gen_sort_two(t_ps **a, t_ps **b, t_operations **operations, char **av)
{
	int		n;
	t_ps	*tmp;

	n = 1;
	tmp = (*a);
	while (tmp)
	{
		tmp->block = 1;
		tmp = tmp->next;
	}
	while (!check_order_in_stack(a) || (*b))
	{
		while (*b)
		{
			while (cardinality(b) > 2)
				sort_another_parts(a, b, operations, ++n);
			check_sort_stack_b_and_a(a, b, operations);
			if ((*a)->block != 1 && !check_order_in_stack(a))
				transfer_from_a_to_b(a, b, operations);
		}
		general_sort_three(a, b, operations);
	}
	the_end_of_sorting(a, operations, av);
}

void	general_sort_three(t_ps **a, t_ps **b, t_operations **operations)
{
	int count;
	int center;
	int numbers;

	if (!check_order_in_stack(a) && (*a)->block)
	{
		count = 0;
		numbers = cardinality(a);
		center = find_mid(a);
		zeroing_the_blocks(a);
		while (++count <= (numbers / 2 + 1))
			sort_first_part(a, b, operations, center);
		count = 0;
		if (!check_large_elem(a, center))
			while (++count <= (numbers / 2) && !check_large_elem(a, center))
				sort_first_part(a, b, operations, center);
		flipping_to_the_top(a, b, operations);
	}
}

void	sort_first_part(t_ps **a, t_ps **b, t_operations **operations, int mid)
{
	t_ps *tmp_a;

	tmp_a = (*a);
	if (tmp_a && tmp_a->sort != 1)
	{
		if (tmp_a->index <= mid)
			pb(a, b, operations);
		else if (0 == (*a)->block)
		{
			(*a)->block = 1;
			ra(a, b, operations);
		}
	}
}

void	sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int n)
{
	int		mid;
	int		min;
	t_ps	*tmp_b;
	t_ps	*tmp_next;

	min = find_min(b);
	mid = find_mid(b);
	tmp_b = (*b);
	while (tmp_b && tmp_b->block != n + 10)
	{
		tmp_next = tmp_b->next;
		if (tmp_b->index == min && fuc_norm(a, b, operations, tmp_b))
			min++;
		else if (tmp_b->index > mid)
		{
			tmp_b->block = n;
			pa(b, a, operations);
		}
		else if (tmp_b->block != n)
		{
			(tmp_b)->block = n + 10;
			rb(b, a, operations);
		}
		tmp_b = tmp_next;
	}
}
