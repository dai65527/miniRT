/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_tgl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 10:34:53 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

void		mrt_printtgl(void *tgl_pt)
{
	t_tgl	*tgl;

	tgl = (t_tgl *)tgl_pt;
	ft_printf("first point: [%g, %g, %g]\n",
		tgl->pos1[0], tgl->pos1[1], tgl->pos1[2]);
	ft_printf("second point: [%g, %g, %g]\n",
		tgl->pos2[0], tgl->pos2[1], tgl->pos2[2]);
	ft_printf("third point: [%g, %g, %g]\n",
		tgl->pos3[0], tgl->pos3[1], tgl->pos3[2]);
	ft_printf("color: %d\n", tgl->color);
	ft_printf("\n");
}

int			mrt_readfile_storescene_tgl(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_tgl	*tgl;
	t_tgl	tgl_tmp;

	if (!(line = mrt_readfile_readvec(line, tgl_tmp.pos1)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, tgl_tmp.pos2)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, tgl_tmp.pos3)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &tgl_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(tgl = (t_tgl *)malloc(sizeof(t_tgl))))
		return (ERR_MALLOCFAIL);
	*tgl = tgl_tmp;
	if (!(newlst = ft_lstnew(tgl)))
	{
		free(tgl);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->tgls), newlst);
	return (NOERR);
}
