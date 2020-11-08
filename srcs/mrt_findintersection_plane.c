/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_plane.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:52:32 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/08 18:25:09 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static t_surface	plane_solve(t_ray *ray, t_plane *plane)
{
	t_surface	surface;
	double		innerprod_tmp;
	double		vec_tmp[3];

	surface.dist = -1.0;
	innerprod_tmp = math_3dvec_innerprod(ray->dir, plane->orien);	
	if (mrt_isinepsilon(innerprod_tmp))
		return (surface);
	else if (innerprod_tmp < 0.0)
		math_3dvec_applylen(plane->orien, 1.0, surface.normvec);
	else
		math_3dvec_applylen(plane->orien, -1.0, surface.normvec);
	math_3dvec_minus(plane->pos, ray->orig, vec_tmp);
	surface.dist = math_3dvec_innerprod(vec_tmp, plane->orien) / innerprod_tmp;
	math_3dvec_applylen(ray->dir, surface.dist, vec_tmp);
	math_3dvec_plus(ray->orig, vec_tmp, surface.pos);
	surface.color = plane->color;
	return (surface);
}

t_surface	mrt_findintersection_plane(t_ray *ray, t_list *planes)
{
	t_plane		*plane;
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (planes)
	{
		plane = (t_plane *)planes->content;
		surface_tmp = plane_solve(ray, plane);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		planes = planes->next;
	}
	return (surface);
}
