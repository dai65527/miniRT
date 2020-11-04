/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_errend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:40:48 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 07:04:23 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		mrt_errend(int mrt_errno)
{
	(void)mrt_errno;
	ft_putstr_fd("Error\n", FD_STDERR);
	ft_printf("ERROR CODE: %#x\n", mrt_errno);
	return (1);
}
