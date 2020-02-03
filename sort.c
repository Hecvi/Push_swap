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
    while (tmp_a && tmp_a->sort != 1)
    {
        tmp_next = tmp_a->next;
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
        tmp_a = tmp_next;
    }
}

void    check_sort_stack_b_and_a(t_ps **a, t_ps **b, t_operations **operations)
{
    if (cardinality(b) >= 1 && cardinality(b) <= 3)
    {
        if (3 == cardinality(b))
            sort_of_three_numbers_by_ascending_in_b(a, b, operations);
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

void    zeroing_the_blocks(t_ps **a)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp)
    {
        tmp->block = 0;
        tmp = tmp->next;
    }
}

void    flipping_to_the_top(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    while (tmp && tmp->sort == 1)
        tmp = tmp->next;
    while (tmp && tmp->sort != 1 && tmp != (*a))
    {
        tmp_next = tmp;
        rra(a, b, operations);
        tmp = tmp_next;
    }
}

int    cardinality(t_ps **stack)
{
    int count;
    t_ps *tmp;
    int block;

    count = 0;
    if (!(*stack))
        return (0);
    tmp = (*stack);
    block = (*stack)->block;
    while (tmp && tmp->block == block)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

void    general_sort(t_ps **a, t_ps **b)
{
    int n;
    int count;
    t_operations *operations;

    n = 1;
    operations = NULL;
    if_we_have_up_to_five_numbers(a, b, &operations);
    sort_first_part(a, b, &operations, (find_max(a) / 2));
    while (!check_order_in_stack(a) && (*b))
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
            zeroing_the_blocks(a);
            sort_first_part(a, b, &operations, find_mid(a));
            flipping_to_the_top(a, b, &operations);
        }
    }
    count = 0;
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

void    the_end_of_sorting(t_ps **a, t_operations **operations)
{
    ability_to_combine(operations, "sa", "sb", "ss");
    ability_to_combine(operations, "ra", "rb", "rr");
    ability_to_combine(operations, "rra", "rrb", "rrr");
    print_operations(operations);
    free_list_operations(operations);
    free_list(a, 0);
    exit (0);
}
int     find_mid(t_ps **stack)
{
    int mid;
    int count;
    t_ps *tmp;
    int block;

    mid = 0;
    count = 0;
    if (!(*stack))
        return (0);
    if ((*stack)->sort)
        return (0);
    tmp = (*stack);
    block = (*stack)->block;
    while (tmp && tmp->block == block && tmp->sort != 1)
    {
        count++;
        mid = mid + tmp->index;
        tmp = tmp->next;
    }
    return (mid / count);
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
    while (tmp_b && tmp_b->block != n + 100)
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
            (*b)->block = n + 100;
            rb(b, a, operations);
        }
        tmp_b = tmp_next;
    }
}