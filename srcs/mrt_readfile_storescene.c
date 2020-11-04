/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_readfile_storescene.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:13:56 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 09:23:44 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int			mrt_readfile_storescene(const char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (!(*line))
		return (NOERR);
	else if (!ft_strncmp(line, "pl", 2))
		return (mrt_readfile_storescene_plane(line + 2, scene));
	else if (!ft_strncmp(line, "sp", 2))
		return (mrt_readfile_storescene_sphere(line + 2, scene));
	else if (!ft_strncmp(line, "sq", 2))
		return (mrt_readfile_storescene_sqr(line + 2, scene));
	else if (!ft_strncmp(line, "cy", 2))
		return (mrt_readfile_storescene_cyl(line + 2, scene));
	else if (!ft_strncmp(line, "tr", 2))
		return (mrt_readfile_storescene_tgl(line + 2, scene));
	else if (!ft_strncmp(line, "R", 1))
		return (mrt_readfile_storescene_rez(line + 1, scene));
	else if (!ft_strncmp(line, "A", 1))
		return (mrt_readfile_storescene_amblight(line + 1, scene));
	else if (!ft_strncmp(line, "c", 1))
		return (mrt_readfile_storescene_cam(line + 1, scene));
	else if (!ft_strncmp(line, "l", 1))
		return (mrt_readfile_storescene_light(line + 1, scene));
	return (ERR_FILEWRONG);
}
