/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_drawimg_bmp_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:06:18 by dnakano           #+#    #+#             */
/*   Updated: 2020/11/12 12:01:22 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "minirt.h"

/*
**	WRITE FILEHEADER (14bytes in total)
**
** filetype	(2bytes) =	"BM" (unique for bmp file)
** filesize	(2bytes) =	imgsize (whole size of bmpfile in byte)
** reserved	(4bytes) =	0 (not used)
** offbits	(4bytes) :	BMP_FILEHEADERSIZE + BMP_INFOHEADERSIZE
**						(offset from file head to imagedata begens in byte)
*/

static int	bmp_write_fileheader(int fd, uint32_t imgsize)
{
	int			writtenbytes;
	uint32_t	tmp4byte;

	writtenbytes = write(fd, "BM", 2);
	tmp4byte = imgsize + BMP_FILEHEADERSIZE + BMP_INFOHEADERSIZE;
	writtenbytes += write(fd, &tmp4byte, 4);
	tmp4byte = 0;
	writtenbytes += write(fd, &tmp4byte, 4);
	tmp4byte = BMP_FILEHEADERSIZE + BMP_INFOHEADERSIZE;
	writtenbytes += write(fd, &tmp4byte, 4);
	if (writtenbytes != BMP_FILEHEADERSIZE)
		return (ERR_FILEWRITE);
	return (NOERR);
}

/*
**	WRITE INFOHEADER (40bytes in total)
**
** headersize	(4bytes) =	BMP_INFOHEADERSIZE (=40, windows bitmapinfoheader)
** imagewidth	(4bytes) =	imgwidth
** imageheight	(4bytes) =	imgheight
** planes		(2bytes) =	0 (number of planes, usually 0)
** bitcount		(2bytes) =	32 (bit count of color, for now 32bit color used)
** compression	(4bytes) =	0 (no compression)
** sizeimage	(4bytes) =	imgsize (size of image data in bytes)
** pixpermeterX	(4bytes) =	3780 (for 96dpi, differ depends on system)
** pixpermeterY	(4bytes) =	3780 (for 96dpi, differ depends on system)
** color used	(4bytes) =	0 (number of color pallets. 0 for 32 bit color)
** color imp.	(4bytes) =	0 (number of important color. 0 for now)
*/

static int	bmp_write_infoheader(int fd, uint32_t imgsize,
				int32_t imgwidth, int32_t imgheight)
{
	int			writtenbytes;
	uint16_t	tmp2byte;
	uint32_t	tmp4byte;

	tmp4byte = BMP_INFOHEADERSIZE;
	writtenbytes = write(fd, &tmp4byte, 4);
	writtenbytes += write(fd, &imgwidth, 4);
	writtenbytes += write(fd, &imgheight, 4);
	tmp2byte = 1;
	writtenbytes += write(fd, &tmp2byte, 2);
	tmp2byte = 32;
	writtenbytes += write(fd, &tmp2byte, 2);
	tmp4byte = 0;
	writtenbytes += write(fd, &tmp4byte, 4);
	writtenbytes += write(fd, &imgsize, 4);
	tmp4byte = 3780;
	writtenbytes += write(fd, &tmp4byte, 4);
	writtenbytes += write(fd, &tmp4byte, 4);
	tmp4byte = 0;
	writtenbytes += write(fd, &tmp4byte, 4);
	writtenbytes += write(fd, &tmp4byte, 4);
	if (writtenbytes != BMP_INFOHEADERSIZE)
		return (ERR_FILEWRITE);
	return (NOERR);
}

static int	bmp_write_image(int fd, t_screen *screen)
{
	int		writtenbytes;
	int		i;
	int		j;

	writtenbytes = 0;
	j = screen->rez.y - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < screen->rez.x)
		{
			writtenbytes += write(fd, &screen->px[i][j], 4);
			i++;
		}
		j--;
	}
	if (writtenbytes != 4 * screen->rez.x * screen->rez.y)
		return (ERR_FILEWRITE);
	return (NOERR);
}

int			mrt_drawimg_bmp_write(int fd, t_screen *screen)
{
	int			res;
	uint32_t	imgsize;

	imgsize = 4 * screen->rez.x * screen->rez.y;
	res = bmp_write_fileheader(fd, imgsize);
	if (res != NOERR)
		return (res);
	res = bmp_write_infoheader(fd, imgsize, screen->rez.x, screen->rez.y);
	if (res != NOERR)
		return (res);
	res = bmp_write_image(fd, screen);
	return (NOERR);
}
