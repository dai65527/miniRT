/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:16:58 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/09 09:28:42 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

void		math_3dvec_applylen(double *vec, double len, double *ans);
void		math_3dvec_plus(double *a, double *b, double *ans);
void		math_3dvec_minus(double *a, double *b, double *ans);
double		math_3dvec_norm(double *vec);
void		math_3dvec_normalize(double *vec, double *normalizedvec);
double		math_3dvec_innerprod(double *a, double *b);
void		math_3dvec_outerprod(double *a, double *b, double *ans);

int	    	math_absi(int intnbr);
long    	math_absl(long longnbr);
float   	math_absf(float floatnbr);
double  	math_absd(double doublenbr);

#endif
