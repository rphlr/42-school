/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:01 by rrouille          #+#    #+#             */
/*   Updated: 2023/02/06 19:04:35 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		put_pixel(t_var *v, int type)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = v->x;
	y = v->y;
	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
			&& x < WIN_W && y >= 0 && y < WIN_H)
	{
		i = ((int)v->x * (v->bpp / 8)) + ((int)v->y * v->sl);
		rgb = (char*)&v->clr;
		v->d[i] = rgb[0];
		v->d[++i] = rgb[1];
		v->d[++i] = rgb[2];
	}
	return (0);
}

int		ft_shade_color(int clr, double val)
{
	int r;
	int g;
	int b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr >> 16) & 0xFF) - D(D((clr >> 16) & 0xFF) * val));
	g = floor(D((clr >> 8) & 0xFF) - D(D((clr >> 8) & 0xFF) * val));
	b = floor(D((clr) & 0xFF) - D(D((clr) & 0xFF) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

t_rgb			ft_hsv_to_rgb(t_hsv hsv)
{
	t_rgb		rgb;
	double		p;
	double		q;
	double		t;

	(hsv.h == 360.) ? (hsv.h = 0.) : (hsv.h /= 60.);
	p = hsv.v * (1. - hsv.s);
	q = hsv.v * (1. - (hsv.s * (hsv.h - floor(hsv.h))));
	t = hsv.v * (1. - (hsv.s * (1. - (hsv.h - floor(hsv.h)))));
	rgb = (t_rgb){.r = 0., .g = 0., .b = 0.};
	if (hsv.s == 0.)
		rgb = (t_rgb){.r = hsv.v, .g = hsv.v, .b = hsv.v};
	else if (0. <= hsv.h && hsv.h < 1.)
		rgb = (t_rgb){.r = hsv.v, .g = t, .b = p};
	else if (1. <= hsv.h && hsv.h < 2.)
		rgb = (t_rgb){.r = q, .g = hsv.v, .b = p};
	else if (2. <= hsv.h && hsv.h < 3.)
		rgb = (t_rgb){.r = p, .g = hsv.v, .b = t};
	else if (3. <= hsv.h && hsv.h < 4.)
		rgb = (t_rgb){.r = p, .g = q, .b = hsv.v};
	else if (4. <= hsv.h && hsv.h < 5.)
		rgb = (t_rgb){.r = t, .g = p, .b = hsv.v};
	else if (5. <= hsv.h && hsv.h < 6.)
		rgb = (t_rgb){.r = hsv.v, .g = p, .b = q};
	return (rgb);
}

int				ft_rgb_to_hex(t_rgb rgb)
{
	int			r;
	int			g;
	int			b;

	r = (int)(rgb.r * 255.0);
	g = (int)(rgb.g * 255.0);
	b = (int)(rgb.b * 255.0);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int				ft_hsv_to_hex(double h, double s, double v)
{
	t_hsv		hsv;
	t_rgb		rgb;

	hsv = (t_hsv){.h = h, .s = s, .v = v};
	rgb = ft_hsv_to_rgb(hsv);
	return (ft_rgb_to_hex(rgb));
}

int	edit_hue_hex(t_var *v)
{
	t_hsv	hsv;
	t_rgb	rgb;

	if (v->i == v->imax)
		return (0x000000);
	else
	{
		hsv.h = v->clr_h + ((240. / v->imax) * v->i);
		hsv.s = v->clr_s;
		hsv.v = v->clr_v - (((v->clr_v - 0.10) / 100.0) * v->i);
		while (hsv.h < 0.)
			hsv.h += 360.0;
		while (hsv.h > 360.)
			hsv.h -= 360.0;
		rgb = ft_hsv_to_rgb(hsv);
	}
	return (ft_rgb_to_hex(rgb));
}

void	mandelbrot(t_var *v)
{
	v->i = -2.0;
	v->zr = 0.0;
	v->zi = 0.0;
	v->mod = (v->num == 2) ? 2 : -2;
	v->mr = (v->e == 0 || v->e == 2) ? (D(v->x) / v->z) + v->minx :
	(D(v->y) / v->z) + v->miny;
	v->mi = (v->e == 0 || v->e == 2) ? (D(v->y) / v->z) + v->miny :
	(D(v->x) / v->z) + v->minx;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->mr;
		v->zi = v->mod * v->zi * v->tmp + v->mi;
	}
	v->clr = edit_hue_hex(v);
	//if (((v->x >= 25 && v->x <= 188) &&
	// ((v->y >= 25 && v->y <= 213) || (v->y >= 237 && v->y <= 326) ||
	// (v->y >= (WIN_H - 133) && v->y <= (WIN_H - 25)))) ||
	// (v->x >= (v->len - 1) && v->x <= (WIN_W - 25) &&
	// v->y >= (WIN_H - 65) && v->y <= (WIN_H - 25)))
	// 	v->clr = ft_shade_color(v->clr, 0.35);
	put_pixel(v, 0);
}

static int	error(int type, char **argv)
{
	char *str;

	if (type == 0)
		write(1, MSG0, ft_strlen(MSG0));
	else if (type == 1)
		write(1, MSG1, ft_strlen(MSG1));
	else if (type == 2)
	{
		str = ft_strjoin(ft_strjoin("error : \"", argv[1]), MSG3);
		write(1, str, ft_strlen(str));
		write(1, "\n", 2);
		write(1, MSG0, ft_strlen(MSG0));
		free(str);
	}
	write(1, "\n", 1);
	return (-1);
}

static int		check(t_var *v, char **argv, int len)
{
	int		i;
	char	input[len + 1];
	i = 0;
	// ft_strcpy(v->ftl[0], "Julia\0");
	// ft_strcpy(v->ftl[1], "Mandelbrot\0");
	// ft_strcpy(v->ftl[2], "Tricorn\0");
	ft_strlcpy(input, argv[1], len + 1);
	while (input[i])
	{
		input[i] = ft_tolower(input[i]);
		i++;
	}
	if (ft_strcmp(input, "julia") == 0)
	{
		v->num = 1;
		write(1, "Julia", 5);
	}
	else if (ft_strcmp(input, "mandelbrot") == 0)
	{
		v->num = 2;
		write(1, "Mandelbrot", 10);
//		init_win(v);
	}
	else if (ft_strcmp(input, "tricorn") == 0)
	{
		v->num = 3;
		write(1, "Tricorn", 7);
	}
	else
		return (1);
	return (0);
}

int		close_hook(int button, t_var *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}

void	draw_fractal(t_var *v)
{
	v->y = -1;
//	v->nam = ft_strjoin("Fractal : ", ft_firstupper(v->ftl[v->num - 1]));
//	v->len = WIN_W - 50 - ft_strlen(v->nam) * 10;
//	rotate_fractal(v, v->rot);
	while (++v->y < WIN_H && (v->x = -1) == -1)
	{
		while (++v->x < WIN_W)
		{
			//if (v->num == 1)
				//fractal_julia(v);
			/*else*/ if (v->num == 2)
			{
				mandelbrot(v);
			}
			//else if (v->num == 3)
				//fractal_mandelbrot(v);
		}
	}
}

