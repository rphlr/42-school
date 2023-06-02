/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:51 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 14:47:34 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_params *params, t_images *images)
{
	load_player_idle_frames(params, images);
	load_player_run_frames(params, images);
	load_player_death_frames(params, images);
	load_enemy_idle_frames(params, images);
	load_enemy_run_frames(params, images);
	load_enemy_death_frames(params, images);
	load_utils_images(params, images);
}

void	load_utils_images(t_params *params, t_images *images)
{
	char	*pathnames[6];
	char	**current_pathname;
	int		i;

	pathnames[0] = "sprites/wall.xpm";
	pathnames[1] = "sprites/floor.xpm";
	pathnames[2] = "sprites/collectibles/taco.xpm";
	pathnames[3] = "sprites/collectibles/sushi.xpm";
	pathnames[4] = "sprites/collectibles/dish.xpm";
	pathnames[5] = "sprites/exit.xpm";
	i = 0;
	current_pathname = pathnames;
	load_frames(params, current_pathname++, 1, (void **)&images->wall);
	load_frames(params, current_pathname++, 1, (void **)&images->floor);
	load_frames(params, current_pathname++, 1, (void **)&images->taco);
	load_frames(params, current_pathname++, 1, (void **)&images->sushi);
	load_frames(params, current_pathname++, 1, (void **)&images->dish);
	load_frames(params, current_pathname++, 1, (void **)&images->exit);
}

void	load_frames(t_params *params, char **frames, int num_frames,
		void **dest)
{
	int	i;
	int	img_width;
	int	img_height;

	i = -1;
	while (++i < num_frames)
	{
		dest[i] = mlx_xpm_file_to_image(params->mlx, frames[i], &img_width,
				&img_height);
		if (dest[i] == NULL)
			error_and_exit(BOLD""RED""IMAGE_ERROR""RESET);
	}
}
