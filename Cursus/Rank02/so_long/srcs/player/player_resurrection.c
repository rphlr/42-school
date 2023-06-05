/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_resurrection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:59:54 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 10:00:12 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_resurrection_state(t_process_player_state_params *params,
								t_player *player,
								t_images *images)
{
	if (player->state == 5 && player->is_death == 1)
	{
		ft_printf(BLUE""RESURRECTION_MSG""RESET);
		*params->player_frame = player_resurrect(images, params->params, player,
				params->map);
	}
}
