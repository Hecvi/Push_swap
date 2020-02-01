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
    t_operations *operations;

    n = 3;
    operations = NULL;
    sort_first_part(a, b, &operations, (find_max(a) / 2));
//    while (!(check_order_in_stack(a)) и все элементы слева )
 //   {
//        printf("number is %d\n", mid);
         while (find_max(b) > 3)
         {
             sort_another_parts(a, b, &operations, n);
             n++;
         }
         if (3 == find_max(b))
         {
             sort_of_three_numbers_by_ascending(a, b, &operations, 0);
             while (*b)
             {
                 pa(b, a, &operations);
                 ra(a, b, &operations);
                 (*b)->sort = 1;
             }
        }
         else if ((*b) && (*b)->next)
         {
             if ((*b)->index > (*b)->next->index)
                 sb(b, a, &operations);
             while (*b)
             {
                 pa(b, a, &operations);
                 ra(a, b, &operations);
                 (*b)->sort = 1;
             }
         }
         else if ((*b))
         {
             pa(b, a, &operations);
             ra(a, b, &operations);
             (*b)->sort = 1;
         }

else
    return ;


  //  }





    /*   sort_of_three_numbers_by_ascending(a, b, &operations, 1);
  while (operations)
   {
       printf("%s\n", (operations->str));
       operations = operations->next;
   }
    printf("%d\n", check_order_in_stack(a))*/
}

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
            pa(b, a, operations);
            ra(a, b, operations);
            tmp_b->sort = 1;
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
