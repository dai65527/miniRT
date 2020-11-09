/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:29:11 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 17:43:35 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static double		sphere_calc_dist(t_ray *ray, t_sphere *sphere, int *flg_inside)
{
	double		b;
	double		c;
	double		d;
	double		dist;
	double		vec[3];

	*flg_inside = 0;
	math_3dvec_minus(ray->orig, sphere->pos, vec);
	b = 2.0 * math_3dvec_innerprod(ray->dir, vec);
	c = math_3dvec_norm(vec);
	c = c * c - sphere->dia * sphere->dia / 4.0;
	d = b * b - 4.0 * c;
	if (d < -MRT_EPS)
		return (-1);
	if (mrt_isineps(d))
		return (-b / 2);
	else if ((dist = (-b - sqrt(d)) / 2.0) > MRT_EPS)
		return (dist);
	*flg_inside = 1;
	return ((-b + sqrt(d)) / 2.0);
}

static t_surface	sphere_solve(t_ray *ray, t_sphere *sphere)
{
	t_surface	surface;
	double		vec[3];
	int			flg_inside;

	if ((surface.dist = sphere_calc_dist(ray, sphere, &flg_inside)) <= MRT_EPS)
		return (surface);
	math_3dvec_applylen(ray->dir, surface.dist, vec);
	math_3dvec_plus(ray->orig, vec, surface.pos);
	math_3dvec_minus(surface.pos, sphere->pos, surface.normvec);
	math_3dvec_normalize(surface.normvec, surface.normvec);
	if (flg_inside)
		math_3dvec_applylen(surface.normvec, -1.0, surface.normvec);
	surface.color = sphere->color;
	return (surface);
}

t_surface			mrt_findintersection_sphere(t_ray *ray, t_list *spheres)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (spheres)
	{
		surface_tmp = sphere_solve(ray, spheres->content);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		spheres = spheres->next;
	}
	return (surface);
}
