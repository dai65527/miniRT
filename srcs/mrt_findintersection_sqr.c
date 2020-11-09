/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_sqr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 08:57:50 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 10:26:03 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static int		sqr_isinsqr(t_sqr *sqr, t_surface surface)
{
	double		vec_cp[3];
	double		unitvec_x[3];
	double		unitvec_y[3];
	double		tmp;

	math_3dvec_minus(surface.pos, sqr->pos, vec_cp);
	if (mrt_isinepsilon(surface.normvec[0])
		&& mrt_isinepsilon(surface.normvec[1]))
	{
		unitvec_x[0] = 1.0;
		unitvec_x[1] = 0.0;
	}
	else
	{
		tmp = sqrt(surface.normvec[0] * surface.normvec[0]
				+ surface.normvec[1] * surface.normvec[1]);
		unitvec_x[0] = surface.normvec[1] / tmp;
		unitvec_x[1] = -surface.normvec[0] / tmp;
	}
	unitvec_x[2] = 0.0;
	math_3dvec_outerprod(surface.normvec, unitvec_x, unitvec_y);
	return (math_absd(math_3dvec_innerprod(vec_cp, unitvec_x)) <= sqr->size / 2
	&& math_absd(math_3dvec_innerprod(vec_cp, unitvec_y)) <= sqr->size / 2);
}

static t_surface	sqr_solve(t_ray *ray, t_sqr *sqr)
{
	t_plane		plane;
	t_surface	surface;

	math_3dvec_applylen(sqr->orien, 1.0, plane.orien);
	math_3dvec_applylen(sqr->pos, 1.0, plane.pos);
	plane.color = sqr->color;
	surface = mrt_findintersection_plane_solve(ray, &plane);
	if (surface.dist < MRT_EPSIRON)
		return (surface);
	if (!sqr_isinsqr(sqr, surface))
		surface.dist = -1.0;
	return (surface);
}

t_surface	mrt_findintersection_sqr(t_ray *ray, t_list *sqrs)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (sqrs)
	{
		surface_tmp = sqr_solve(ray, sqrs->content);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		sqrs = sqrs->next;
	}
	return (surface);
}
