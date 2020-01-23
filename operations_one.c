/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_ps **a)
{
    t_ps *l;

    if ((*a) && (*a)->next)
    {
        l = (*a)->next;
        (*a)->next = l->next;
        l->next = (*a);
        (*a) = l;
    }
}

void    pa(t_ps **a, t_ps **b)
{
    t_ps *l;

    if (*b)
    {
        l = (*b)->next;
        (*b)->next = (*a);
        (*a) = (*b);
        (*b) = l;
    }
}

void    ra(t_ps **a)
{
    t_ps *l;
    t_ps *tmp;

    if (*a)
    {
        if (!((*a)->next))
            return ;
        l = (*a);
        tmp = (*a)->next;
        while(l->next)
            l = l->next;
        l->next = (*a);
        (*a)->next = NULL;
        (*a) = tmp;
    }
}

void    rr(t_ps **a, t_ps **b)
{
    ra(a);
    rb(b);
}

void    rra(t_ps **a)
{
    t_ps *l;
    t_ps *tmp;

    if (*a)
    {
        if (!((*a)->next))
            return ;
        l = (*a);
        while(l->next->next)
            l = l->next;
        tmp = l->next;
        l->next = NULL;
        tmp->next = (*a);
        (*a) = tmp;
    }
}