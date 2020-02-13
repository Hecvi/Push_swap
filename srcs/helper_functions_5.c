/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 17:44:39 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	combine_pb_pa(t_operations **operations, char *str1, char *str2, int f)
{
	t_operations *tmp;
	t_operations *tmp_next;

	tmp = (*operations);
	if (tmp && tmp->next)
		tmp_next = tmp->next;
	else
		return ;
	while (tmp)
	{
		f = 0;
		if (tmp_next->next && compare_tmp(str1, str2, tmp))
		{
			f = 1;
			tmp->next = tmp_next->next->next;
			free(tmp_next->next);
			tmp_next->next = NULL;
			free(tmp_next);
			tmp_next = NULL;
		}
		if (0 == f)
			tmp = tmp->next;
		if (tmp && tmp->next)
			tmp_next = tmp->next;
	}
}

int		compare_tmp(char *str1, char *str2, t_operations *tmp)
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
