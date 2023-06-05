/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 07:36:20 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/17 09:56:35 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**prepend_program_name(char *program_name, char **argv)
{
	int		argc;
	int		i;
	char	**new_argv;

	argc = count_args(argv);
	new_argv = ft_gc_malloc((argc + 2) * sizeof(char *));
	if (!new_argv)
		return (NULL);
	new_argv[0] = program_name;
	i = -1;
	while (++i <= argc)
		new_argv[i + 1] = argv[i];
	return (new_argv);
}

char	**split_arguments(char *arg)
{
	char	**split_argv;

	split_argv = ft_split(arg, ' ');
	if (!split_argv)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (split_argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_argv;
	char	**new_argv;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split_argv = split_arguments(argv[1]);
		new_argv = prepend_program_name(argv[0], split_argv);
		split_argv = new_argv;
		argc = count_args(split_argv);
	}
	else
		split_argv = argv;
	a = parse_and_create_stack(argc, split_argv);
	b = NULL;
	if (!a && ft_strcmp(argv[1], ""))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	push_swap(a, b);
	return (0);
}
