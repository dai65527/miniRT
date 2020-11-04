/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_readfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:31:10 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 09:23:09 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "minirt.h"

int			mrt_readfile(const char *path, t_scene *scene)
{
	int		fd;
	int		res_gnl;
	int		res_scene;
	char	*line;

	line = NULL;
	mrt_initscene(scene);
	if (!mrt_readfile_isrt(path))
		return (ERR_FILETYPE);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (ERR_FILEOPEN);
	while ((res_gnl = get_next_line(fd, &line)) >= 0)
	{
		if ((res_scene = mrt_readfile_storescene(line, scene)) != NOERR)
			return (mrt_readfile_errend(res_scene, scene, line, fd));
		free(line);
		if (!res_gnl)
		{
			close(fd);
			return (NOERR);
		}
	}
	return (mrt_readfile_errend(ERR_FILEREAD, scene, NULL, fd));
}
