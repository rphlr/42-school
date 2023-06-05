/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:57 by rrouille          #+#    #+#             */
/*   Updated: 2023/04/17 09:23:52 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int keycode, t_params *params)
{
	params->keys[keycode] = 0;
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT || keycode == KEY_E || keycode == KEY_D
		|| keycode == KEY_R)
		params->keys[keycode] = 1;
	if (keycode == ESC_KEY || keycode == KEY_Q)
		close_window(params);
	return (0);
}

int	handle_key_release(int keycode, t_params *params)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP
		|| keycode == KEY_DOWN || keycode == KEY_E || keycode == KEY_D
		|| keycode == KEY_R)
		params->keys[keycode] = 0;
	return (0);
}
