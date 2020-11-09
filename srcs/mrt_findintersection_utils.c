/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:08:47 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 13:13:43 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
