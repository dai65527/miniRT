/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace_calc_reflect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:46:29 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:03 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static void	calc_reflect_applyratio(double *color_vec, double *ratio_vec, double *res_vec)
{
	res_vec[0] = color_vec[0] * ratio_vec[0];
	res_vec[1] = color_vec[1] * ratio_vec[1];
	res_vec[2] = color_vec[2] * ratio_vec[2];
}

static void	calc_reflect_amblight(t_surface *surface, t_amblight *amblight, double color_vec[3])
{
	double	reflect_ratio[3];

	mrt_color_int_to_vec(surface->color, reflect_ratio);
	math_3dvec_applylen(reflect_ratio, 1.0 / 255.0, reflect_ratio);
	mrt_color_int_to_vec(amblight->color, color_vec);
	math_3dvec_applylen(color_vec, amblight->ratio, color_vec);
	calc_reflect_applyratio(color_vec, reflect_ratio, color_vec);
}

int			mrt_raytrace_calc_reflect(t_surface *surface, t_scene *scene)
{
	double	color_vec[3];
	double	color_vec_tmp[3];

	ft_bzero(color_vec, sizeof(color_vec));
	calc_reflect_amblight(surface, scene->amblights->content, color_vec_tmp);
	math_3dvec_plus(color_vec, color_vec_tmp, color_vec);
	return (mrt_color_vec_to_int(color_vec));
}
