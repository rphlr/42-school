/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:08:38 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 09:53:35 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_rgb_values(int *r, int *g, int *b, int step)
{
	if (*r == 255 && *g < 255)
		*g += step;
	else if (*g == 255 && *r > 0)
		*r -= step;
	else if (*g == 255 && *b < 255)
		*b += step;
	else if (*b == 255 && *g > 0)
		*g -= step;
	else if (*b == 255 && *r < 255)
		*r += step;
	else if (*r == 255 && *b > 0)
		*b -= step;
	else if (*b == 255 && *g < 255)
		*g += step;
	else
	{
		*r = 255;
		*g = 0;
		*b = 0;
	}
}

static char	*combine_rgb_values(char *r_str, char *g_str, char *b_str)
{
	char	*rgb_combined;

	rgb_combined = ft_strjoin(ft_strjoin(r_str, ";"), ft_strjoin(g_str, ";"));
	rgb_combined = ft_strjoin(rgb_combined, b_str);
	return (ft_strjoin("\033[38;2;", ft_strjoin(rgb_combined, "m")));
}

char	*get_next_color(void)
{
	static t_rgb	color;
	static int		step;
	char			*r_str;
	char			*g_str;
	char			*b_str;

	if (!step)
		step = 5;
	update_rgb_values(&color.r, &color.g, &color.b, step);
	r_str = ft_itoa(color.r);
	g_str = ft_itoa(color.g);
	b_str = ft_itoa(color.b);
	return (combine_rgb_values(r_str, g_str, b_str));
}

int	manage_exit(int *new_code)
{
	static int	exit_code;

	if (new_code)
		exit_code = *new_code;
	return (exit_code);
}

pid_t	manage_pid(pid_t *new_pid)
{
	static pid_t	child_pid;

	if (new_pid)
		child_pid = *new_pid;
	return (child_pid);
}
