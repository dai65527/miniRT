/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:40:53 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 20:10:18 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		mrt_color_int_to_vec(int color, double *color_vec)
{
	color_vec[0] = (double)((color >> 16) & 0xFF);
	color_vec[1] = (double)((color >> 8) & 0xFF);
	color_vec[2] = (double)(color & 0xFF);
}

int			mrt_color_vec_to_int(double *color_vec)
{
	int		r;
	int		g;
	int		b;

	r = (color_vec[0] >= 255.0) ? 255 : (int)color_vec[0];
	g = (color_vec[1] >= 255.0) ? 255 : (int)color_vec[1];
	b = (color_vec[2] >= 255.0) ? 255 : (int)color_vec[2];
	return (r << 16 | g << 8 | b);
}

int			mrt_color_apply_brightness(int color, double ratio)
{
	int		r;
	int		g;
	int		b;

	r = ((color >> 16) & 0xFF) * ratio;
	g = ((color >> 8) & 0xFF) * ratio;
	b = (color & 0xFF) * ratio;
	return ((r << 16) | (g << 8) | b);
}
