/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:53:16 by rrouille          #+#    #+#             */
/*   Updated: 2023/05/23 12:40:00 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_images	*init_background_image(t_params *params)
{
	t_images	*img;

	img = (t_images *)ft_gc_malloc(sizeof(t_images));
	if (!img)
		error_and_exit(BOLD""RED""MEMORY_ERROR""RESET);
	img->img = mlx_new_image(params->mlx, TILE, TILE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

void	swap_pixels(t_image_info *info, int x1, int y, int x2)
{
	char	*img_data;
	int		bpp;
	int		size_line;

	img_data = info->addr;
	bpp = info->bpp;
	size_line = info->line_length;
	*(int *)(img_data + (y * size_line + x1 * (bpp / 8))) ^= *(int *)(img_data
			+ (y * size_line + x2 * (bpp / 8)));
	*(int *)(img_data + (y * size_line + x2 * (bpp / 8))) ^= *(int *)(img_data
			+ (y * size_line + x1 * (bpp / 8)));
	*(int *)(img_data + (y * size_line + x1 * (bpp / 8))) ^= *(int *)(img_data
			+ (y * size_line + x2 * (bpp / 8)));
}

void	flip_horizontal_line(t_image_info *info, int width, int y)
{
	int	x;

	x = 0;
	while (x < width / 2)
	{
		swap_pixels(info, x, y, width - x - 1);
		x++;
	}
}

void	flip_image_horizontally(t_image_info *info, int img_width,
	int img_height)
{
	int	endian;
	int	y;

	info->addr = mlx_get_data_addr(info->img, &info->bpp, &info->line_length,
			&endian);
	y = 0;
	while (y < img_height)
	{
		flip_horizontal_line(info, img_width, y);
		y++;
	}
}

void	flip_all_images(t_params *params, t_images *images)
{
	int				i;
	t_image_info	info;

	(void)params;
	i = 0;
	while (i < 6)
	{
		info.img = images->player_idle[i++];
		flip_image_horizontally(&info, TILE, TILE);
	}
	i = 0;
	while (i < 6)
	{
		info.img = images->player_run[i++];
		flip_image_horizontally(&info, TILE, TILE);
	}
	i = 0;
	while (i < 9)
	{
		info.img = images->player_death[i++];
		flip_image_horizontally(&info, TILE, TILE);
	}
}
