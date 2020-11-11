/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_drawimg_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 07:15:48 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/11 17:00:34 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "minirt.h"

static int	bmp_getfilename(char *bmpfn, const char *rtfn, int index)
{
	int		bmpfnlen;
	int		rtfnlen;
	char	*index_suffix;

	rtfnlen = ft_strlen(rtfn);
	if (!(index_suffix = ft_itoa(index)))
		return (ERR_MALLOCFAIL);
	bmpfnlen = rtfnlen - 1;
	if (index != 0)
		bmpfnlen += ft_strlen(index_suffix) + 1;
	if (bmpfnlen + 1 >= MRT_FILEPATHMAX)
		return (ERR_FNTOOLONG);
	ft_strlcpy(bmpfn, rtfn, rtfnlen - 2);
	if (index > 0)
	{
		ft_strlcat(bmpfn, "_", MRT_FILEPATHMAX);
		ft_strlcat(bmpfn, index_suffix, MRT_FILEPATHMAX);
	}
	ft_strlcat(bmpfn, ".bmp", MRT_FILEPATHMAX);
	free(index_suffix);
	return (NOERR);
}

int			mrt_drawimg_bmp(t_scene *scene, t_list *screens,
				const char *rtfilename)
{
	int		index;
	int		res;
	int		fd;
	char	bmpfilename[MRT_FILEPATHMAX];
	t_list	*screens_head;

	screens_head = screens;
	index = 0;
	while (screens)
	{
		if ((res = bmp_getfilename(bmpfilename, rtfilename, index)) != NOERR)
			return (mrt_drawimg_errend(res, scene, screens_head));
		fd = open(bmpfilename, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
		if (fd < 0)
			return (mrt_drawimg_errend(ERR_BMPOPEN, scene, screens_head));
		res = mrt_drawimg_bmp_write(fd, screens->content);
		close(fd);
		if (res != NOERR)
			return (mrt_drawimg_errend(ERR_BMPOPEN, scene, screens_head));
		index++;
		screens = screens->next;
	}
	mrt_freescene(scene);
	mrt_freescreens(screens);
	return (NOERR);
}
