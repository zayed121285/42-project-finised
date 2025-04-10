/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:47:57 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 18:13:00 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

int	atoi_color(char *str, t_fdf *fdf)
{
	int			i;
	int			j;
	static char	num[100];
	static char	color[100];

	i = 0;
	j = 0;
	while (str[i] != ',' && str[i] != '\0')
	{
		num[i] = str[i];
		i++;
	}
	num[i] = '\0';
	i++;
	while (str[i] != '\0')
	{
		color[j] = str[i];
		i++;
		j++;
	}
	color[j] = '\0';
	fdf->color = 99;
	return (ft_atoi(num));
}

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

int	color(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	decide_color(float z, float z1)
{
	static int	j;

	if (!j)
		j = 0;
	j++;
	if (z > 0 && z1 > 0)
		return (color(100, 255, 100 * (int)z, 99));
	if (z == 0 && z1 == 0)
		return (color(250, 255, 250, 255));
	else
		return (color(250, 3 * j, 70 * j, 150));
}

t_draw	fill_data(int x, int x1, int y, int y1)
{
	t_draw	new;

	new.x = x;
	new.y = y;
	new.x1 = x1;
	new.y1 = y1;
	return (new);
}
