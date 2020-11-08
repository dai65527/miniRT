/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:27:12 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/08 11:51:51 by dnakano          ###   ########.fr       */
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
