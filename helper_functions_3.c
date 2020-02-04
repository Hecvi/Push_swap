/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_elements_in_b(t_ps **stack, int mid)
{
    int count;
    t_ps *tmp;

    count = 0;
    tmp = (*stack);
    while (tmp && tmp->block == (*stack)->block && tmp->index <= mid)
    {
        count++;
        tmp = tmp->next;
    }
    if (count == mid)
        return (1);
    return (0);
}
