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
        create_list_operations(operations, a, b, "rrr");
    }
}

int     func_atoi(char *str, int sign, int *indicator)
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

#include <stdio.h>

int     main(int ac, char **av)
{
    int i;
    int j;
    t_ps  *a;
    t_ps *b;
    int count;
//    int b;


    i = 0;
    j = 0;
    a = NULL;
    b = NULL;
    count = 1;
    first_check(av, ac);
    second_check(av, &a, i, j);
    sort_by_index(&a, count);
//    b = check_order_in_stack(&a);
//    printf("%d\n", b);
    general_sort(&a, &b);

    printf("stack A\n");
    while (a)
    {
        printf("%d\n", (a->index));
        a = a->next;
    }
    printf("\nstack B\n");
    while (b)
    {
        printf("%d\n", (b->index));
        b = b->next;
    }
    //free operations and lists

    return (0);
}

