/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_scene_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:37:40 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:30:53 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_initscene(t_scene *scene)
{
	scene->rezs = NULL;
	scene->amblights = NULL;
	scene->cams = NULL;
	scene->lights = NULL;
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->sqrs = NULL;
	scene->cyls = NULL;
	scene->tgls = NULL;
}

void		mrt_freescene(t_scene *scene)
{
	ft_lstclear(&(scene->rezs), free);
	ft_lstclear(&(scene->amblights), free);
	ft_lstclear(&(scene->cams), free);
	ft_lstclear(&(scene->lights), free);
	ft_lstclear(&(scene->spheres), free);
	ft_lstclear(&(scene->planes), free);
	ft_lstclear(&(scene->sqrs), free);
	ft_lstclear(&(scene->cyls), free);
	ft_lstclear(&(scene->tgls), free);
}

void		mrt_printscene(t_scene scene)
{
	ft_printf("resolution:\n");
	ft_lstiter(scene.rezs, mrt_printrez);
	ft_printf("ambient light:\n");
	ft_lstiter(scene.amblights, mrt_printamblight);
	ft_printf("camera:\n");
	ft_lstiter(scene.cams, mrt_printcam);
	ft_printf("light:\n");
	ft_lstiter(scene.lights, mrt_printlight);
	ft_printf("plane:\n");
	ft_lstiter(scene.planes, mrt_printplane);
	ft_printf("sphere:\n");
	ft_lstiter(scene.spheres, mrt_printsphere);
	ft_printf("square:\n");
	ft_lstiter(scene.sqrs, mrt_printsqr);
	ft_printf("cylinder:\n");
	ft_lstiter(scene.cyls, mrt_printcyl);
	ft_printf("triangle:\n");
	ft_lstiter(scene.tgls, mrt_printtgl);
}
