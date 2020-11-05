/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:13:02 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/05 11:30:54 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int		main(int argc, char **argv)
{
	int		res;
	t_scene	scene;

	if (argc != 2 && argc != 3)
		return (mrt_errend(ERR_ARGC));
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2]) + 1))
		g_flgs |= FLG_BMP;
	else if (argc == 3)
		return (mrt_errend(ERR_ARGC));
	if ((res = mrt_readfile(argv[1], &scene)) != NOERR)
		return (mrt_errend(res));
	mrt_printscene(scene);
	res = mrt_renderscene(&scene);
	return (res);
}
