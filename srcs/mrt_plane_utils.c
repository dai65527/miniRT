/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_plane_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:34:04 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printplane(void *plane_pt)
{
	t_plane	*plane;

	plane = (t_plane *)plane_pt;
	ft_printf("coordinates: [%g, %g, %g]\n",
		plane->pos[0], plane->pos[1], plane->pos[2]);
	ft_printf("orientation: [%g, %g, %g]\n",
		plane->orien[0], plane->orien[1], plane->orien[2]);
	ft_printf("color: %d\n", plane->color);
	ft_printf("\n");
}

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
