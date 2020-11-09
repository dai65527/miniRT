/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:27:12 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 16:41:50 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_surface	mrt_findintersection(t_ray *ray, t_scene *scene)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	surface_tmp = mrt_findintersection_sphere(ray, scene->spheres);
	if (mrt_surface_isnearer(surface, surface_tmp))
		surface = surface_tmp;
	surface_tmp = mrt_findintersection_plane(ray, scene->planes);
	if (mrt_surface_isnearer(surface, surface_tmp))
		surface = surface_tmp;
	surface_tmp = mrt_findintersection_sqr(ray, scene->sqrs);
	if (mrt_surface_isnearer(surface, surface_tmp))
		surface = surface_tmp;
	surface_tmp = mrt_findintersection_cyl(ray, scene->cyls);
	if (mrt_surface_isnearer(surface, surface_tmp))
		surface = surface_tmp;
	surface_tmp = mrt_findintersection_tgl(ray, scene->tgls);
	if (mrt_surface_isnearer(surface, surface_tmp))
		surface = surface_tmp;
	return (surface);
}
