/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/08 16:53:20 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_of_five_num(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps	*tmp;
    t_ps	*tmp_next;
    int		i;

    i = 0;
    tmp = (*a);
    while (i++ < 5)
    {
        tmp_next = tmp->next;
        if (tmp->index > 3)
            pb(a, b, operations);
        else
            ra(a, b, operations);
        tmp = tmp_next;
    }
    sort_of_three_num_in_a(a, b, operations);
    sort_of_two_num(a, b, operations);
}

void	rrr(t_ps **a, t_ps **b, t_operations **operations)
{
    if ((*a) && (*a)->next && (*b) && (*b)->next)
    {
        rra(a, b, operations);
        rrb(b, a, operations);
        create_list_oper(operations, a, b, "rrr");
    }
}

void	the_end_of_sorting(t_ps **a, t_operations **operations, char **av)
{
    t_ps *tmp;
    combine(operations, "sa", "sb", "ss");
    combine(operations, "ra", "rb", "rr");
    combine(operations, "rra", "rrb", "rrr");
    combine_pb_pa(operations, "pb", "pa");
    tmp = (*a);
    while (tmp)
    {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
    tmp = (*a);
    while (tmp)
    {
        printf("%d ", tmp->index);
        tmp = tmp->next;
    }
    print_operations(operations, av);
    free_list_operations(operations);
    free_list(a, 0);
    exit(0);
}

void	print_operations(t_operations **operations, char **av)
{
    t_operations	*tmp;

    tmp = (*operations);
    if ('-' == av[1][0] && 'w' == av[1][1] && !av[1][2])
        write_to_file(operations);
    else
        while (tmp)
        {
            write(1, tmp->str, ft_strlen(tmp->str));
            write(1, "\n", 1);
            tmp = tmp->next;
        }
}

int		write_to_file(t_operations **operations)
{
    FILE			*s;
    t_operations	*tmp;

    tmp = (*operations);
    s = fopen("Operations.txt", "w");
    if (NULL == s)
        return (write(1, "Cannot create file\n", 19));
    while (tmp)
    {
        fprintf(s, "%s\n", tmp->str);
        tmp = tmp->next;
    }
    return (0);
}

void	combine_pb_pa(t_operations **operations, char *str1, char *str2)
{
    int flag;
    t_operations *tmp;
    t_operations *tmp_next;

    tmp = (*operations);
    if (tmp && tmp->next)
        tmp_next = tmp->next;
    else
        return ;
    while (tmp)
    {
        flag = 0;
        if (tmp_next->next && compare_tmp(str1, str2, tmp))
            {
                flag = 1;
                tmp->next = tmp_next->next->next;
                free(tmp_next->next);
                tmp_next->next = NULL;
                free(tmp_next);
                tmp_next = NULL;
            }
        if (0 == flag)
            tmp = tmp->next;
        if (tmp && tmp->next)
            tmp_next = tmp->next;
    }
}

int     compare_tmp(char *str1, char *str2, t_operations *tmp)
{
    t_operations *tmp_next;

    if (tmp && tmp->next)
        tmp_next = tmp->next;
    else
        return (0);
    if (tmp_next->next)
        if ((!ft_strcmp(tmp->next->str, str1) &&
             !ft_strcmp(tmp_next->next->str, str2)) ||
            (!ft_strcmp(tmp->next->str, str2) &&
             !ft_strcmp(tmp_next->next->str, str1)))
        return (1);
    return (0);
}


