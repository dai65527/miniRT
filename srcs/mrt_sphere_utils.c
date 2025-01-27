/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_sphere_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:02:36 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

int			mrt_readfile_storescene_sphere(const char *line, t_scene *scene)
{
	t_list		*newlst;
	t_sphere	*sphere;
	t_sphere	sphere_tmp;

	if (!(line = mrt_readfile_readvec(line, sphere_tmp.pos)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &sphere_tmp.dia)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &sphere_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (ERR_MALLOCFAIL);
	*sphere = sphere_tmp;
	if (!(newlst = ft_lstnew(sphere)))
	{
		free(sphere);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->spheres), newlst);
	return (NOERR);
}

int			mrt_readfile_checkscene_sphere(t_list *spheres)
{
	t_sphere	*sphere;

	while (spheres)
	{
		sphere = (t_sphere *)spheres->content;
		if (sphere->dia < 0.0)
			return (ERR_FILEWRONG);
		spheres = spheres->next;
	}
	return (NOERR);
}
