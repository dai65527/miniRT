/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_readfile_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:51:54 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 07:18:08 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "minirt.h"

int			mrt_readfile_isrt(const char *path)
{
	int		len;

	len = ft_strlen(path);
	if (len < 3)
		return (0);
	return (!ft_strncmp(path + len - 3, ".rt", 3));
}

int			mrt_readfile_checkendl(const char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line != '\0')
		return (1);
	return (NOERR);
}

int			mrt_readfile_errend(int err, t_scene *scene, char *line, int fd)
{
	mrt_freescene(scene);
	free(line);
	get_next_line(fd, NULL);
	close(fd);
	return (err);
}
