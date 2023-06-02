/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_state_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:01:40 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 10:01:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_state(t_params *params)
{
	if (params->keys[KEY_UP] || params->keys[KEY_DOWN] || params->keys[KEY_LEFT]
		|| params->keys[KEY_RIGHT])
		params->player->state = 1;
	else if (params->keys[KEY_E])
		params->player->state = 2;
	else if (params->keys[KEY_D])
		params->player->state = 3;
	else if (params->keys[KEY_R])
		params->player->state = 5;
	else
		params->player->state = 0;
}
