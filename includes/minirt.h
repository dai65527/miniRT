/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:13:19 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/31 19:55:21 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define FLG_BMP	1

# define ERR_ARGC	1

int				g_flgs;
int				g_errno;

typedef struct	s_data
{
	int			res[2];
}				t_data;

int			mrt_errend(int mrt_errno);

#endif
