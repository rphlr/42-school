/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:53:11 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 15:02:31 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_power(int nb, int power)
{
	int	nombre;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nombre = nb * ft_power(nb, power - 1);
	return (nombre);
}
