/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_tgl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 08:57:50 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 13:15:22 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static int		tgl_isintgl(t_tgl *tgl, t_surface surface)
{
	double	vec_apx[3];
	double	vec_a2p[3];
	double	outerprod[3];
	double	iprds[3];

	math_3dvec_minus(tgl->pos2, tgl->pos1, vec_apx);
	math_3dvec_minus(surface.pos, tgl->pos1, vec_a2p);
	math_3dvec_outerprod(vec_a2p, vec_apx, outerprod);
	iprds[0] = math_3dvec_innerprod(outerprod, surface.normvec);
	math_3dvec_minus(tgl->pos3, tgl->pos2, vec_apx);
	math_3dvec_minus(surface.pos, tgl->pos2, vec_a2p);
	math_3dvec_outerprod(vec_a2p, vec_apx, outerprod);
	iprds[1] = math_3dvec_innerprod(outerprod, surface.normvec);
	math_3dvec_minus(tgl->pos1, tgl->pos3, vec_apx);
	math_3dvec_minus(surface.pos, tgl->pos3, vec_a2p);
	math_3dvec_outerprod(vec_a2p, vec_apx, outerprod);
	iprds[2] = math_3dvec_innerprod(outerprod, surface.normvec);
	if ((iprds[0] > MRT_EPS && iprds[1] > MRT_EPS && iprds[2] > MRT_EPS)
		|| (iprds[0] < -MRT_EPS && iprds[1] < -MRT_EPS && iprds[2] < -MRT_EPS))
		return (1);
	return (0);
}

static int	tgl_calc_normvec(t_tgl *tgl, double *normvec)
{
	double	vec_ab[3];
	double	vec_bc[3];
	double	vec_ca[3];

	math_3dvec_minus(tgl->pos2, tgl->pos1, vec_ab);
	math_3dvec_minus(tgl->pos3, tgl->pos2, vec_bc);
	math_3dvec_minus(tgl->pos1, tgl->pos3, vec_ca);
	if (mrt_isineps(math_3dvec_norm(vec_ab))
		|| mrt_isineps(math_3dvec_norm(vec_bc))
		|| mrt_isineps(math_3dvec_norm(vec_ca)))
		return (1);
	math_3dvec_outerprod(vec_ab, vec_ca, normvec);
	math_3dvec_normalize(normvec, normvec);
	return (0);
}

static t_surface	tgl_solve(t_ray *ray, t_tgl *tgl)
{
	t_plane		plane;
	t_surface	surface;

	surface.dist = -1.0;
	if (tgl_calc_normvec(tgl, plane.orien))
		return (surface);
	math_3dvec_applylen(tgl->pos1, 1.0, plane.pos);
	plane.color = tgl->color;
	surface = mrt_findintersection_plane_solve(ray, &plane);
	if (surface.dist < MRT_EPS)
		return (surface);
	if (!tgl_isintgl(tgl, surface))
		surface.dist = -1.0;
	return (surface);
}

t_surface	mrt_findintersection_tgl(t_ray *ray, t_list *tgls)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (tgls)
	{
		surface_tmp = tgl_solve(ray, tgls->content);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		tgls = tgls->next;
	}
	return (surface);
}
