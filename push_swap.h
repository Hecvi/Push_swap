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
# define MAX 2147483647
# define MIN 2147483648
# include "libft/libft.h"

typedef struct      s_ps
{
    int             num;
    int             index;
    int             flag;
    struct s_ps   *next;
}                   t_ps;

int     c_w(char *s);
char    *sa(t_ps **a);
char    *sb(t_ps **b);
char    *ra(t_ps **a);
char    *rb(t_ps **b);
char    *rra(t_ps **a);
char    *rrb(t_ps **b);
int     find_max(t_ps **a);
int     c_l(char *s, int i);
void    first_check(char **av);
char    *pa(t_ps **a, t_ps **b);
char    *pb(t_ps **b, t_ps **a);
char    *rr(t_ps **a, t_ps **b);
char    *ss(t_ps **a, t_ps **b);
char    *rrr(t_ps **a, t_ps **b);
int     check_char(char c, int flag);
void    free_list(t_ps **a, int flag);
int     check_order_in_stack(t_ps **a);
char    **ft_split(char *str, t_ps **a);
int     check_number(t_ps **a, int number);
void    sort_by_index(t_ps **a, int count);
void    free_split(char **s, int words, int flag);
int     func_atoi(char *str, int sign, int *indicator);
int     check_string_of_array(char *s, int *indicator);
void    second_check(char **av, t_ps **a, int i, int j);
void    free_all(char **s, int words, t_ps **a, int flag);
void    create_list_a(t_ps **a, int i, char **s, int words);
void    filling_in_lists(t_ps **a, int i, char **s, int words);
char    **mas_of_char(char *str, char **s, t_ps **a, int i, int j);




#endif
