/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:08:47 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 08:49:09 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "math_utils.h"

int			mrt_isineps(double var)
{
	return (-MRT_EPS <= var && var <= MRT_EPS);
}

int			mrt_surface_isnearer(t_surface old, t_surface new)
{
	if (new.dist <= MRT_EPS)
		return (0);
	return (old.dist <= MRT_EPS || new.dist < old.dist);
}

void	mrt_surface_calcpos_from_dirdist(t_surface *surface, t_ray *ray)
{
	double	vec[3];

	math_vec3_applylen(ray->dir, surface->dist, vec);
	math_vec3_plus(ray->orig, vec, surface->pos);
}
