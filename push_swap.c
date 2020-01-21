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

void    create_list(t_ps **a, int i)
{
    t_ps *b;
    t_ps *tmp;

    if (NULL == (*a))
    {
        if (!((*a) = (t_ps *)malloc(sizeof(t_ps))))
        {
            write(1, "Memory allocation error\n", 24);
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
        return (free_list(a, 1));
    b->num = i;
    b->next = NULL;
    tmp->next = b;
}

int     check_char(char c, int flag)
{
    if (1 == flag && ((c >= '0' && c <= '9') || '-' == c || '+' == c || '\n' == c || '\t' == c || '\v' == c || '\f' == c || '\r' == c || ' ' == c))
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

//       проверить на длину инта с учетом знака и по абсолютному значению
//       проверить что нет ничего лишнего в инте, только минус или плюс или цифры от 0 до 9
//       можем проверять построчно: создали массив строк из строки, определили инты в ней, проверили их и записали
//       в листы если что-то не так, то фришим все листы и выходим из программы
//       если ошибка при выделении памяти в одной строке сплита то мы фришим все массивы сплитов. в конце мы фришим
//       все равно массив сплитов
//      не работает \n тд

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
            *indicator = 0;
            return (0);
        }
        i++;
    }
    return ((int)number * sign);
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
        return (0);
    while (s[++i])
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (0);
    number = func_atoi(s, sign, indicator);
    if (0 == *indicator)
        return (0);
    return (number);
}

int     second_check(char **av, t_ps **a)
{
    int i;
    int j;
    char **s;

    i = 0;
    while (av[++i])
    {
        j = 0;
        if (!(s = ft_split(av[i])))
            continue ;
        while (s[j])
        {
            if (!(check_string_of_array(s[j])))
            {
                free_char(s, c_w(av[i]), 0);
                free_list(a, 0);
                write(1, "Incorrect data\n", 15);
                exit(1);
            }
            create_list(a, check_string_of_array(s[j]));
            j++;
        }
    }
    return (1);
}

#include <stdio.h>

int     main(int ac, char **av)
{
    int i;
    int     j;
    t_ps  *a;

    a = NULL;
    first_check(av);
    second_check(av, &a);
    j = 0;
    i = 4;
    while (j < i)
    {
        printf("%d\n", (a->num));
        a = a->next;
        j++;
    }
    return (0);
}

