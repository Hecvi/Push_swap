/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    general_sort(t_ps **a, t_ps **b)
{
    int max;
    int one;
    int two;
    t_ps *tmp;
    t_ps *tmp_next;
    t_operations *operations;

    one = 0;
//    two = 0;
    tmp = (*a);
    operations = NULL;
    max = find_max(a);
    if (0 == (max % 3))
    {
        one = max - 2 * max / 3;
//        two = 2 * max / 3;
    }
    while (tmp)
    {
        tmp_next = tmp->next;
        if (tmp->index <= one && 0 == (*a)->flag)
        {
            if (NULL == (*b))
            {
                (*b) = (*a);
                (*a) = (*a)->next;
                (*b)->next = NULL;
            }
            else
                pb(a, b, &operations);
        }
        else if (0 == (*a)->flag)
        {
            (*a)->flag = 1;
            ra(a, &operations);
        }
        tmp = tmp_next;
    }
}

void    create_list_operations(t_operations **operations, t_ps **a, t_ps **b, char *s)
{
    t_operations *step;
    t_operations *tmp;

    if (NULL == (*operations))
    {
        if (!((*operations) = (t_operations *)malloc(sizeof(t_operations))))
        {
            free_list(a, 1);
            exit(1);
        }
        (*operations)->str = s;
        (*operations)->next = NULL;
        return ;
    }
    tmp = (*operations);
    while (tmp->next)
        tmp = tmp->next;
    if (!(step = (t_operations *)malloc(sizeof(t_operations))))
    {
        free_list(a, 0);
        free_list(b, 1);
        free_list_operations(operations);
    }
    step->str = s;
    step->next = NULL;
    tmp->next = step;
}

