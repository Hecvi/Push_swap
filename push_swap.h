/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:40:20 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:40:22 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
//# include "libft/libft.h"

typedef struct      s_ps
{
    int             num;
    struct s_ps   *next;
}                   t_ps;

int     c_w(char *s);
int     c_l(char *s, int i);
int     free_char(char **s, int j);
char    **mas_of_char(char *str, char **s, int i);
char    **ft_split(char *str);
void    free_list(t_ps **a, int flag);
void    create_list(t_ps **a, int i);
int     check_char(char c, int flag);
void    first_check(char **av);
int     func_atoi(char *str, int sign, int *indicator);
int     check_string_of_array(char *s);
int     second_check(char **av, t_ps **a);
size_t	ft_strlen(const char *s);

#endif
