/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace_calc_raytrace.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:23:00 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 14:53:27 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static double		sphere_calc_dist(t_ray *ray, t_sphere *sphere)
{
	double		b;
	double		c;
	double		d;
	double		t;
	double		vec[3];

	math_3dvec_minus(ray->orig, sphere->pos, vec);
	b = 2.0 * math_3dvec_innerprod(ray->dir, vec);
	c = math_3dvec_norm(vec);
	c = c * c - sphere->dia * sphere->dia / 4.0;
	d = b * b - 4.0 * c;
	if (d < 0)
		return (-1);
	if (d == 0)
		return (-b / 2);
	else if ((t = (-b - sqrt(d)) / 2.0) > 0)
		return (t);
	return ((-b + sqrt(d)) / 2.0);
}

static t_surface	sphere_solve(t_ray *ray, t_sphere *sphere)
{
	t_surface	surface;
	double		vec[3];

	if ((surface.dist = sphere_calc_dist(ray, sphere)) <= 0.0)
		return (surface);
	math_3dvec_applylen(ray->dir, surface.dist, vec);
	math_3dvec_plus(ray->orig, vec, surface.pos);
	math_3dvec_minus(surface.pos, sphere->pos, surface.normvec);
	math_3dvec_normalize(surface.normvec, surface.normvec);
	surface.color = sphere->color;
	return (surface);
}

int					mrt_surface_isnearer(t_surface old, t_surface new)
{
	if (new.dist <= 0.0)
		return (0);
	return (old.dist <= 0.0 || new.dist < old.dist);
}

t_surface			mrt_findintersection_sphere(t_ray *ray, t_list *spheres)
{
	t_sphere	*sphere;
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (spheres)
	{
		sphere = (t_sphere *)spheres->content;
		surface_tmp = sphere_solve(ray, sphere);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		spheres = spheres->next;
	}
	return (surface);
}

static t_surface	findintersection(t_ray *ray, t_scene *scene)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	surface_tmp = mrt_findintersection_sphere(ray, scene->spheres);
	if (mrt_surface_isnearer(surface, surface_tmp))
		surface = surface_tmp;
	// surface_tmp = mrt_getintersection_plane(ray, scene);
	// if (get_intersectionsurface_isnearer(surface, surface_tmp))
	// 	surface = surface_tmp;
	// surface_tmp = mrt_getintersection_sqr(ray, scene);
	// if (get_intersectionsurface_isnearer(surface, surface_tmp))
	// 	surface = surface_tmp;
	// surface_tmp = mrt_getintersection_cyl(ray, scene);
	// if (get_intersectionsurface_isnearer(surface, surface_tmp))
	// 	surface = surface_tmp;
	// surface_tmp = mrt_getintersection_tgl(ray, scene);
	// if (get_intersectionsurface_isnearer(surface, surface_tmp))
	// 	surface = surface_tmp;
	return (surface);
}

int					mrt_raytrace_calc_raytrace(t_ray *ray, t_scene *scene)
{
	int			color;
	t_surface	surface;

	surface = findintersection(ray, scene);
	if (surface.dist > 0)
		color = surface.color;
	else
	{
		color = ((t_amblight *)(scene->amblights->content))->color;
		color = mrt_color_apply_brightness(color,
			((t_amblight *)(scene->amblights->content))->ratio);
	}
	return (color);
}
