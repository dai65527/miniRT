/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cam_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:53:17 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printcam(void *cam_pt)
{
	t_cam	*cam;

	cam = (t_cam *)cam_pt;
	ft_printf("view point: [%g, %g, %g]\n",
		cam->point[0], cam->point[1], cam->point[2]);
	ft_printf("orientation: [%g, %g, %g]\n",
		cam->orien[0], cam->orien[1], cam->orien[2]);
	ft_printf("\n");
}

int			mrt_readfile_storescene_cam(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_cam	*cam;
	t_cam	cam_tmp;

	if (!(line = mrt_readfile_readvec(line, cam_tmp.point)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, cam_tmp.orien)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &cam_tmp.fov)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (ERR_MALLOCFAIL);
	*cam = cam_tmp;
	if (!(newlst = ft_lstnew(cam)))
	{
		free(cam);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->cams), newlst);
	return (NOERR);
}
