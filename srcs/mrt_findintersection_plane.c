/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_plane.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:52:32 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 13:46:10 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

t_surface			mrt_findintersection_plane_solve(t_ray *ray, t_plane *plane)
{
	t_surface	surface;
	double		innerprod_tmp;
	double		vec_tmp[3];

	surface.dist = -1.0;
	innerprod_tmp = math_vec3_innerprod(ray->dir, plane->orien);
	if (mrt_isineps(innerprod_tmp))
		return (surface);
	else if (innerprod_tmp < 0.0)
		math_vec3_applylen(plane->orien, 1.0, surface.normvec);
	else
		math_vec3_applylen(plane->orien, -1.0, surface.normvec);
	math_vec3_minus(plane->pos, ray->orig, vec_tmp);
	surface.dist = math_vec3_innerprod(vec_tmp, plane->orien) / innerprod_tmp;
	math_vec3_applylen(ray->dir, surface.dist, vec_tmp);
	math_vec3_plus(ray->orig, vec_tmp, surface.pos);
	surface.color = plane->color;
	return (surface);
}

t_surface			mrt_findintersection_plane(t_ray *ray, t_list *planes)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (planes)
	{
		surface_tmp = mrt_findintersection_plane_solve(ray, planes->content);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		planes = planes->next;
	}
	return (surface);
}
