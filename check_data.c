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

int     func_atoi(char *str, int sign, int *indicator)
{
    int						i;
    unsigned long long int	number;

    i = 0;
    number = 0;
    while (check_char(str[i], 2))
        i++;
    sign = str[i] == '-' ? -1 : 1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        number = number * 10 + (str[i] - '0');
        if ((number > 2147483647 && 1 == sign) || (number > 2147483648 && -1 == sign))
        {
            *indicator = -1;
            return (0);
        }
        i++;
    }
    return ((int)number * sign);
}

int     check_string_of_array(char *s, int *indicator)
{
    int     i;
    size_t  j;
    int     sign;
    int     number;

    i = -1;
    sign = 1;
    if ('-' == s[0] || '+' == s[0])
    {
        sign = -1;
        i++;
    }
    j = ft_strlen(s);
    if ((j > 10 && 1 == sign) || (j > 11 && -1 == sign))
    {
        *indicator = -1;
        return (0);
    }
    while (s[++i])
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (0);
    number = func_atoi(s, sign, indicator);
    return (number);
}

int    check_number(t_ps **a, int number)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp)
    {
        if ((tmp)->num == number)
            return (0);
        (tmp) = (tmp)->next;
    }
    return (1);
}

void    second_check(char **av, t_ps **a, int i, int j)
{
    char **s;
    int number;
    int *indicator;

    indicator = &i;
    while (av[++i])
    {
        j = 0;
        if (!(s = ft_split(av[i], a)))
            continue ;
        while (s[j])
        {
            number = check_string_of_array(s[j], indicator);
            if (-1 == *indicator)
            {
                free_char(s, c_w(av[i]), 0);
                free_list(a, 0);
                write(1, "Incorrect data\n", 15);
                exit(1);
            }
            create_list(a, number, av[i]); //вставить функцию перед этой???
            j++;
        }
        free_char(s, c_w(av[i]), 0);
    }
}