/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_abs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:19:18 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 09:28:25 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		math_absi(int intnbr)
{
	return (intnbr < 0 ? -intnbr : intnbr);
}

long	math_absl(long longnbr)
{
	return (longnbr < 0 ? -longnbr : longnbr);
}

float	math_absf(float floatnbr)
{
	return (floatnbr < 0 ? -floatnbr : floatnbr);
}

double	math_absd(double doublenbr)
{
	return (doublenbr < 0 ? -doublenbr : doublenbr);
}
