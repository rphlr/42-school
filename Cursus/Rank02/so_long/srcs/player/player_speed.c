/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_speed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:58:30 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:59:09 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_speed_x(t_params *params)
{
	if (params->keys[KEY_LEFT])
		return (-MOVE_SPEED);
	if (params->keys[KEY_RIGHT])
		return (MOVE_SPEED);
	return (0);
}

int	move_speed_y(t_params *params)
{
	if (params->keys[KEY_UP])
		return (-MOVE_SPEED);
	if (params->keys[KEY_DOWN])
		return (MOVE_SPEED);
	return (0);
}
