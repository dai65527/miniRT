/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:40:53 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 07:16:14 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
