/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controleview.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:46:11 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/27 16:21:16 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

t_draw	zoming(t_draw draw, t_mlx *mlx)
{
	draw.x *= mlx->zoom;
	draw.y *= mlx->zoom;
	draw.y1 *= mlx->zoom;
	draw.x1 *= mlx->zoom;
	return (draw);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	mouse(int keyhook, int x, int y, t_mlx *mlx)
{
	t_fdf	fdf;
	t_img	img;

	if (keyhook == 4)
		mlx->zoom = mlx->zoom + 1;
	if (keyhook == 5)
		mlx->zoom = mlx->zoom - 1;
	if (keyhook == 1)
	{
		mlx->str = "Angle: changed in Y AXIS";
		mlx->yangle = mlx->yangle + 0.1;
	}
	if (keyhook == 2)
	{
		mlx->str = "Angle: Changed in X AXIS";
		mlx->xangle = mlx->xangle + 0.1;
	}
	if (keyhook == 3)
	{
		mlx->str = "Defualt: ISOMATRIC PROJECTION";
		mlx->yangle = 0;
		mlx->xangle = 0;
	}
	new_image_hook(&fdf, mlx, &img);
	return (ft_printf("(%d, %d)", x, y));
}

int	move(int keyhook, t_mlx *mlx)
{
	t_fdf	fdf;
	t_img	img;

	if (keyhook == 123)
		mlx->xshift = mlx->xshift - 1;
	if (keyhook == 124)
		mlx->xshift = mlx->xshift + 1;
	if (keyhook == 125)
		mlx->yshift = mlx->yshift + 1;
	if (keyhook == 126)
		mlx->yshift = mlx->yshift - 1;
	if (keyhook == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	new_image_hook(&fdf, mlx, &img);
	return (0);
}
