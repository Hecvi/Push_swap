/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 16:57:40 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		func_atoi(char *str, int sign, int *indicator)
{
	int						i;
	unsigned long long int	number;

	i = 0;
	number = 0;
	while (check_char(str[i], 2))
		i++;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		number = number * 10 + (str[i] - '0');
		if ((number > MAX && 1 == sign) || (number > MIN && -1 == sign))
		{
			*indicator = -1;
			return (0);
		}
		i++;
	}
	return ((int)number * sign);
}

void	zeroing_the_blocks(t_ps **a)
{
	t_ps *tmp;

	tmp = (*a);
	while (tmp)
	{
		tmp->block = 0;
		tmp = tmp->next;
	}
}

void	flipping_to_the_top(t_ps **a, t_ps **b, t_operations **operations)
{
	int		min;
	t_ps	*tmp;
	t_ps	*tmp_next;

	tmp = (*a);
	min = find_min(b);
	while (tmp && tmp->sort == 1)
		tmp = tmp->next;
	while (tmp && tmp->sort != 1 && tmp != (*a))
	{
		tmp_next = tmp;
		if ((*b)->index != min && (*b))
			rrr(a, b, operations);
		else
			rra(a, b, operations);
		tmp = tmp_next;
	}
}

void	combine(t_operations **operations, char *str1, char *str2, char *str3)
{
	t_operations	*tmp;
	t_operations	*tmp_next;

	tmp = (*operations);
	if (tmp && tmp->next)
		tmp_next = tmp->next;
	else
		return ;
	while (tmp)
	{
		if (tmp_next)
			if ((!ft_strcmp(tmp->str, str1) && !ft_strcmp(tmp_next->str, str2))
					|| (!ft_strcmp(tmp->str, str2) &&
						!ft_strcmp(tmp_next->str, str1)))
			{
				tmp->str = str3;
				tmp->next = tmp_next->next;
				free(tmp_next);
				tmp_next = NULL;
			}
		tmp = tmp->next;
		if (tmp && tmp->next)
			tmp_next = tmp->next;
	}
}

int		fuc_norm(t_ps **a, t_ps **b, t_operations **operations, t_ps *tmp)
{
	(tmp)->sort = 1;
	pa(b, a, operations);
	ra(a, b, operations);
	return (1);
}
