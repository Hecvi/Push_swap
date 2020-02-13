/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 17:04:28 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_of_five_num(t_ps **a, t_ps **b, t_operations **operations)
{
	t_ps	*tmp;
	t_ps	*tmp_next;
	int		i;

	i = 0;
	tmp = (*a);
	while (i++ < 5)
	{
		tmp_next = tmp->next;
		if (tmp->index > 3)
			pb(a, b, operations);
		else
			ra(a, b, operations);
		tmp = tmp_next;
	}
	sort_of_three_num_in_a(a, b, operations);
	sort_of_two_num(a, b, operations);
}

void	rrr(t_ps **a, t_ps **b, t_operations **operations)
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
	}
	if ((*b) && (*b)->next)
	{
		l = (*b);
		while (l->next->next)
			l = l->next;
		tmp = l->next;
		l->next = NULL;
		tmp->next = (*b);
		(*b) = tmp;
	}
	create_list_oper(operations, a, b, "rrr");
}

void	the_end_of_sorting(t_ps **a, t_operations **operations, char **av)
{
	int flag;

	flag = 0;
	combine(operations, "sa", "sb", "ss");
	combine(operations, "ra", "rb", "rr");
	combine(operations, "rra", "rrb", "rrr");
	combine_pb_pa(operations, "pb", "pa", flag);
	print_operations(operations, av);
	free_list_operations(operations);
	free_list(a, 0);
	exit(0);
}

void	print_operations(t_operations **operations, char **av)
{
	t_operations	*tmp;

	tmp = (*operations);
	if ('-' == av[1][0] && 'w' == av[1][1] && !av[1][2])
		write_to_file(operations);
	else
		while (tmp)
		{
			write(1, tmp->str, ft_strlen(tmp->str));
			write(1, "\n", 1);
			tmp = tmp->next;
		}
}

int		write_to_file(t_operations **operations)
{
	FILE			*s;
	t_operations	*tmp;

	tmp = (*operations);
	s = fopen("Operations.txt", "w");
	if (NULL == s)
		return (write(1, "Error: Cannot create file\n", 26));
	while (tmp)
	{
		fprintf(s, "%s\n", tmp->str);
		tmp = tmp->next;
	}
	return (0);
}
