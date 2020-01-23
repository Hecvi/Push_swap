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
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct      s_ps
{
    int             num;
    struct s_ps   *next;
}                   t_ps;

int     c_w(char *s);
void    sa(t_ps **a);
void    sb(t_ps **b);
void    ra(t_ps **a);
void    rb(t_ps **b);
void    rra(t_ps **a);
void    rrb(t_ps **b);
int     c_l(char *s, int i);
void    pa(t_ps **a, t_ps **b);
void    pb(t_ps **b, t_ps **a);
void    rr(t_ps **a, t_ps **b);
void    ss(t_ps **a, t_ps **b);
void    rrr(t_ps **a, t_ps **b);
void    first_check(char **av);
int     check_char(char c, int flag);
void    free_list(t_ps **a, int flag);
char    **ft_split(char *str, t_ps **a);
int     check_number(t_ps **a, int number);
void    free_split(char **s, int words, int flag);
int     func_atoi(char *str, int sign, int *indicator);
int     check_string_of_array(char *s, int *indicator);
void    second_check(char **av, t_ps **a, int i, int j);
void    create_list(t_ps **a, int i, char **s, int words);
void    free_all(char **s, int words, t_ps **a, int flag);
char    **mas_of_char(char *str, char **s, t_ps **a, int i, int j);




#endif
