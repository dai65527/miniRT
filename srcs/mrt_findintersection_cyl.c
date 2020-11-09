/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_cyl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:29:11 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 20:35:05 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static void			cyl_calc_dist_abcd(t_ray *ray, t_cyl *cyl, double *abcd)
{
	double	vec_sc[3];
	double	oprd_dn[3];
	double	oprd_scn[3];

	math_3dvec_minus(ray->orig, cyl->pos, vec_sc);
	math_3dvec_outerprod(ray->dir, cyl->orien, oprd_dn);
	math_3dvec_outerprod(vec_sc, cyl->orien, oprd_scn);
	abcd[0] = math_3dvec_innerprod(oprd_dn, oprd_dn);
	abcd[1] = 2.0 * math_3dvec_innerprod(oprd_dn, oprd_scn);
	abcd[2] = math_3dvec_innerprod(oprd_scn, oprd_scn)
				- cyl->dia * cyl->dia / 4.0;
	abcd[3] = abcd[1] * abcd[1] - 4.0 * abcd[0] * abcd[2];
}

static int			cyl_calc_normvec(t_surface *surface, t_ray *ray, t_cyl *cyl)
{
	double		vec_c2s[3];
	double		iprd_c2s_n;

	mrt_surface_calcpos_from_dirdist(surface, ray);
	math_3dvec_minus(surface->pos, cyl->pos, vec_c2s);
	iprd_c2s_n = math_3dvec_innerprod(vec_c2s, cyl->orien);
	if (iprd_c2s_n < -MRT_EPS || iprd_c2s_n > cyl->hei)
		return (1);
	math_3dvec_applylen(cyl->orien, iprd_c2s_n, surface->normvec);
	math_3dvec_minus(vec_c2s, surface->normvec, surface->normvec);
	math_3dvec_normalize(surface->normvec, surface->normvec);
	return (0);
}

static t_surface	cyl_solve(t_ray *ray, t_cyl *cyl)
{
	double		abcd[4];
	t_surface	surface;

	surface.dist = -1.0;
	cyl_calc_dist_abcd(ray, cyl, abcd);
	if (abcd[3] < -MRT_EPS)
		return (surface);
	surface.color = cyl->color;
	if ((surface.dist = (-abcd[1] - sqrt(abcd[3])) / (2.0 * abcd[0])) > MRT_EPS)
	{
		if (!cyl_calc_normvec(&surface, ray, cyl))
			return (surface);
	}
	if ((surface.dist = (-abcd[1] + sqrt(abcd[3])) / (2.0 * abcd[0])) > MRT_EPS)
	{
		if (!cyl_calc_normvec(&surface, ray, cyl))
			math_3dvec_applylen(surface.normvec, -1.0, surface.normvec);
		else
			surface.dist = -1.0;
	}
	return (surface);
}

t_surface			mrt_findintersection_cyl(t_ray *ray, t_list *cyls)
{
	t_surface	surface;
	t_surface	surface_tmp;

	surface.dist = -1.0;
	while (cyls)
	{
		surface_tmp = cyl_solve(ray, cyls->content);
		if (mrt_surface_isnearer(surface, surface_tmp))
			surface = surface_tmp;
		cyls = cyls->next;
	}
	return (surface);
}
