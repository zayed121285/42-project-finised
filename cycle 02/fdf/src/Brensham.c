/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brensham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:38:50 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 18:01:28 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

float	mod(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	abst(float a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

void	bresnham(t_draw draw, t_mlx *mlx, t_img *img, t_fdf *fdf)
{
	float	dx;
	float	dy;
	float	bigger;
	int		color1;

	color1 = 0;
	calcualte_z(&draw, fdf, mlx);
	draw = zoming(draw, mlx);
	dx = draw.x1 - draw.x;
	dy = draw.y1 - draw.y;
	bigger = mod(abst(dx), abst(dy));
	dx /= bigger;
	dy /= bigger;
	while ((int)(draw.x1 - draw.x) || (int)(draw.y1 - draw.y))
	{
		color1 = decide_color(draw.z, draw.z1);
		if ((int)draw.x < WIDTH1 && (int)draw.y < LENGTH1
			&& (int)draw.y > 0 && (int)draw.x > 0)
			put_image(img, (int)draw.x, (int)draw.y, color1);
		draw.x += dx;
		draw.y += dy;
	}
}
