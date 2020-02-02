/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_usual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    if_we_have_up_to_five_numbers(t_ps **a, t_ps **b, t_operations **operations)
{
    int max;

    max = find_max(a);
    if (max <= 5)
    {
        if (!check_order_in_stack(a))
        {
            if (1 == max)
            {
                free_list(a, 0);
                exit(0);
            }
            if (2 == max)
                sa(a, b, operations);
            else if (3 == max)
                sort_of_three_numbers_by_ascending(a, b, operations, 1);
            else if (4 == max)
                sort_of_four_numbers_by_ascending(a, b, operations);
            else if (5 == max)
                sort_of_five_numbers_by_ascending(a, b, operations);
        }
        the_end_of_sorting(a, operations);
    }
}

void sort_of_two_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*b);
    tmp_next = (*b)->next;
    if (tmp->num > tmp_next->num)
        sb(b, a, operations);
    pa(b, a, operations);
    ra(a, b, operations);
    pa(b, a, operations);
    ra(a, b, operations);
}

void    sort_of_three_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations, int flag)
{
    t_ps *n;
    t_ps *n1;
    t_ps *n2;
    t_ps *n3;

    n = (1 == flag) ? (*a) : (*b);
    n1 = n;
    n2 = n->next;
    n3 = n2->next;
    if ((n1->num < n2->num) && (n1->num < n3->num) && (n2->num > n3->num))
    {
        sa(a, b, operations);
        ra(a, b, operations);
    }
    else if ((n1->num < n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
        rra(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num < n3->num) && (n2->num < n3->num))
        sa(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
    {
        sa(a, b, operations);
        rra(a, b, operations);
    }
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num < n3->num))
        ra(a, b, operations);
}

void sort_of_four_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps    *tmp;
    t_ps    *tmp_next;
    int     i;

    i = 0;
    tmp = (*a);
    while (i++ < 4)
    {
        tmp_next = tmp->next;
        if (tmp->index > 2)
            pb(a, b, operations);
        else
            ra(a, b, operations);
        tmp = tmp_next;
    }
    tmp = (*a);
    tmp_next = tmp->next;
    if (tmp->index > tmp_next->index)
        ra(a, b, operations);
    sort_of_two_numbers_by_ascending(a, b, operations);
}

void sort_of_five_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps    *tmp;
    t_ps    *tmp_next;
    int     i;

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
    sort_of_three_numbers_by_ascending(a, b, operations, 1);
    sort_of_two_numbers_by_ascending(a, b, operations);
}
