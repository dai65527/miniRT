/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:13:02 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 12:02:06 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int		main(int argc, char **argv)
{
	int		res;
	int		flg_bmp;
	t_scene	scene;
	t_list	*screens;

	if (argc < 2)
		return (mrt_errend(ERR_ARGCFEW));
	if (argc > 3)
		return (mrt_errend(ERR_ARGCMANY));
	flg_bmp = 0;
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", ft_strlen(argv[2]) + 1))
			flg_bmp = 1;
		else
			return (mrt_errend(ERR_OPT));
	}
	if ((res = mrt_readfile(argv[1], &scene)) != NOERR)
		return (mrt_errend(res));
	if (!(screens = mrt_raytrace(&scene)))
		return (mrt_errend(ERR_MALLOCFAIL));
	if (flg_bmp)
		return (mrt_drawimg_bmp(&scene, screens, argv[1]));
	return (mrt_drawimg_mlx(&scene, screens));
}
