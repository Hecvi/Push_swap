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

char    *sa(t_ps **a)
{
    t_ps *l;

    if ((*a) && (*a)->next)
    {
        l = (*a)->next;
        (*a)->next = l->next;
        l->next = (*a);
        (*a) = l;
    }
    return ("sa");
}

char   *pa(t_ps **a, t_ps **b)
{
    t_ps *l;

    if (*b)
    {
        l = (*b)->next;
        (*b)->next = (*a);
        (*a) = (*b);
        (*b) = l;
    }
    return ("pa");
}

char    *ra(t_ps **a)
{
    t_ps *l;
    t_ps *tmp;

    if (*a)
    {
        if (!((*a)->next))
            return (NULL);
        l = (*a);
        tmp = (*a)->next;
        while(l->next)
            l = l->next;
        l->next = (*a);
        (*a)->next = NULL;
        (*a) = tmp;
    }
    return ("ra");
}

char    *rr(t_ps **a, t_ps **b)
{
    ra(a);
    rb(b);
    return ("rr");
}

char    *rra(t_ps **a)
{
    t_ps *l;
    t_ps *tmp;

    if (*a)
    {
        if (!((*a)->next))
            return (NULL);
        l = (*a);
        while(l->next->next)
            l = l->next;
        tmp = l->next;
        l->next = NULL;
        tmp->next = (*a);
        (*a) = tmp;
    }
    return ("rra");
}