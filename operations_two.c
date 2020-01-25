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

char    *sb(t_ps **b)
{
    t_ps *l;

    if ((*b) && (*b)->next)
    {
        l = (*b)->next;
        (*b)->next = l->next;
        l->next = (*b);
        (*b) = l;
        return ("sb");
    }
    return (NULL);
}

char    *pb(t_ps **b, t_ps **a)
{
    t_ps *l;

    if (*a)
    {
        l = (*a)->next;
        (*a)->next = (*b);
        (*b) = (*a);
        (*a) = l;
        return ("pb");
    }
    return (NULL);
}

char    *rb(t_ps **b)
{
    t_ps *l;
    t_ps *tmp;

    if ((*b) && (*b)->next)
    {
        l = (*b);
        tmp = (*b)->next;
        while (l->next)
            l = l->next;
        l->next = (*b);
        (*b)->next = NULL;
        (*b) = tmp;
        return ("rb");
    }
    return (NULL);
}

char    *rrb(t_ps **b)
{
    t_ps *l;
    t_ps *tmp;

    if (*b)
    {
        if (!((*b)->next))
            return (NULL);
        l = (*b);
        while(l->next->next)
            l = l->next;
        tmp = l->next;
        l->next = NULL;
        tmp->next = (*b);
        (*b) = tmp;
    }
    return ("rrb");
}

char    *ss(t_ps **a, t_ps **b)
{
    if ((*a) && (*a)->next && (*b) && (*b)->next)
    {
        sa(a);
        sb(b);
        return ("ss");
    }
    return (NULL);
}