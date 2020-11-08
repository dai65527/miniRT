/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace_calc_reflect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:46:29 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/08 11:04:16 by dnakano          ###   ########.fr       */
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

static void	calc_reflect_amblight(t_surface *surface, t_amblight *amblight, double *color_vec)
{
	double	reflect_ratio[3];

	mrt_color_int_to_vec(surface->color, reflect_ratio);
	math_3dvec_applylen(reflect_ratio, 1.0 / 255.0, reflect_ratio);
	mrt_color_int_to_vec(amblight->color, color_vec);
	math_3dvec_applylen(color_vec, amblight->ratio, color_vec);
	calc_reflect_applyratio(color_vec, reflect_ratio, color_vec);
}

 int	has_obstruction(t_surface *surface, t_light *light, t_scene *scene)
{
	t_ray		ray_surface_light;
	t_surface	obstsurface;

	ray_surface_light.orig = surface->pos;
	math_3dvec_minus(light->pos, surface->pos, ray_surface_light.dir);
	math_3dvec_normalize(ray_surface_light.dir, ray_surface_light.dir);
	obstsurface = mrt_findintersection(&ray_surface_light, scene);
	return (obstsurface.dist > MRT_EPSIRON);
}

static void	calc_reflect_light(t_ray *ray, t_surface *surface, t_light *light, double *color_vec)
{
	double	innnerprod_tmp;
	double	vec_s2l[3];
	double	vec_tmp[3];
	double	lightcolor_vec[3];
	double	reflect_ratio[3];

	math_3dvec_minus(light->pos, surface->pos, vec_s2l);
	math_3dvec_normalize(vec_s2l, vec_s2l);
	if ((innnerprod_tmp = math_3dvec_innerprod(surface->normvec, vec_s2l)) < 0.0)
	{
		ft_bzero(color_vec, sizeof(double) * 3);
		return ;
	}
	mrt_color_int_to_vec(surface->color, reflect_ratio);
	math_3dvec_applylen(reflect_ratio, 1.0 / 255.0, reflect_ratio);
	mrt_color_int_to_vec(light->color, lightcolor_vec);
	math_3dvec_applylen(lightcolor_vec, innnerprod_tmp * light->ratio, color_vec);
	calc_reflect_applyratio(color_vec, reflect_ratio, color_vec);
	math_3dvec_applylen(surface->normvec, 2.0 * innnerprod_tmp, vec_tmp);
	math_3dvec_minus(vec_tmp, vec_s2l, vec_tmp);
	if ((innnerprod_tmp = -math_3dvec_innerprod(ray->dir, vec_tmp)) < 0.0)
		return ;
	math_3dvec_applylen(lightcolor_vec, SPECREFLEC_FACTOR * pow(innnerprod_tmp, SHININESS), vec_tmp);
	math_3dvec_plus(color_vec, vec_tmp, color_vec);
}

int			mrt_raytrace_calc_reflect(t_ray *ray, t_surface *surface, t_scene *scene)
{
	t_list	*lights;
	double	color_vec[3];
	double	color_vec_tmp[3];

	lights = scene->lights;
	ft_bzero(color_vec, sizeof(color_vec));
	calc_reflect_amblight(surface, scene->amblights->content, color_vec_tmp);
	math_3dvec_plus(color_vec, color_vec_tmp, color_vec);
	while (lights)
	{
		if (!has_obstruction(surface, lights->content, scene))
		{
			calc_reflect_light(ray, surface, lights->content, color_vec_tmp);
			math_3dvec_plus(color_vec, color_vec_tmp, color_vec);
		}
		lights = lights->next;
	}
	return (mrt_color_vec_to_int(color_vec));
}
