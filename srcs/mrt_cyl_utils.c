/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cyl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:01:35 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

static int	free_and_return(t_cyl *cyl, int mrt_errno)
{
	free(cyl);
	return (mrt_errno);
}

int			mrt_readfile_storescene_cyl(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_cyl	*cyl;
	t_cyl	cyl_tmp;

	if (!(line = mrt_readfile_readvec(line, cyl_tmp.pos)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, cyl_tmp.orien)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &cyl_tmp.dia)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &cyl_tmp.hei)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &cyl_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (ERR_MALLOCFAIL);
	*cyl = cyl_tmp;
	if (!(newlst = ft_lstnew(cyl)))
		return (free_and_return(cyl, ERR_MALLOCFAIL));
	ft_lstadd_back(&(scene->cyls), newlst);
	return (NOERR);
}

int			mrt_readfile_checkscene_cyl(t_list *cyls)
{
	t_cyl	*cyl;

	while (cyls)
	{
		cyl = (t_cyl *)cyls->content;
		if (mrt_readfile_checknormorien(cyl->orien))
			return (ERR_FILEWRONG);
		if (cyl->dia < 0.0)
			return (ERR_FILEWRONG);
		if (cyl->hei < 0.0)
			return (ERR_FILEWRONG);
		cyls = cyls->next;
	}
	return (NOERR);
}
