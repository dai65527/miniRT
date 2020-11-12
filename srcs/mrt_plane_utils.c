/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_plane_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:02:44 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

int			mrt_readfile_storescene_plane(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_plane	*plane;
	t_plane	plane_tmp;

	if (!(line = mrt_readfile_readvec(line, plane_tmp.pos)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, plane_tmp.orien)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &plane_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return (ERR_MALLOCFAIL);
	*plane = plane_tmp;
	if (!(newlst = ft_lstnew(plane)))
	{
		free(plane);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->planes), newlst);
	return (NOERR);
}

int			mrt_readfile_checkscene_plane(t_list *planes)
{
	t_plane	*plane;

	while (planes)
	{
		plane = (t_plane *)planes->content;
		if (mrt_readfile_checknormorien(plane->orien))
			return (ERR_FILEWRONG);
		planes = planes->next;
	}
	return (NOERR);
}
