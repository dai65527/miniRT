/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_readfile_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:01:54 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/04 07:23:37 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

const char	*mrt_readfile_readint(const char *line, int *n)
{
	while (ft_isspace(*line))
		line++;
	if (!(ft_isdigit(*line) || *line == '+' || *line == '-'))
		return (NULL);
	*n = ft_atoi(line);
	if (*line == '+' || *line == '-')
		line++;
	while (ft_isdigit(*line))
		line++;
	return (line);
}

const char	*mrt_readfile_readdouble(const char *line, double *n)
{
	while (ft_isspace(*line))
		line++;
	if (!(ft_isdigit(*line) || *line == '+' || *line == '-' || *line == '.'))
		return (NULL);
	*n = ft_atof(line);
	if (*line == '+' || *line == '-')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line == '.')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line == 'e' || *line == 'E')
		line++;
	while (ft_isdigit(*line))
		line++;
	return (line);
}

const char	*mrt_readfile_readvec(const char *line, double *vec)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (!(line = mrt_readfile_readdouble(line, &vec[i])))
			return (NULL);
		if (i < 2)
		{
			while (ft_isspace(*line))
				line++;
			if (*line == ',')
				line++;
		}
		i++;
	}
	return (line);
}

const char	*mrt_readfile_readcolor(const char *line, int *color)
{
	int		i;
	int		tmp;

	i = 0;
	*color = 0;
	while (i < 3)
	{
		if (!(line = mrt_readfile_readint(line, &tmp)))
			return (NULL);
		if (tmp < 0 || tmp > 255)
			return (NULL);
		*color |= (tmp << (i * 8));
		if (i < 2)
		{
			while (ft_isspace(*line))
				line++;
			if (*line == ',')
				line++;
		}
		i++;
	}
	return (line);
}
