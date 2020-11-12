/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_errend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:40:48 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 12:00:32 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static void	errend_printinfo_0(int mrt_errno)
{
	if (mrt_errno == ERR_ARGCFEW)
		ft_putstr_fd("Too few arguments. (", FD_STDERR);
	else if (mrt_errno == ERR_ARGCMANY)
		ft_putstr_fd("Too many arguments. (", FD_STDERR);
	else if (mrt_errno == ERR_OPT)
		ft_putstr_fd("Wrong option. Only --save is available. (", FD_STDERR);
	else if (mrt_errno == ERR_MALLOCFAIL)
		ft_putstr_fd("Failed in memory allocation (", FD_STDERR);
}

static void	errend_printinfo_1(int mrt_errno)
{
	if (mrt_errno == ERR_FILETYPE)
		ft_putstr_fd("File name invalid. Need \".rt\" extaition (", FD_STDERR);
	else if (mrt_errno == ERR_FILEOPEN)
		ft_putstr_fd("Failed to open file (", FD_STDERR);
	else if (mrt_errno == ERR_FILEWRONG)
		ft_putstr_fd("Invalid rt file (", FD_STDERR);
}

static void	errend_printinfo_2(int mrt_errno)
{
	if (mrt_errno == ERR_MLXINIT)
		ft_putstr_fd("Falied to initialize minilibx (", FD_STDERR);
	else if (mrt_errno == ERR_MLXIMG)
		ft_putstr_fd("Falied to create minilbx images (", FD_STDERR);
	else if (mrt_errno == ERR_MLXLOOP)
		ft_putstr_fd("Problem in minilibx loop (", FD_STDERR);
}

static void	errend_printinfo_3(int mrt_errno)
{
	if (mrt_errno == ERR_BMPOPEN)
		ft_putstr_fd("Failed to open/create bmp file (", FD_STDERR);
	else if (mrt_errno == ERR_FNTOOLONG)
		ft_putstr_fd("Bmp file path too long (", FD_STDERR);
	else if (mrt_errno == ERR_FILEWRITE)
		ft_putstr_fd("Failed to write to bmp file (", FD_STDERR);
}

int			mrt_errend(int mrt_errno)
{
	ft_putstr_fd("Error\n", FD_STDERR);
	if (mrt_errno < ERR_FILETYPE)
		errend_printinfo_0(mrt_errno);
	else if (mrt_errno < ERR_MLXINIT)
		errend_printinfo_1(mrt_errno);
	else if (mrt_errno < ERR_BMPOPEN)
		errend_printinfo_2(mrt_errno);
	else
		errend_printinfo_3(mrt_errno);
	ft_putnbr_fd(mrt_errno, FD_STDERR);
	ft_putstr_fd(")\n", FD_STDERR);
	return (1);
}
