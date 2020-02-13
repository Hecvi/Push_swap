/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:32 by klaurine          #+#    #+#             */
/*   Updated: 2020/02/13 16:55:28 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	start_read_gnl(t_ps **a, t_ps **b, t_operations **operations, int flag)
{
	int		fd;
	char	*str;

	if (1 == flag)
		fd = open_file(a, operations);
	else
		fd = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (!check_command(a, b, operations, str))
		{
			write(1, "Error: Incorrect commands\n", 26);
			free_list_operations(operations);
			free_list(a, 0);
			free_list(b, 0);
			free(str);
			str = NULL;
			close(fd);
			exit(1);
		}
		free(str);
	}
	str = NULL;
	close(fd);
}

int		check_command(t_ps **a, t_ps **b, t_operations **operations, char *str)
{
	if (!ft_strcmp(str, "sa"))
		sa(a, b, operations);
	else if (!ft_strcmp(str, "sb"))
		sb(b, a, operations);
	else if (!ft_strcmp(str, "ss"))
		ss(a, b, operations);
	else if (!ft_strcmp(str, "ra"))
		ra(a, b, operations);
	else if (!ft_strcmp(str, "rb"))
		rb(b, a, operations);
	else if (!ft_strcmp(str, "rr"))
		rr(a, b, operations);
	else if (!ft_strcmp(str, "pa"))
		pa(b, a, operations);
	else if (!ft_strcmp(str, "pb"))
		pb(a, b, operations);
	else if (!ft_strcmp(str, "rra"))
		rra(a, b, operations);
	else if (!ft_strcmp(str, "rrb"))
		rrb(b, a, operations);
	else if (!ft_strcmp(str, "rrr"))
		rrr(a, b, operations);
	else
		return (0);
	return (1);
}

int		open_file(t_ps **a, t_operations **operations)
{
	int fd;

	fd = open("Operations.txt", O_RDONLY, 0);
	if (-1 == fd || fd > FD_MAX)
	{
		write(1, "Error: Cannot read file\n", 24);
		free_list_operations(operations);
		free_list(a, 0);
		exit(1);
	}
	return (fd);
}

void	data_reading(t_ps **a, t_ps **b, t_operations **operations, char **av)
{
	if ('-' == av[1][0] && 'w' == av[1][1] && !av[1][2])
		start_read_gnl(a, b, operations, 1);
	else
		start_read_gnl(a, b, operations, 0);
}

int		main(int ac, char **av)
{
	int				i;
	int				j;
	t_ps			*a;
	t_ps			*b;
	t_operations	*operations;

	i = 0;
	j = 0;
	a = NULL;
	b = NULL;
	operations = NULL;
	first_check(av, ac);
	second_check(av, &a, i, j);
	data_reading(&a, &b, &operations, av);
	if (check_order_in_stack(&a) && NULL == b)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		free_list(&b, 0);
	}
	free_list_operations(&operations);
	free_list(&a, 0);
	return (0);
}
