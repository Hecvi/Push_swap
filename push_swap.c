/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_list(t_ps **a, int flag)
{
    t_ps *tmp;

    tmp = (*a);
    while (*a)
    {
        (*a) = (*a)->next;
        free(tmp);
        tmp = (*a);
    }
    if (1 == flag)
        write(1, "Memory allocation error\n", 24);
}

void    create_list(t_ps **a, int i, char *s)
{
    t_ps *b;
    t_ps *tmp;

    if (NULL == (*a))
    {
        if (!((*a) = (t_ps *)malloc(sizeof(t_ps))))
        {
            write(1, "Memory allocation error\n", 24);
            free_char(&s, c_w(s), 0);
            exit(1);
        }
        (*a)->num = i;
        (*a)->next = NULL;
        return ;
    }
    tmp = (*a);
    while (tmp->next)
        tmp = tmp->next;
    if (!(b = (t_ps *)malloc(sizeof(t_ps))))
    {
        free_char(&s, c_w(s), 0);
        return (free_list(a, 1));  ///только кусок тут и все
    }
    b->num = i;
    b->next = NULL;
    tmp->next = b;
}



void    rrr(t_ps **a, t_ps **b)
{
    rra(a);
    rrb(b);
}

#include <stdio.h>

int     main(int ac, char **av)
{
    int i;
    int j;
    char **s;
    t_ps  *a;
    t_ps  *b;

    i = 0;
    j = 0;
    a = NULL;
    first_check(av);
    second_check(av, &a, i, j);

    while (a)
    {
        printf("%d\n", (a->num));
        a = a->next;
    }
    return (0);
}

