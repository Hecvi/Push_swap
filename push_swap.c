/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rrr(t_ps **a, t_ps **b, t_operations **operations)
{
    if ((*a) && (*a)->next && (*b) && (*b)->next)
    {
        rra(a, b, operations);
        rrb(b, a, operations);
        create_list_oper(operations, a, b, "rrr");
    }
}

void    print_operations(t_operations **operations)
{
    int count; //
    t_operations *tmp;

    count = 0;
    tmp = (*operations);
    while (tmp)
    {
        count++; //
        write(1, tmp->str, ft_strlen(tmp->str));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    printf("%d", count); //
}

int     main(int ac, char **av)
{
    int     i;
    int     j;
    t_ps    *a;
    t_ps    *b;
    int     count;

    i = 0;
    j = 0;
    a = NULL;
    b = NULL;
    count = 1;
    first_check(av, ac);
    second_check(av, &a, i, j);
    sort_by_index(&a, count);
    general_sort(&a, &b);
    return (0);
}

