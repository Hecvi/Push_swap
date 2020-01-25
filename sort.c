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

int    find_max(t_ps **a)
{
    t_ps *tmp;
    t_ps *max;
    int maximum;

    tmp = (*a);
    maximum = (*a)->num;
    while (tmp && tmp->flag == (*a)->flag)
    {
        if (tmp->num > maximum)
        {
            maximum = tmp->num;
            max = tmp;
        }
        tmp = tmp->next;
    }
    return (max->index);
}

int     check_order_in_stack(t_ps **a)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp)
    {
        if (tmp->next)
            if (tmp->index > tmp->next->index)
                return (0);
        tmp = tmp->next;
    }
    return (1);
}

