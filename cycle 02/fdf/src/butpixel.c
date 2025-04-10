/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:41:56 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 18:01:40 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

void	put_image(t_img *img, int x, int y, int color)
{
	unsigned int	*dst;
	int				i;

	i = 0;
	dst = img->addr;
	dst = dst + img->ln * y / 4;
	dst = dst + x * (img->bits_per_pixel / 32);
	dst[0] = color;
}

void	drawdata(t_mlx *mlx, t_fdf *fdf, t_img *img)
{
	int		y;
	int		x;
	t_draw	draw;
	int		j;

	x = 0;
	j = 0;
	y = 0;
	while (y < fdf->yln)
	{
		x = 0;
		while (j < fdf->xwd)
		{
			draw = fill_data(x, x, y, y + 1);
			if (y < fdf->yln - 1)
				bresnham(draw, mlx, img, fdf);
			draw = fill_data(x, x + 1, y, y);
			if (x < fdf->xwd - 1)
				bresnham(draw, mlx, img, fdf);
			x++;
			j++;
		}
		j = 0;
		y++;
	}
}