int		expose_hook(t_var *v)
{
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	draw_fractal(v);
//	user_interface(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
//	user_interface_texts(v);
	return (0);
}

static void		assign(t_var *v)
{
	//v->e = 0;
	v->rot = 0;
	v->z = 170.0;
	//v->padx = 0.;
	//v->pady = 0.;
	v->imax = 21.;
	//v->jr = -1.1380;
	//v->ji = 0.2403;
	v->clr_h = 358.;
	v->clr_s = 0.80;
	v->clr_v = 0.92;
	//v->m = UI_DISABLE_CLR;
}

int		key_hook(int keycode, t_var *v)
{
	int		r;

	r = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else
	{
		// if (keycode >= 1 && keycode <= 123 && ++r > 0)
		// 	controls_part_one(v, keycode);
		// else if (keycode >= 124 && keycode <= 258 && ++r > 0)
		// 	controls_part_two(v, keycode);
		if (r > 0)
		{
			mlx_destroy_image(v->mlx, v->img);
			mlx_clear_window(v->mlx, v->win);
			expose_hook(v);
		}
	}
	return (0);
}

static void		init_win(t_var *v)
{
	assign(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_W, WIN_H, PROG_NAME);
	mlx_expose_hook(v->win, expose_hook, v);
//	mlx_hook(v->win, 6, 64, motion_hook, v);
	mlx_hook(v->win, 17, 0, close_hook, v);
	mlx_hook(v->win, 2, 0, key_hook, v);
//	mlx_mouse_hook(v->win, mouse_hook, v);
//	mlx_do_key_autorepeaton(v->mlx);
	mlx_loop(v->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// //int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Go fuck yourself!!!!");
	// mlx_loop(mlx);

	t_var *v;
	int len;

	len = 0;
	v = (t_var *)malloc(sizeof(t_var));
	v->nbr = argc;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (check(v, argv, len) > 0)
			return (error(2, argv));
		init_win(v);
	}
	else 
		return (error(0, argv));
	return (0);
}
