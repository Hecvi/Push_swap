/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     check_char(char c, int flag)
{
    if (1 == flag && ((c >= '0' && c <= '9') || '-' == c || '+' == c ||
    '\n' == c || '\t' == c || '\v' == c || '\f' == c || '\r' == c || ' ' == c))
        return (1);
    else if (2 == flag && c != '\0' && ('\n' == c || '\t' == c || '\v' == c ||
    '\f' == c || '\r' == c || ' ' == c))
        return (2);
    else if (3 == flag && c != '\0' && c != '\n' && c != '\t' && c != '\v' &&
    c != '\f' && c != '\r' && c != ' ')
        return (3);
    return (0);
}

void     first_check(char **av)
{
    int i;
    int j;

    i = 0;
    if (!av)
    {
        write(1, "Add the arguments\n", 18);
        exit(1);
    }
    while (av[++i])
    {
        j = 0;
        while (av[i][j])
        {
            if (check_char(av[i][j], 1))
                j++;
            else
            {
                write(1, "Incorrect data\n", 15);
                exit(1);
            }
        }
    }
}

int     invalid_data(void)
{
    free_char(s, c_w(av[i]), 0);
    free_list(a, 0);
    write(1, "Incorrect data\n", 15);
    exit(1);
}

int     check_string_of_array(char *s)
{
    int     i;
    size_t  j;
    int     sign;
    int     number;
    int     *indicator;

    i = -1;
    sign = 1;
    indicator = &sign;
    if ('-' == s[0] || '+' == s[0])
    {
        sign = -1;
        i++;
    }
    j = ft_strlen(s);
    if ((j > 10 && 1 == sign) || (j > 11 && -1 == sign))
        return (invalid_data());
    while (s[++i])
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (invalid_data());
    number = func_atoi(s, sign, indicator);
    if (0 == *indicator)
        return (invalid_data());
    return (number);
}

void     second_check(char **av, t_ps **a)
{
    int i;
    int j;
    char **s;
    int number;

    i = 0;
    while (av[++i])
    {
        j = 0;
        if (!(s = ft_split(av[i])))
            continue ;
        while (s[j])
        {
            number = check_string_of_array(s[j]);
            if (!(number))
            {
                free_char(s, c_w(av[i]), 0);
                free_list(a, 0);
                write(1, "Incorrect data\n", 15);
                exit(1);
            }
            create_list(a, number);
            j++;
        }
    }
}