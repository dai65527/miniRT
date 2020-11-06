/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:00:04 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/06 20:02:13 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static void	calc_screen_unitvec(t_screen *screen)
{
	double	tmp;

	if (!screen->cam.orien[0] && !screen->cam.orien[1])
	{
		screen->unitvec_x[0] = 1.0;
		screen->unitvec_x[1] = 0.0;
	}
	else
	{
		tmp = screen->cam.orien[0] * screen->cam.orien[0];
		tmp += screen->cam.orien[1] * screen->cam.orien[1];
		tmp = sqrt(tmp);
		screen->unitvec_x[0] = screen->cam.orien[1] / tmp;
		screen->unitvec_x[1] = screen->cam.orien[0] / tmp;
	}
	screen->unitvec_x[2] = 0.0;
	math_3dvec_outerprod(screen->unitvec_x, screen->cam.orien,
							screen->unitvec_y);
	screen->dist = tan(screen->cam.fov * M_PI / 180.0 / 2.0);
	screen->dist = screen->rez.x / screen->dist;
}

void		calc_ray_to_screenpx(t_ray *ray, t_screen *screen, int i, int j)
{
	double	vec[3];

	vec[0] = screen->dist * screen->cam.orien[0];
	vec[1] = screen->dist * screen->cam.orien[1];
	vec[2] = screen->dist * screen->cam.orien[2];
	vec[0] += ((double)i - (double)screen->rez.x / 2.0) * screen->unitvec_x[0];
	vec[1] += ((double)i - (double)screen->rez.x / 2.0) * screen->unitvec_x[1];
	vec[2] += ((double)i - (double)screen->rez.x / 2.0) * screen->unitvec_x[2];
	vec[0] -= ((double)j - (double)screen->rez.y / 2.0) * screen->unitvec_y[0];
	vec[1] -= ((double)j - (double)screen->rez.y / 2.0) * screen->unitvec_y[1];
	vec[2] -= ((double)j - (double)screen->rez.y / 2.0) * screen->unitvec_y[2];
	math_3dvec_normalize(vec, ray->dir);
}

int			mrt_raytrace_calc(t_scene *scene, t_screen *screen)
{
	int		i;
	int		j;
	double	dist_cam_to_screen;
	t_ray	ray;

	ray.orig = screen->cam.pos;
	calc_screen_unitvec(screen);
	i = 0;
	while (i < screen->rez.x)
	{
		j = 0;
		while (j < screen->rez.y)
		{
			calc_ray_to_screenpx(&ray, &screen, i, j);
			screen->px = mrt_raytrace_calc_raytrace(ray, scene);
			j++;
		}
		i++;
	}
}
