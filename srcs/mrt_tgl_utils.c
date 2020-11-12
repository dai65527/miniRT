/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_tgl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:02:18 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

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

/*
** nothing to check.
*/

int			mrt_readfile_checkscene_tgl(t_list *tgls)
{
	(void)tgls;
	return (NOERR);
}
