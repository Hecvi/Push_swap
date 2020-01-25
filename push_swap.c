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

char    *rrr(t_ps **a, t_ps **b)
{
    if ((*a) && (*a)->next && (*b) && (*b)->next)
    {
        rra(a);
        rrb(b);
        return ("rrr");
    }
    return (NULL);
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
    int count;
    int b;


    i = 0;
    j = 0;
    a = NULL;
    count = 1;
    first_check(av);
    second_check(av, &a, i, j);
    sort_by_index(&a, count);
    b = check_order_in_stack(&a);
    printf("%d\n", b);
//    while (a)
//    {
//        printf("%d\n", (a->flag));
//        a = a->next;
//    }
    return (0);
}

