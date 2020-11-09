/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_raytrace_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:00:04 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 13:13:43 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_utils.h"
#include "minirt.h"

static void	calc_screen_unitvecdist(t_screen *screen)
{
	double	tmp;

	if (mrt_isineps(screen->cam.orien[0]) && mrt_isineps(screen->cam.orien[1]))
	{
		screen->unitvec_x[0] = 1.0;
		screen->unitvec_x[1] = 0.0;
	}
	else
	{
		tmp = sqrt(screen->cam.orien[0] * screen->cam.orien[0]
					+ screen->cam.orien[1] * screen->cam.orien[1]);
		screen->unitvec_x[0] = -screen->cam.orien[1] / tmp;
		screen->unitvec_x[1] = screen->cam.orien[0] / tmp;
	}
	screen->unitvec_x[2] = 0.0;
	math_3dvec_outerprod(screen->unitvec_x, screen->cam.orien,
							screen->unitvec_y);
	screen->dist = screen->rez.x / tan(screen->cam.fov * M_PI / 180.0 / 2.0);
}

static void	calc_ray_to_screenpx(t_ray *ray, t_screen *screen, int i, int j)
{
	double	vec[3];

	math_3dvec_applylen(screen->cam.orien, screen->dist, vec);
	vec[0] -= ((double)i - (double)screen->rez.x / 2.0) * screen->unitvec_x[0];
	vec[1] -= ((double)i - (double)screen->rez.x / 2.0) * screen->unitvec_x[1];
	vec[2] -= ((double)i - (double)screen->rez.x / 2.0) * screen->unitvec_x[2];
	vec[0] += ((double)j - (double)screen->rez.y / 2.0) * screen->unitvec_y[0];
	vec[1] += ((double)j - (double)screen->rez.y / 2.0) * screen->unitvec_y[1];
	vec[2] += ((double)j - (double)screen->rez.y / 2.0) * screen->unitvec_y[2];
	math_3dvec_normalize(vec, ray->dir);
}

static int	calc_screencolor(t_ray *ray, t_scene *scene)
{
	int			color;
	t_surface	surface;

	surface = mrt_findintersection(ray, scene);
	if (surface.dist > MRT_EPS)
	{
		color = mrt_raytrace_calc_reflect(ray, &surface, scene);
	}
	else
	{
		color = ((t_amblight *)(scene->amblights->content))->color;
		color = mrt_color_apply_brightness(color,
			((t_amblight *)(scene->amblights->content))->ratio);
	}
	return (color);
}

int			mrt_raytrace_calc(t_scene *scene, t_screen *screen)
{
	int		i;
	int		j;
	t_ray	ray;

	ray.orig = screen->cam.pos;
	calc_screen_unitvecdist(screen);
	i = 0;
	while (i < screen->rez.x)
	{
		j = 0;
		while (j < screen->rez.y)
		{
			// ft_printf("[%d,%d]: ", i, j);
			calc_ray_to_screenpx(&ray, screen, i, j);
			screen->px[i][j] = calc_screencolor(&ray, scene);
			j++;
			// ft_printf("\n");
		}
		i++;
	}
	return (NOERR);
}
