/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_findintersection_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:08:47 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/08 14:45:14 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			mrt_isinepsilon(double var)
{
	return (-MRT_EPSIRON <= var && var <= MRT_EPSIRON);
}

int			mrt_surface_isnearer(t_surface old, t_surface new)
{
	if (new.dist <= MRT_EPSIRON)
		return (0);
	return (old.dist <= MRT_EPSIRON || new.dist < old.dist);
}
