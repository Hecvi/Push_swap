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
    int n;
    int count;
    int numbers;
    t_operations *operations;

    n = 1;
    count = 0;
    operations = NULL;
    numbers = cardinality(a);
    if_we_have_up_to_five_num(a, b, &operations);
    if (check_order_in_stack(a))
        the_end_of_sorting(a, &operations);
    while (++count <= (numbers / 2))
        sort_first_part(a, b, &operations, numbers / 2);
    count = 0;
    if (!check_elements_in_b(b, numbers / 2))
        while (++count <= (numbers / 2) && !check_elements_in_b(b, numbers / 2))
            sort_first_part(a, b, &operations, numbers / 2);
        block A cделать единичками
    while (!check_order_in_stack(a) || (*b))
    {
        while (*b)
        {
            while (cardinality(b) > 3)
                sort_another_parts(a, b, &operations, ++n);
            check_sort_stack_b_and_a(a, b, &operations);
            if ((*a)->block != 1 && !check_order_in_stack(a))
                transfer_from_a_to_b(a, b, &operations);
        }
        if (!check_order_in_stack(a) && (*a)->block)
        {
            numbers = cardinality(a);
            zeroing_the_blocks(a);
            count = 0;
            while (++count <= (numbers / 2))
                sort_first_part(a, b, &operations, find_mid(a));
            flipping_to_the_top(a, b, &operations);
        }
    }
    printf("stack A\n");
    while (*a)
    {
        printf("%d\n", (*a)->index);
        (*a) = (*a)->next;
    }
    printf("\nstack B\n");
    while (*b)
    {
        printf("%d\n", (*b)->index);
        (*b) = (*b)->next;
    }
    printf("\n");
    the_end_of_sorting(a, &operations);
}

void    sort_first_part(t_ps **a, t_ps **b, t_operations **operations, int mid)
{
    t_ps *tmp_a;

    tmp_a = (*a);
    if (tmp_a && tmp_a->sort != 1)
    {
        if (tmp_a->index <= mid)
        {
            if (NULL == (*b))
            {
                (*b) = (*a);
                (*a) = (*a)->next;
                (*b)->next = NULL;
            }
            else
                pb(a, b, operations);
        }
        else if (0 == (*a)->block)
        {
            (*a)->block = 1;
            ra(a, b, operations);
        }
    }
}

void    sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int n)
{
    int mid;
    int min;
    t_ps *tmp_b;
    t_ps *tmp_next;

    min = find_min(b);
    mid = find_mid(b);
    tmp_b = (*b);
    while (tmp_b && tmp_b->block != n + 10)
    {
        tmp_next = tmp_b->next;
        if (tmp_b->index == min)
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
        else if (tmp_b->block != n)
        {
            (*b)->block = n + 10;
            rb(b, a, operations);
        }
        tmp_b = tmp_next;
    }
}

void    check_sort_stack_b_and_a(t_ps **a, t_ps **b, t_operations **operations)
{
    if (cardinality(b) >= 1 && cardinality(b) <= 3)
    {
        if (3 == cardinality(b))
            sort_of_three_num_in_b(a, b, operations);
        else if ((*b)->next && ((*b)->next->index < (*b)->index))
            sb(b, a, operations);
        while (*b)
        {
            (*b)->sort = 1;
            pa(b, a, operations);
            ra(a, b, operations);
        }
    }
    help_with_operations_in_a(a, b, operations);
    if (cardinality(a) <= 2 && cardinality(a) >= 1)
    {
        if (2 == cardinality(a))
        {
            if ((*a)->next && ((*a)->next->index < (*a)->index))
                sa(a, b, operations);
            (*a)->sort = 1;
            ra(a, b, operations);
        }
        (*a)->sort = 1;
        ra(a, b, operations);
    }
}

void    help_with_operations_in_a(t_ps **a, t_ps **b, t_operations **operations)
{
    int min;
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    while (tmp->next)
        tmp = tmp->next;
    min = tmp->index;
    tmp = (*a);
    while (tmp && tmp->block == (*a)->block)
    {
        tmp_next = tmp->next;
        if (tmp_next && (min + 1) == tmp_next->index && (min + 2) == tmp->index)
        {
            sa(a, b, operations);
            tmp = (*a);
        }
        if ((min + 1) == tmp->index)
        {
            min++;
            tmp->sort = 1;
            ra(a, b, operations);
            tmp = tmp_next;
        }
        else
            break ;
    }
}
/*
void    help_with_operations_in_b(t_ps **a, t_ps **b, t_operations **operations)
{
    int min;
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    while (tmp->next)
        tmp = tmp->next;
    min = tmp->index;
    if (!(tmp->sort))
        min = 1;
    tmp = (*b);
    while (tmp)
    {
        tmp_next = tmp->next;
        if (tmp_next && min == tmp_next->index && (min + 1) == tmp->index)
        {
            sb(b, a, operations);
            tmp = (*b);
        }
        if (min == tmp->index)
        {
            min++;
            tmp->sort = 1;
            pa(b, a, operations);
            ra(a, b, operations);
            tmp = tmp_next;
        }
        else
            break ;
    }
}
*/
void    transfer_from_a_to_b(t_ps **a, t_ps **b, t_operations **operations)
{
    int block;
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    block = (*a)->block;
    while (tmp && tmp->block == block)
    {
        tmp_next = tmp->next;
        pb(a, b, operations);
        tmp = tmp_next;
    }
}