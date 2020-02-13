/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 17:07:51 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	int		j;
	t_ps	*a;
	t_ps	*b;
	int		count;

	i = 0;
	j = 0;
	a = NULL;
	b = NULL;
	count = 1;
	first_check(av, ac);
	second_check(av, &a, i, j);
	sort_by_index(&a, count);
	general_sort_one(&a, &b, av);
	return (0);
}
