/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace_calc_reflect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:46:29 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 08:49:09 by dnakano          ###   ########.fr       */
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
	math_vec3_applylen(reflect_ratio, 1.0 / 255.0, reflect_ratio);
	mrt_color_int_to_vec(amblight->color, color_vec);
	math_vec3_applylen(color_vec, amblight->ratio, color_vec);
	calc_reflect_applyratio(color_vec, reflect_ratio, color_vec);
}

 int	has_obstruction(t_surface *surface, t_light *light, t_scene *scene)
{
	double		vec_s2l[3];
	t_ray		ray_s2l;
	t_surface	obstsurface;

	ray_s2l.orig = surface->pos;
	math_vec3_minus(light->pos, surface->pos, vec_s2l);
	math_vec3_normalize(vec_s2l, ray_s2l.dir);
	obstsurface = mrt_findintersection(&ray_s2l, scene);
	return (obstsurface.dist > MRT_EPS && obstsurface.dist < math_vec3_norm(vec_s2l));
}

static void	calc_reflect_light(t_ray *ray, t_surface *surface, t_light *light, double *color_vec)
{
	double	innnerprod_tmp;
	double	vec_s2l[3];
	double	vec_tmp[3];
	double	lightcolor_vec[3];
	double	reflect_ratio[3];

	math_vec3_minus(light->pos, surface->pos, vec_s2l);
	math_vec3_normalize(vec_s2l, vec_s2l);
	if ((innnerprod_tmp = math_vec3_innerprod(surface->normvec, vec_s2l)) < MRT_EPS)
	{
		ft_bzero(color_vec, sizeof(double) * 3);
		return ;
	}
	mrt_color_int_to_vec(surface->color, reflect_ratio);
	math_vec3_applylen(reflect_ratio, 1.0 / 255.0, reflect_ratio);
	mrt_color_int_to_vec(light->color, lightcolor_vec);
	math_vec3_applylen(lightcolor_vec, innnerprod_tmp * light->ratio, color_vec);
	calc_reflect_applyratio(color_vec, reflect_ratio, color_vec);
	math_vec3_applylen(surface->normvec, 2.0 * innnerprod_tmp, vec_tmp);
	math_vec3_minus(vec_tmp, vec_s2l, vec_tmp);
	if ((innnerprod_tmp = -math_vec3_innerprod(ray->dir, vec_tmp)) < 0.0)
		return ;
	math_vec3_applylen(lightcolor_vec, SPECREFLEC_FACTOR * pow(innnerprod_tmp, SHININESS) * light->ratio, vec_tmp);
	math_vec3_plus(color_vec, vec_tmp, color_vec);
}

int			mrt_raytrace_calc_reflect(t_ray *ray, t_surface *surface, t_scene *scene)
{
	t_list	*lights;
	double	color_vec[3];
	double	color_vec_tmp[3];

	lights = scene->lights;
	ft_bzero(color_vec, sizeof(color_vec));
	calc_reflect_amblight(surface, scene->amblights->content, color_vec_tmp);
	math_vec3_plus(color_vec, color_vec_tmp, color_vec);
	while (lights)
	{
		if (!has_obstruction(surface, lights->content, scene))
		{
			calc_reflect_light(ray, surface, lights->content, color_vec_tmp);
			math_vec3_plus(color_vec, color_vec_tmp, color_vec);
		}
		lights = lights->next;
	}
	return (mrt_color_vec_to_int(color_vec));
}
