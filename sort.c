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

void    sort_first_part(t_ps **a, t_ps **b, t_operations **operations, int mid)
{
    t_ps *tmp_a;
    t_ps *tmp_next;

    tmp_a = (*a);
    while (tmp_a)
    {
        tmp_next = tmp_a->next;
        if (tmp_a->index <= mid)
        {
            if (NULL == (*b))
            {
                (*b) = (*a);
                (*b)->block = 2;
                (*a) = (*a)->next;
                (*b)->next = NULL;
            }
            else
            {
                tmp_a->block = 2;
                pb(a, b, operations);
            }
        }
        else if (0 == (*a)->block)
        {
            (*a)->block = 1;
            ra(a, b, operations);
        }
        tmp_a = tmp_next;
    }
}

void    general_sort(t_ps **a, t_ps **b)
{
    int n;
    t_operations *operations;

    n = 3;
    operations = NULL;
    if_we_have_up_to_five_numbers(a, b, &operations);
    sort_first_part(a, b, &operations, (find_max(a) / 2));
    while (!check_order_in_stack(a) && (*b))
    {
        if (*b)
        {
            sort_another_parts(a, b, &operations, n);
        }

        while (find_max(b) > 3) {
            sort_another_parts(a, b, &operations, n);
            n++;
        }
        if (3 == find_max(b)) {
            sort_of_three_numbers_by_ascending(a, b, &operations, 0);
            while (*b) {
                (*b)->sort = 1;
                pa(b, a, &operations);
                ra(a, b, &operations);
            }
        } else if ((*b) && (*b)->next) {
            if ((*b)->next->index > (*b)->index)
                sb(b, a, &operations);
            while (*b) {
                (*b)->sort = 1;
                pa(b, a, &operations);
                ra(a, b, &operations);
            }
        } else if (*b) {
            (*b)->sort = 1;
            pa(b, a, &operations);
            ra(a, b, &operations);
        }
        if (find_max(a) == 2) {
            if ((*a)->next->index > (*a)->index)
                sa(a, b, &operations);
            (*a)->sort = 1;
            ra(a, b, &operations);
            (*a)->sort = 1;
            ra(a, b, &operations);
        } else if (find_max(a) == 1) {
            (*a)->sort = 1;
            ra(a, b, &operations);
        }
    }
    general_sort_continue(a, b, &operations);
}

void    general_sort_continue(t_ps **a, t_operations **operations)
{
    ability_to_combine(operations, "sa", "sb", "ss");
    ability_to_combine(operations, "ra", "rb", "rr");
    ability_to_combine(operations, "rra", "rrb", "rrr");
    print_operations(operations);
    free_list_operations(operations);
    free_list(a, 0);
    exit (0);
}

void    sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int n)
{
    int mid;
    int min;
    t_ps *tmp_b;
    t_ps *tmp_next;

    min = find_min(b);
    mid = find_max(b) / 2;
    tmp_b = (*b);
    while (tmp_b && (*b)->block != n + 1)
    {
        tmp_next = tmp_b->next;
        if (tmp_b->index == min && (*b)->block != n + 1)
        {
            tmp_b->sort = 1;
            pa(b, a, operations);
            ra(a, b, operations);
            min++;
        }
        else if (tmp_b->index > mid)
        {
            tmp_b->block = n;
            pa(b, a, operations);
        }
        else if ((*b)->block != n)
        {
            (*b)->block = n + 1;
            rb(b, a, operations);
        }
        tmp_b = tmp_next;
    }
}

