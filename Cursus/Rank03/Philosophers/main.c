/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:42:08 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/30 19:01:55 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosophers.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum e_status
{
	IS_SLEEPING,
	IS_THINKING,
	IS_EATING
}	t_status;

typedef struct s_philos
{
	int				curr_philo;
	bool			right_fork_free;
	bool			left_fork_free;
	t_status		status;
	struct s_philos	*prev;
	struct s_philos	*next;
}	t_philos;

typedef struct s_state
{
	int			nbr_of_philo;
	int			nbr_of_fork;
	int			max_eat;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
}	t_state;

int	ft_atoi(const char *str)
{
	int	result;
	int	is_minus;

	result = 0;
	is_minus = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	return (result * is_minus);
}

void	init(int ac, char **av)
{
	t_state		global_state;
	t_philos	curr_philo;

	if (ac == 6)
		global_state.max_eat = ft_atoi(av[ac - 1]);
	if (ac == 5)
		global_state.max_eat = -1;
	global_state.nbr_of_philo = ft_atoi(av[1]);
	global_state.nbr_of_fork = ft_atoi(av[1]);
	global_state.time_to_die = ft_atoi(av[2]);
	global_state.time_to_eat = ft_atoi(av[3]);
	global_state.time_to_sleep = ft_atoi(av[4]);
	curr_philo.right_fork_free = true;
	curr_philo.left_fork_free = true;
	curr_philo.status = IS_THINKING;
	printf("max_eat =  %i\nnbr_of_philo =  %i\nnbr_of_fork =  %i\ntime_to_die =  %i\ntime_to_eat =  %i\ntime_to_sleep =  %i\ncurr_state = %i\n", global_state.max_eat, global_state.nbr_of_philo,	global_state.nbr_of_fork, global_state.time_to_die, global_state.time_to_eat, 	global_state.time_to_sleep, curr_philo.status);
}

bool	check_int(char *cur_arg_value)
{
	while (*cur_arg_value)
	{
		if (!(*cur_arg_value >= '0' && *cur_arg_value <= '9'))
			return (false);
		cur_arg_value++;
	}
	return (true);
}

bool	check_args(int ac, char **av)
{
	int		cur_arg_nbr;
	char	*cur_arg_value;

	cur_arg_nbr = 0;
	while (++cur_arg_nbr != ac)
	{
		cur_arg_value = av[cur_arg_nbr];
		if (!check_int(cur_arg_value))
			return (false);
	}
	return (true);
}

bool	check_validity(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		return (check_args(ac, av));
	return (false);
}

int	main(int ac, char **av)
{
	if (!check_validity(ac, av))
		printf("NOK\n");
	else
	{
		printf("OK\n");
		init(ac, av);
	}
}
