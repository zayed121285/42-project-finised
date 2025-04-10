/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:31:49 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 18:05:00 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

t_coordinate	calcualte_x_rotation(t_coordinate rotate, t_mlx	*mlx)
{
	rotate.angle = 45 + mlx->xangle;
	rotate.x = rotate.x;
	rotate.y = rotate.y * cosf(rotate.angle) - rotate.z * sinf(rotate.angle);
	rotate.y = rotate.y * sinf(rotate.angle) + rotate.z * cosf(rotate.angle);
	return (rotate);
}

t_coordinate	calcualte_y_rotation(t_coordinate	rotate, t_mlx	*mlx)
{
	rotate.angle = 100 + mlx->yangle;
	rotate.x = rotate.x * cosf(rotate.angle) + rotate.z * sinf(rotate.angle);
	rotate.y = rotate.y;
	rotate.z = -rotate.x * sinf(rotate.angle) + rotate.z * cosf(rotate.angle);
	return (rotate);
}

t_coordinate	calcualte_z_rotation(t_coordinate rotate, t_mlx	*mlx)
{
	rotate.angle = mlx->zangle;
	rotate.x = rotate.x * cosf(rotate.angle) - rotate.y * sinf(rotate.angle);
	rotate.y = rotate.x * sinf(rotate.angle) + rotate.y * cosf(rotate.angle);
	rotate.z = rotate.z;
	return (rotate);
}

void	calcualte_z(t_draw *draw, t_fdf *fdf, t_mlx *mlx)
{
	t_coordinate	rotate;
	t_coordinate	rotate1;

	draw->z = 0;
	draw->z1 = 0;
	if ((int)(draw->x) < fdf->xwd || (int)(draw->y) < fdf->yln)
		draw->z = fdf->intmatrix[(int)(draw->y)][(int)(draw->x)];
	if ((int)(draw->x1) < fdf->xwd - 1 || (int)(draw->y1) < fdf->yln - 1)
		draw->z1 = fdf->intmatrix[(int)(draw->y1)][(int)(draw->x1)];
	fill(&rotate, &rotate1, draw);
	rotate = calcualte_x_rotation(rotate, mlx);
	rotate = calcualte_y_rotation(rotate, mlx);
	draw->x = (rotate.x - rotate.y) + mlx->xshift;
	draw->y = (rotate.x + rotate.y) + mlx->yshift;
	rotate1 = calcualte_x_rotation(rotate1, mlx);
	rotate1 = calcualte_y_rotation(rotate1, mlx);
	draw->x1 = (rotate1.x - rotate1.y) + mlx->xshift;
	draw->y1 = (rotate1.x + rotate1.y) + mlx->yshift;
}
