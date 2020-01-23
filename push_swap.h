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
//# include "libft/libft.h"

typedef struct      s_ps
{
    int             num;
    struct s_ps   *next;
}                   t_ps;

int     c_w(char *s);
int     c_l(char *s, int i);
int     free_char(char **s, int j, int flag);
char    **mas_of_char(char *str, char **s, int i);
char    **ft_split(char *str, t_ps **a);
void    free_list(t_ps **a, int flag);
void    create_list(t_ps **a, int i, char *s);
int     check_char(char c, int flag);
void    first_check(char **av);
int     func_atoi(char *str, int sign, int *indicator);
int     check_string_of_array(char *s, int *indicator);
void    second_check(char **av, t_ps **a, int i, int j);
void    sa(t_ps **a);
void    sb(t_ps **b);
void    ss(t_ps **a, t_ps **b);
void    pa(t_ps **a, t_ps **b);
void    pb(t_ps **b, t_ps **a);
void    ra(t_ps **a);
void    rb(t_ps **b);
void    rr(t_ps **a, t_ps **b);
void    rra(t_ps **a);
void    rrb(t_ps **b);
void    rrr(t_ps **a, t_ps **b);

#endif
