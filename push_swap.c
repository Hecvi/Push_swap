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

void    print_operations(t_operations **operations)
{
    int count; //
    t_operations *tmp;

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

void    ability_to_combine(t_operations **operations, char *str1, char *str2, char *str3)
{
    t_operations *tmp;
    t_operations *tmp_next;

    tmp = (*operations);
    if (tmp && tmp->next)
        tmp_next = tmp->next;
    else
        return ;
    while (tmp)
    {
        if (tmp_next)
            if ((!ft_strcmp(tmp->str, str1) && !ft_strcmp(tmp_next->str, str2)) ||
                (!ft_strcmp(tmp->str, str2) && !ft_strcmp(tmp_next->str, str1)))
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
    return (0);
}

