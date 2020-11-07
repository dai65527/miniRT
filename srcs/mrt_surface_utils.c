/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_surface_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:30:51 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/07 20:39:01 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		mrt_surface_isnearer(t_surface old, t_surface new)
{
	if (new.dist <= 0.0)
		return (0);
	return (old.dist <= 0.0 || new.dist < old.dist);
}
