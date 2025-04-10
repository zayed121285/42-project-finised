/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filefdf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:51:30 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 18:09:56 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEFDF_H
# define FILEFDF_H

# include "../headers/FDF.h"

void			error(char *str);
void			ft_putchar(char c, int *ret_val);
void			ft_putstr(char *str, int *ret_val);
void			ft_putnbr(int num, int *ret_val);
void			ft_putptr(unsigned long num, int *ret_val);
void			ft_putunbr(unsigned int num, int *ret_val);
char			*ft_convert(size_t num, char *repres);
int				ft_printf(const char *str, ...);
t_coordinate	calcualte_x_rotation(t_coordinate rotate, t_mlx *mlx);
t_coordinate	calcualte_y_rotation(t_coordinate rotate, t_mlx *mlx);
t_coordinate	calcualte_z_rotation(t_coordinate rotate, t_mlx *mlx);
void			calcualte_z(t_draw *draw, t_fdf *fdf, t_mlx *mlx);
void			put_image(t_img *img, int x, int y, int color);
float			mod(float a, float b);
void			mlx_ready(t_mlx *mlx, t_img *img);
void			get_yln(t_fdf *fdf);
void			get_xwd(t_fdf *fdf);
void			map_ready(t_fdf *fdf);
t_draw			zoming(t_draw draw, t_mlx *mlx);
void			fill(t_coordinate *rotate, t_coordinate *rotate1, t_draw *draw);
float			abst(float a);
int				color(int a, int r, int g, int b);
int				decide_color(float z, float z1);
void			bresnham(t_draw draw, t_mlx *mlx, t_img *img, t_fdf *fdf);
t_draw			fill_data(int x, int x1, int y, int y1);
int				checking(char *str);
int				atoi_color(char *str, t_fdf *fdf);
void			extract(t_fdf *fdf);
void			drawdata(t_mlx *mlx, t_fdf *fdf, t_img *img);
void			mlx_ready_img(t_mlx *mlx, t_img *img);
void			new_image_hook(t_fdf *fdf, t_mlx *mlx, t_img *img);
int				mouse(int keyhook, int x, int y, t_mlx *mlx);
int				move(int keyhook, t_mlx *mlx);
int				close_window(t_mlx *mlx);
int				mlx_hooks_ready(t_mlx *mlx);
void			initilaztion(t_mlx *mlx);
void			mlx_strings(t_mlx *mlx);
#endif