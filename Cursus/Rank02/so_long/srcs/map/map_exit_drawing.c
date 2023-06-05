/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exit_drawing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:12:25 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 16:44:33 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_params *params, int i, int j)
{
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->images->exit,
		j * TILE, i * TILE);
}
