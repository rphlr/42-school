/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easter_egg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:35:48 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/31 08:55:57 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_easter_egg(void)
{
	ft_printf(C_CLEAR);
	ft_printf(C_YELLOW"\n");
	ft_printf(MS_1);
	ft_printf(MS_2);
	ft_printf(MS_3);
	ft_printf(MS_4);
	ft_printf(MS_5);
	ft_printf("\n"C_RESET);
	ft_printf("This is a shell, not a game.\n");
	ft_printf("You can't play with it.\n");
	ft_printf("But you can play with your shell.\n");
	ft_printf("So, play with your shell.\n");
	ft_printf("\n");
}
