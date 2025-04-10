/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:35:44 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/18 19:23:15 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

int	mlx_hooks_ready(t_mlx *mlx)
{
	mlx_mouse_hook(mlx->win, mouse, mlx);
	mlx_key_hook(mlx->win, move, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	return (0);
}

void	mlx_ready_img(t_mlx *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->mlx, WIDTH1, LENGTH1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->ln, &img->endian);
}

void	mlx_ready(t_mlx *mlx, t_img *img)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		error("Error: mlx initilaztion");
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, LENGTH, "Fdf@42");
	if (!mlx->win)
		error("Error: window initilaztion");
	img->img = mlx_new_image(mlx->mlx, WIDTH1, LENGTH1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->ln,
			&img->endian);
}

void	mlx_strings(t_mlx *mlx)
{
	static int	j;

	if (!j)
		j = 0;
	j++;
	mlx_string_put(mlx->mlx, mlx->win, 50, 25,
		color(20, j * 100, 100 * 20, 255), mlx->str);
	mlx_string_put(mlx->mlx, mlx->win, 50, 50,
		color(20 * j, 100, 10 * j, 3 * j),
		"[keyboard Movement: Up, Down, Left, Right]");
	mlx_string_put(mlx->mlx, mlx->win, 50, 75,
		color(20 * j, 65 * j, 3 * j, 10 * j),
		"[Mouse : scrolle up ->");
	mlx_string_put(mlx->mlx, mlx->win, 300, 75,
		color(20 * j, 65 * j, 3 * j, 10 * j),
		"[scrolle up -> ZOOM, scrolle up -> ZOOMDOWN | LEFT && RIGHT X,Y AXIS");
}

void	new_image_hook(t_fdf *fdf, t_mlx *mlx, t_img *img)
{
	static int	j;

	if (!j)
		j = 0;
	j++;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_strings(mlx);
	fdf->filename = mlx->filename;
	mlx_ready_img(mlx, img);
	fdf->matrix = mlx->matrix;
	fdf->intmatrix = mlx->intmatrix;
	fdf->xwd = mlx->xwd;
	fdf->yln = mlx->yln;
	drawdata(mlx, fdf, img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 100, 100);
}
