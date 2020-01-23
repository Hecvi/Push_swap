/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_index(t_ps **a)
{
    t_ps *tmp;
    int min;

    min = (*a)->num;
    while (tmp)
    {
        tmp = (*a);
        while (tmp)
        {
            if (tmp->num < min)
                min



        }

    }
}

void    create_list(t_ps **a, int i, char **s, int words)
{
    t_ps *b;
    t_ps *tmp;

    if (NULL == (*a))
    {
        if (!((*a) = (t_ps *)malloc(sizeof(t_ps))))
        {
            write(1, "Memory allocation error\n", 24);
            free_split(s, words, 0);
            exit(1);
        }
        (*a)->num = i;
        (*a)->index = 0;
        (*a)->next = NULL;
        return ;
    }
    tmp = (*a);
    while (tmp->next)
        tmp = tmp->next;
    if (!(b = (t_ps *)malloc(sizeof(t_ps))))
        free_all(s, words, a, 1);
    b->num = i;
    b->index = 0;
    b->next = NULL;
    tmp->next = b;
}