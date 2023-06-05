/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2023/02/06 18:33:40 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../mylib/includes/mylib.h"
# include "../mlx/mlx.h"

# define D (double)

# define UI_CLR 0xC0C0C0
# define UI_DISABLE_CLR ft_hsv_to_hex(v->clr_h, v->clr_s, v->clr_v)

# define PROG_NAME "fract-ol by rrouille"

# define MIN_X v->minx
# define MIN_Y v->miny
# define MAX_X v->maxx
# define MAX_Y v->maxy

# define WIN_W 1280
# define WIN_H 720

# define MID_W 640
# define MID_H 360

# define MIN_J -3.20
# define MAX_J 3.200

# define MSG0 "usage: ./fractol (Julia / Mandelbrot / Tricorn)"
# define MSG1 "error: Window size must be greater than 1024 x 576."
# define MSG3 "\" isn't a valid fractal name."

typedef struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct	s_var
{
	int			e;
	int			m;
	int			x;
	int			y;
	int			sl;
	int			len;
	int			nbr;
	int			num;
	int			bpp;
	int			end;
	int			rot;
	int			clr;
	char		*d;
	char		*nam;
	char		ftl[3][12];
	float		minx;
	float		miny;
	double		i;
	double		z;
	double		imax;
	double		padx;
	double		pady;
	double		clr_h;
	double		clr_s;
	double		clr_v;
	long double	jr;
	long double	ji;
	long double	mr;
	long double	mi;
	long double	zr;
	long double	zi;
	long double	tmp;
	long double	mod;
	void		*img;
	void		*mlx;
	void		*win;
}				t_var;

static void		init_win(t_var *v);
int		close_hook(int button, t_var *v);

#endif
