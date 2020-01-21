/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     c_w(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != '\n' && s[i] != '\t' && s[i] != '\v' && s[i] != '\f'
            && s[i] != '\r' && s[i] != ' ' && (' ' == s[i + 1] ||
            '\t' == s[i + 1] || '\n' == s[i + 1] || '\v' == s[i + 1] ||
            '\f' == s[i + 1] || '\r' == s[i + 1] || '\0' == s[i + 1]))
            count++;
        i++;
    }
    return (count);
}

int     c_l(char *s, int i)
{
    int count;

    count = 0;
    while (s[i] != '\n' && s[i] != '\t' && s[i] != '\v' && s[i] != '\f'
           && s[i] != '\r' && s[i] != ' ' && s[i])
    {
        count++;
        i++;
    }
    return (count);
}

int     free_char(char **s, int j)
{
    j--;
    while (j >= 0)
    {
        free(s[j]);
        s[j] = NULL;
        j--;
    }
    free(s);
    s = NULL;
    write(1, "Memory allocation error\n", 24);
    return (1);
}

char    **mas_of_char(char *str, char **s, int i)
{
    int k;
    int j;

    j = 0;
    while (str[i])
    {
        k = 0;
        if (!(s[j] = (char *)malloc(sizeof(char) * (c_l(str, i) + 1))))
            exit(free_char(s, j));
        while (check_char(str[i], 3))
        {
            s[j][k] = str[i];
            i++;
            k++;
        }
        s[j][k] = '\0';
        j++;
        if (!str[i])
        {
            s[j] = NULL;
            return (s);
        }
        i++;
    }
    s[j] = NULL;
    return (s);
}

char    **ft_split(char *str)
{
    int     i;
    char    **s;

    i = 0;
    if (!(s = (char **)malloc(sizeof(char *) * (c_w(str) + 1))))
    {
        write(1, "Memory allocation error\n", 24);
        return (NULL);
    }
    while (check_char(str[i], 2))
        i++;
    return (mas_of_char(str, s, i));
}