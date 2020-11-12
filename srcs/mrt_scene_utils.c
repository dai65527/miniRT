/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_scene_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:37:40 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:03:05 by dnakano          ###   ########.fr       */
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
