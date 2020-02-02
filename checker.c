/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:32 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:34 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    start_read_gnl(t_ps **a, t_ps **b, t_operations **operations)
{
    char *str;

    while (get_next_line(0, &str) > 0)
    {
        if (!ft_strcmp(str, "sa"))
            sa(a, b, operations);
        else if (!ft_strcmp(str, "sb"))
            sb(b, a, operations);
        else if (!ft_strcmp(str, "ss"))
            ss(a, b, operations);
        else if (!ft_strcmp(str, "ra"))
            ra(a, b, operations);
        else if (!ft_strcmp(str, "rb"))
            rb(b, a, operations);
        else if (!ft_strcmp(str, "rr"))
            rr(a, b, operations);
        else if (!ft_strcmp(str, "pa"))
            pa(b, a, operations);
        else if (!ft_strcmp(str, "pb"))
            pb(a, b, operations);
        else
            continue_read_gnl(a, b, operations, str);
    }
}

void    continue_read_gnl(t_ps **a, t_ps **b, t_operations **operations, char *str)
{
    if (!ft_strcmp(str, "rra"))
        rra(a, b, operations);
    else if (!ft_strcmp(str, "rrb"))
        rrb(b, a, operations);
    else if (!ft_strcmp(str, "rrr"))
        rrr(a, b, operations);
    else
    {
        write(1, "Incorrect commands\n", 19);
        free_list_operations(operations);
        free_list(a, 0);
        free_list(b, 0);
        free(str);
        str = NULL;
        exit (1);
    }
    free(str);
    str = NULL;
}

int     main(int ac, char **av)
{
    int i;
    int j;
    t_ps *a;
    t_ps *b;
    t_operations *operations;

    i = 0;
    j = 0;
    a = NULL;
    b = NULL;
    operations = NULL;
    first_check(av, ac);
    second_check(av, &a, i, j);
    start_read_gnl(&a, &b, &operations);
    if (check_order_in_stack(&a) && NULL == b)
        write(1, "OK\n", 3);
    else
    {
        write(1, "KO\n", 3);
        free_list(&b, 0);
    }
    free_list_operations(&operations);
    free_list(&a, 0);
    return (0);
}
