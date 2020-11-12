/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_sqr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:04:41 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 09:08:05 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

int			mrt_readfile_storescene_sqr(const char *line, t_scene *scene)
{
	t_list	*newlst;
	t_sqr	*sqr;
	t_sqr	sqr_tmp;

	if (!(line = mrt_readfile_readvec(line, sqr_tmp.pos)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readvec(line, sqr_tmp.orien)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readdouble(line, &sqr_tmp.size)))
		return (ERR_FILEWRONG);
	if (!(line = mrt_readfile_readcolor(line, &sqr_tmp.color)))
		return (ERR_FILEWRONG);
	if (mrt_readfile_checkendl(line))
		return (ERR_FILEWRONG);
	if (!(sqr = (t_sqr *)malloc(sizeof(t_sqr))))
		return (ERR_MALLOCFAIL);
	*sqr = sqr_tmp;
	if (!(newlst = ft_lstnew(sqr)))
	{
		free(sqr);
		return (ERR_MALLOCFAIL);
	}
	ft_lstadd_back(&(scene->sqrs), newlst);
	return (NOERR);
}

int			mrt_readfile_checkscene_sqr(t_list *sqrs)
{
	t_sqr	*sqr;

	while (sqrs)
	{
		sqr = (t_sqr *)sqrs->content;
		if (mrt_readfile_checknormorien(sqr->orien))
			return (ERR_FILEWRONG);
		if (sqr->size < 0.0)
			return (ERR_FILEWRONG);
		sqrs = sqrs->next;
	}
	return (NOERR);
}
