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
    int mid;
    int n;
    t_operations *operations;

    operations = NULL;
    max = find_max(a);
    mid = max / 2;
    sort_first_part(a, b, &operations, mid, n);
//    while (!(check_order_in_stack(a)) и все элементы слева )
 //   {
        mid = find_max(b) / 2;
//        printf("number is %d\n", mid);
         while (find_max(b) > 3)
            sort_another_parts(a, b, &operations, mid, n);




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

void    sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int mid, int n)
{
    t_ps *tmp_b;
    t_ps *tmp_next;

    tmp_b = (*b);
    while (tmp_b)
    {
        tmp_next = tmp_b->next;
        if (tmp_b->index > mid)
        {
            tmp_b->block *= 10; //переменная
            pa(b, a, operations);
        }
        else if (2 == (*b)->block)
        {
            (*b)->block = 1;
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
