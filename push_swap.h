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
    int             block;
    int             index;
    int             sort;
    struct s_ps   *next;
}                   t_ps;

typedef struct      s_operations
{
    char                    *str;
    struct s_operations     *next;
}                   t_operations;

int     c_w(char *s);
int     find_max(t_ps **stack);
int     find_min(t_ps **stack);
int     c_l(char *s, int i);
void    check_list_a(t_ps **a);
void    print_operations(t_operations **operations);
void    first_check(char **av, int ac);
int     check_char(char c, int flag);
void    free_list(t_ps **a, int flag);
int     check_order_in_stack(t_ps **a);
char    **ft_split(char *str, t_ps **a);
void    general_sort(t_ps **a, t_ps **b);
int     check_number(t_ps **a, int number);
void    sort_by_index(t_ps **a, int count);
void    if_we_have_up_to_five_numbers(t_ps **a, t_ps **b, t_operations **operations);
void    free_split(char **s, int words, int flag);
int     func_atoi(char *str, int sign, int *indicator);
int     check_string_of_array(char *s, int *indicator);
void    second_check(char **av, t_ps **a, int i, int j);
void    free_list_operations(t_operations **operations);
void    pa(t_ps **b, t_ps **a, t_operations **operations);
void    pb(t_ps **a, t_ps **b, t_operations **operations);
void    rr(t_ps **a, t_ps **b, t_operations **operations);
void    ss(t_ps **a, t_ps **b, t_operations **operations);
void    free_all(char **s, int words, t_ps **a, int flag);
void    sa(t_ps **a, t_ps **b, t_operations **operations);
void    sb(t_ps **b, t_ps **a, t_operations **operations);
void    ra(t_ps **a, t_ps **b, t_operations **operations);
void    rb(t_ps **b, t_ps **a, t_operations **operations);
void    rra(t_ps **a, t_ps **b, t_operations **operations);
void    rrb(t_ps **b, t_ps **a, t_operations **operations);
void    rrr(t_ps **a, t_ps **b, t_operations **operations);
void    create_list_a(t_ps **a, int i, char **s, int words);
void    filling_in_lists(t_ps **a, int i, char **s, int words);
char    **mas_of_char(char *str, char **s, t_ps **a, int i);
void    sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int n);
void    sort_first_part(t_ps **a, t_ps **b, t_operations **operations, int mid);
void    sort_of_three_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations, int flag);
void    create_list_operations(t_operations **operations, t_ps **a, t_ps **b, char *s);
void    sort_of_five_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations);
void    sort_of_two_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations);
void    sort_of_four_numbers_by_ascending(t_ps **a, t_ps **b, t_operations **operations);
void    ability_to_combine(t_operations **operations, char *str1, char *str2, char *str3);
void    general_sort_continue(t_ps **a, t_operations **operations);

#endif
