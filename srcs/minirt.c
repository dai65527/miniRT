/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:13:02 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/31 20:36:51 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_data	data;

	(void)data;
	if (argc != 2 && argc != 3)
		return (mrt_errend(ERR_ARGC));
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
		g_flgs |= FLG_BMP;
	// if (mrt_readfile(argv[2], &data))
	// 	return (mrt_errend(ERR_READ));
	return (0);
}
