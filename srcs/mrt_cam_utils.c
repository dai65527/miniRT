/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cam_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:01:22 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

int			mrt_readfile_storescene_cam(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_cam	*cam;
	t_cam	cam_tmp;

	if (!(line = mrt_readfile_readvec(line, cam_tmp.pos)))
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

int			mrt_readfile_checkscene_cam(t_list *cams)
{
	t_cam	*cam;

	if (ft_lstsize(cams) < 1)
		return (ERR_FILEWRONG);
	while (cams)
	{
		cam = (t_cam *)cams->content;
		if (cam->fov < 0.0 || cam->fov > 180.0)
			return (ERR_FILEWRONG);
		if (mrt_readfile_checknormorien(cam->orien))
			return (ERR_FILEWRONG);
		cams = cams->next;
	}
	return (NOERR);
}
