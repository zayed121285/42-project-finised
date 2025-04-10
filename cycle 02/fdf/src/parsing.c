/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:30:39 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/03/02 16:36:11 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

void	get_yln(t_fdf *fdf)
{
	char	*line;

	fdf->fd = open(fdf->filename, O_RDONLY);
	if (!fdf->fd)
		error("Error: open the file");
	fdf->yln = 0;
	line = get_next_line(fdf->fd);
	while (line != NULL)
	{
		fdf->yln++;
		free(line);
		line = get_next_line(fdf->fd);
	}
	if (fdf->yln == 0)
		error("file is empty");
}

void	get_xwd(t_fdf *fdf)
{
	char	*line;
	char	**words;

	fdf->fd = open(fdf->filename, O_RDONLY);
	if (!fdf->fd)
		error("Error: open the file");
	fdf->xwd = 0;
	line = get_next_line(fdf->fd);
	words = ft_split(line, ' ');
	while (words[fdf->xwd] != NULL)
		fdf->xwd++;
	if (fdf->xwd == 0)
		error("file is empty");
}

static void	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i = i - 4;
	if (str[i] != '.' || str[i + 1] != 'f'
		|| str[i + 2] != 'd' || str[i + 3] != 'f')
		error("TYPE of file not correcte format : .fdf file");
	i++;
}

void	map_ready(t_fdf *fdf)
{
	char	*line;
	int		i;

	i = 0;
	check_file_name(fdf->filename);
	fdf->fd = open(fdf->filename, O_RDONLY);
	if (!fdf->fd || read(fdf->fd, 0, 0) < 0)
		error("Error: open the file");
	get_yln(fdf);
	get_xwd(fdf);
	fdf->matrix = malloc(sizeof(char **) * fdf->yln);
	line = get_next_line(fdf->fd);
	while (line != NULL)
	{
		line = get_next_line(fdf->fd);
		fdf->matrix[i] = ft_split(line, ' ');
		free(line);
		i++;
	}
	fdf->matrix[i] = NULL;
}

void	extract(t_fdf *fdf)
{
	fdf->i = 0;
	fdf->j = 0;
	fdf->intmatrix = malloc(sizeof(int *) * fdf->yln);
	while (fdf->matrix[fdf->i])
	{
		fdf->intmatrix[fdf->i] = malloc(sizeof(int) * fdf->xwd);
		while (fdf->matrix[fdf->i][fdf->j] && fdf->i <= fdf->xwd)
		{
			if (checking(fdf->matrix[fdf->i][fdf->j]) == 0)
				fdf->intmatrix[fdf->i][fdf->j]
					= ft_atoi(fdf->matrix[fdf->i][fdf->j]);
			else
				fdf->intmatrix[fdf->i][fdf->j]
					= atoi_color(fdf->matrix[fdf->i][fdf->j], fdf);
			fdf->j++;
		}
		fdf->j = 0;
		fdf->i++;
	}
	fdf->yln = fdf->i;
}
