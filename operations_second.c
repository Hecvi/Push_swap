/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sb(t_ps **b)
{
    t_ps *l;

    if ((*b) && (*b)->next)
    {
        l = (*b)->next;
        (*b)->next = l->next;
        l->next = (*b);
        (*b) = l;
    }
}

void    pb(t_ps **b, t_ps **a)
{
    t_ps *l;

    if (*a)
    {
        l = (*a)->next;
        (*a)->next = (*b);
        (*b) = (*a);
        (*a) = l;
    }
}

void    rb(t_ps **b)
{
    t_ps *l;
    t_ps *tmp;

    if (*b)
    {
        if (!((*b)->next))
            return ;
        l = (*b);
        tmp = (*b)->next;
        while(l->next)
            l = l->next;
        l->next = (*b);
        (*b)->next = NULL;
        (*b) = tmp;
    }
}

void    rrb(t_ps **b)
{
    t_ps *l;
    t_ps *tmp;

    if (*b)
    {
        if (!((*b)->next))
            return ;
        l = (*b);
        while(l->next->next)
            l = l->next;
        tmp = l->next;
        l->next = NULL;
        tmp->next = (*b);
        (*b) = tmp;
    }
}

void    ss(t_ps **a, t_ps **b)
{
    sa(a);
    sb(b);
}