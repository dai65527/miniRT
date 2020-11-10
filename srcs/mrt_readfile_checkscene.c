/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_readfile_checkscene.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:13:46 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/10 11:16:47 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

int			mrt_readfile_checkscene(t_scene *scene)
{
	int		res;

	if ((res = mrt_readfile_checkscene_rez(scene->rezs)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_amblight(scene->amblights)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_cam(scene->cams)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_light(scene->lights)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_sphere(scene->spheres)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_plane(scene->planes)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_sqr(scene->sqrs)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_cyl(scene->cyls)) != NOERR)
		return (res);
	if ((res = mrt_readfile_checkscene_tgl(scene->tgls)) != NOERR)
		return (res);
	return (NOERR);
}

int		mrt_readfile_checkratio(double ratio)	
{
	return (ratio < 0.0 || ratio > 1.0);
}

int		mrt_readfile_checknormorien(double *vec)
{
	int		i;
	double	len;

	if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0)
		return (1);
	len = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	i = 0;
	while (i < 3)
	{
		if (vec[i] < -1 || vec[i] > 1)
			return (1);
		vec[i] = vec[i] / len;
		i++;
	}
	return (0);
}
