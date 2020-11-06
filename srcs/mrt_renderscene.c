/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_renderscene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:17:18 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 12:06:23 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	renderscene_errend(int mrt_errno, t_scene *scene, t_list *screens)
{
	mrt_freescreens(screens);
	mrt_freescene(scene);
	return (mrt_errno);
}

/*
** this function never returns unless any errors occur.
*/

int			mrt_renderscene(t_scene *scene)
{
	int			res;
	t_list		*screens;

	if ((res = mrt_mallocscreens(scene, &screens)) != NOERR)
		return (renderscene_errend(res, scene, NULL));
	if ((res = mrt_raytrace(scene, screens)) != NOERR)
		return (renderscene_errend(res, scene, screens));
	// if (g_flgs & FLG_BMP)
	// {
	// 	if ((res = mrt_renderscene_bmp(scene, screens)) != NOERR)
	// 		return (res);
	// }
	return (mrt_renderscene_mlx(scene, screens));
}
