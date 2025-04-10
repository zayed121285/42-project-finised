#include "../headers/FDF.h"

// void error(char *str)
// {
// 	ft_printf("%s\n", str);
// 	exit(-1);
// }

// static int	first_element_count(char const *s, char c)
// {
// 	int	i;
// 	int	count;
// 	int	str_found;

// 	i = 0;
// 	count = 0;
// 	if (s[i] == c && *s != '\0')
// 		str_found = 0;
// 	else if (s[i] != c && *s != '\0')
// 	{
// 		str_found = 1;
// 		count++;
// 	}
// 	while (*s != '\0' && s[++i] != '\0')
// 	{
// 		if (s[i] != c && str_found != 1)
// 		{
// 			str_found = 1;
// 			count++;
// 		}
// 		if (s[i] == c && str_found != 0)
// 			str_found = 0;
// 	}
// 	return (count);
// }

// static void	str_clear(char **ret, int k)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < k)
// 		free(ret[i]);
// 	free (ret);
// 	ret = NULL;
// }

// static void	second_element_malloc(char const *s, char c, char **ret)
// {
// 	int	str_start;
// 	int	i;
// 	int	k;

// 	str_start = -1;
// 	i = -1;
// 	k = 0;
// 	while (s[++i] != '\0')
// 	{
// 		if (s[i] != c && str_start == -1)
// 			str_start = i;
// 		if (s[i] == c && str_start != -1)
// 		{
// 			ret[k++] = ft_substr(s, str_start, i - str_start);
// 			if (ret[k - 1] == NULL)
// 				str_clear(ret, k - 1);
// 			str_start = -1;
// 		}
// 	}
// 	if (s[--i] != c)
// 	{
// 		ret[k++] = ft_substr(s, str_start, i - str_start + 1);
// 		if (ret[k - 1] == NULL)
// 			str_clear(ret, k - 1);
// 	}
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**ret;
// 	int		array_count;

// 	if (s == NULL)
// 		return (NULL);
// 	array_count = first_element_count(s, c);
// 	ret = malloc(sizeof(char *) * (array_count + 1));
// 	if (ret == NULL)
// 		return (NULL);
// 	ret[array_count] = NULL;
// 	if (array_count == 0)
// 		return (ret);
// 	second_element_malloc(s, c, ret);
// 	return (ret);
// }


// coordinate calcualte_x_rotation(coordinate rotate, s_mlx  *mlx)
// {
// 	rotate.angle =  45 + mlx->xangle;
// 	rotate.x = rotate.x;
// 	rotate.y = rotate.y * cosf(rotate.angle) - rotate.z * sinf(rotate.angle);
// 	rotate.y = rotate.y * sinf(rotate.angle) + rotate.z * cosf(rotate.angle);
// 	return (rotate);
// }

// coordinate calcualte_y_rotation(coordinate rotate ,s_mlx  *mlx)
// {
// 	rotate.angle = 100 + mlx->yangle;
// 	rotate.x = rotate.x * cosf(rotate.angle) + rotate.z * sinf(rotate.angle);
// 	rotate.y = rotate.y;
// 	rotate.z = -rotate.x * sinf(rotate.angle) + rotate.z * cosf(rotate.angle);
// 	return (rotate);
// }

// coordinate calcualte_z_rotation(coordinate rotate,s_mlx  *mlx)
// {
// 	rotate.angle = mlx->zangle;
// 	rotate.x = rotate.x * cosf(rotate.angle) - rotate.y * sinf(rotate.angle);
// 	rotate.y = rotate.x * sinf(rotate.angle) + rotate.y * cosf(rotate.angle);
// 	rotate.z = rotate.z;
// 	return (rotate);
// }

// void put_image(s_img *img, int x, int y, int color)
// {
// 	unsigned int *dst;
// 	int i;
// 	i = 0;

// 	dst = img->addr;
// 	dst = dst + img->ln * y / 4;
// 	dst = dst + x * (img->bits_per_pixel / 32);
// 	dst[0] = color;
// }

// void mlx_ready(s_mlx *mlx, s_img *img)
// {
// 	mlx->mlx = mlx_init();
// 	if (!mlx->mlx)
// 		error("Error: mlx initilaztion");
// 	mlx->win = mlx_new_window(mlx->mlx, width, length, "Fdf@42");
// 	if (!mlx->win)
// 		error("Error: window initilaztion");
// 	img->img = mlx_new_image(mlx->mlx, width1, length1);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->ln, &img->endian);
// }

// void get_yln(s_fdf *fdf)
// {
// 	char *line;
// 	fdf->fd = open(fdf->filename, O_RDONLY);
// 	if (!fdf->fd)
// 		error("Error: open the file");
// 	fdf->yln = 0;
// 	while ((line = get_next_line(fdf->fd)) != NULL)
// 	{
// 		fdf->yln++;
// 		free(line);
// 	}
// 	if (fdf->yln == 0)
// 		error("file is empty");
// }

// void get_xwd(s_fdf *fdf)
// {
// 	char *line;
// 	char **words;
// 	fdf->fd = open(fdf->filename, O_RDONLY);
// 	if (!fdf->fd)
// 		error("Error: open the file");
// 	fdf->xwd = 0;
// 	line = get_next_line(fdf->fd);
// 	words = ft_split(line, ' ');
// 	while (words[fdf->xwd] != NULL)
// 		fdf->xwd++;
// 	if (fdf->xwd == 0)
// 		error("file is empty");
// }

// void map_ready(s_fdf *fdf)
// {
// 	char *line;
// 	int i;

// 	i = 0;
// 	fdf->fd = open(fdf->filename, O_RDONLY);
// 	if (!fdf->fd || read(fdf->fd, 0, 0) < 0)
// 		error("Error: open the file");
// 	get_yln(fdf);
// 	get_xwd(fdf);
// 	fdf->matrix = malloc(sizeof(char **) * fdf->yln);
// 	while ((line = get_next_line(fdf->fd)) != NULL)
// 	{
// 		fdf->matrix[i] = ft_split(line, ' ');
// 		free(line);
// 		i++;
// 	}
// 	fdf->matrix[i] = NULL;
// }

// s_draw zoming(s_draw draw, s_mlx *mlx)
// {
// 	draw.x *= mlx->zoom;
// 	draw.y *= mlx->zoom;
// 	draw.y1 *= mlx->zoom;
// 	draw.x1 *= mlx->zoom;
// 	return (draw);
// }


// void fill(coordinate *rotate, coordinate *rotate1, s_draw *draw)
// {
// 	rotate->x = draw->x;
// 	rotate->y = draw->y;
// 	rotate1->x = draw->x1;
// 	rotate1->y = draw->y1;
// 	rotate->z = draw->z;
// 	rotate1->z = draw->z1;
// }

// void calcualte_z(s_draw *draw, s_fdf *fdf, s_mlx *mlx)
// {
// 	coordinate rotate;
// 	coordinate rotate1;

// 	draw->z = 0;
// 	draw->z1 = 0;
// 	if ((int)(draw->x) < fdf->xwd || (int)(draw->y) < fdf->yln)
// 		draw->z = fdf->intmatrix[(int)(draw->y)][(int)(draw->x)];
// 	if ((int)(draw->x1) < fdf->xwd - 1 || (int)(draw->y1) < fdf->yln - 1)
// 		draw->z1 = fdf->intmatrix[(int)(draw->y1)][(int)(draw->x1)];
// 	fill(&rotate, &rotate1, draw);
// 	rotate = calcualte_x_rotation(rotate, mlx);
// 	rotate = calcualte_y_rotation(rotate, mlx);
// 	draw->x = (rotate.x - rotate.y) + mlx->xshift;
// 	draw->y = (rotate.x + rotate.y) + mlx->yshift;
// 	rotate1 = calcualte_x_rotation(rotate1, mlx);
// 	rotate1 = calcualte_y_rotation(rotate1, mlx);
// 	draw->x1 = (rotate1.x - rotate1.y) + mlx->xshift;
// 	draw->y1 = (rotate1.x + rotate1.y) + mlx->yshift;
// }

// float MOD(float a, float b)
// {
// 	if (a > b)
// 		return (a);
// 	else
// 		return (b);
// }

// float abst(float a)
// {
// 	if (a < 0)
// 		return (-1 * a);
// 	else
// 		return (a);
// }

// int color(int a, int r, int g, int b)
// {
// 	return (a << 24 | r << 16 | g << 8 | b);
// }
// int decide_color(float z, float z1)
// {
// 	static int j;

// 	if (!j)
// 		j = 0;
// 	j++;
// 	if (z > 0 && z1 > 0)
// 		return(color(100,255, 100*(int)z, 99));
// 	if (z == 0 && z1 == 0)
// 		return(color(250,255, 250, 255));
// 	else
// 		return(color(250,3*j, 70*j, 150));
// }

// void Bresnham(s_draw draw, s_mlx *mlx, s_img *img, s_fdf *fdf)
// {
// 	float dx;
// 	float dy;
// 	float bigger;
// 	int color1;

// 	color1 = 0;
// 	calcualte_z(&draw, fdf, mlx);
// 	draw = zoming(draw, mlx);
// 	dx = draw.x1 - draw.x;
// 	dy = draw.y1 - draw.y;
// 	bigger = MOD(abst(dx), abst(dy));
// 	dx /= bigger;
// 	dy /= bigger;
// 	while ((int)(draw.x1 - draw.x) || (int)(draw.y1 - draw.y))
// 	{
// 		color1 = decide_color(draw.z,draw.z1);
// 		if ((int)draw.x < width1 && (int)draw.y < length1 && (int)draw.y > 0 && (int)draw.x > 0)
// 			put_image(img, (int)draw.x, (int)draw.y, color1);
// 		draw.x += dx;
// 		draw.y += dy;
// 	}
// }

// s_draw fill_data(int x, int x1, int y, int y1)
// {
// 	s_draw new;

// 	new.x = x;
// 	new.y = y;
// 	new.x1 = x1;
// 	new.y1 = y1;

// 	return (new);
// }

// int checking(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i]==',')
// 			return (3);
// 		i++;
// 	}
// 	return (0);
// }

// int atoi_color(char *str, s_fdf *fdf)
// {
// 	int i;
// 	int j;
// 	static char num[100];
// 	static char color[100];

// 	i = 0;
// 	j = 0;
// 	while (str[i] != ',' && str[i] != '\0')
// 	{
// 		num[i] = str[i];
// 		i++;
// 	}
// 	num[i] = '\0';
// 	i++;
// 	while (str[i] != '\0')
// 	{
// 		color[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	color[j] = '\0';
// 	fdf->color = 99;
// 	return(ft_atoi(num));
// }

// void extract(s_fdf *fdf)
// {
// 	fdf->i = 0;
// 	fdf->j = 0;
// 	fdf->intmatrix = malloc(sizeof(int *) * fdf->yln);
// 	while (fdf->matrix[fdf->i])
// 	{
// 		fdf->intmatrix[fdf->i] = malloc(sizeof(int) * fdf->xwd);
// 		while (fdf->matrix[fdf->i][fdf->j] && fdf->i <= fdf->xwd)
// 		{
// 			if (checking(fdf->matrix[fdf->i][fdf->j])== 0)
// 				fdf->intmatrix[fdf->i][fdf->j] = ft_atoi(fdf->matrix[fdf->i][fdf->j]);
// 			else
// 				fdf->intmatrix[fdf->i][fdf->j] = atoi_color(fdf->matrix[fdf->i][fdf->j], fdf);
// 			fdf->j++;
// 		}
// 		fdf->j = 0;
// 		fdf->i++;
// 	}
// 	fdf->yln = fdf->i;
// }

// void drawdata(s_mlx *mlx, s_fdf *fdf, s_img *img)
// {
// 	int y;
// 	int x;
// 	s_draw draw;

// 	int j;
// 	j = x = 0;
// 	y = 0;
// 	while (y < fdf->yln)
// 	{
// 		x = 0;
// 		while (j < fdf->xwd)
// 		{
// 			draw = fill_data(x, x, y, y + 1);
// 			if (y < fdf->yln - 1)
// 				Bresnham(draw, mlx, img, fdf);
// 			draw = fill_data(x, x + 1, y, y);
// 			if (x < fdf->xwd - 1)
// 				Bresnham(draw, mlx, img, fdf);
// 			x++;
// 			j++;
// 		}
// 		j = 0;
// 		y++;
// 	}
// }


// void mlx_ready_img(s_mlx *mlx, s_img *img)
// {
// 	img->img = mlx_new_image(mlx->mlx, width1, length1);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->ln, &img->endian);
// }

// void	mlx_strings(s_mlx *mlx)
// {
// 	static int j;

// 	if(!j)
// 		j = 0;
// 	j++;
// 	mlx_string_put(mlx->mlx, mlx->win, 50, 25, color(20,j*100,100*20,255), mlx->str);
// 	mlx_string_put(mlx->mlx, mlx->win, 50, 50, color(20*j,100,10*j,3*j), "[keyboard Movement: Up, Down, Left, Right]");
// 	mlx_string_put(mlx->mlx, mlx->win, 50, 75, color(20*j,65*j,3*j,10*j), "[Mouse : scrolle up -> zooming in , scrolle down-> zooming out , mouse click's -> X && Y Axis]");
// }

// void new_image_hook(s_fdf *fdf, s_mlx *mlx, s_img *img)
// {
// 	static int j;

// 	if (!j)
// 		j = 0;
// 	j++;
// 	mlx_clear_window(mlx->mlx, mlx->win);
// 	mlx_strings(mlx);
// 	fdf->filename = mlx->filename;
// 	mlx_ready_img(mlx, img);
// 	fdf->matrix = mlx->matrix;
// 	fdf->intmatrix=mlx->intmatrix;
// 	fdf->xwd = mlx->xwd;
// 	fdf->yln = mlx->yln;
// 	drawdata(mlx, fdf, img);
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 100, 100);
// }

// int mouse(int keyhook, int x, int y, s_mlx *mlx)
// {
// 	s_fdf fdf;
// 	s_img img;

// 	if (keyhook == 4)
// 		mlx->zoom = mlx->zoom + 1;
// 	if (keyhook == 5)
// 		mlx->zoom = mlx->zoom - 1;
// 	if (keyhook == 1)
// 	{
// 		mlx->str = "Angle: changed in Y AXIS";
// 		mlx->yangle = mlx->yangle + 0.1;
// 	}
// 	if (keyhook == 2)
// 	{
// 		mlx->str = "Angle: Changed in X AXIS";
// 		mlx->xangle = mlx->xangle + 0.1;
// 	}
// 	if (keyhook == 3)
// 	{
// 		mlx->str = "Defualt: ISOMATRIC PROJECTION";
// 		mlx->yangle = 0;
// 		mlx->xangle =0;
// 	}
// 	ft_printf("(%d, %d)",x, y);
// 	new_image_hook(&fdf, mlx, &img);
// 	return (0);
// }

// int move(int keyhook, s_mlx *mlx)
// {
// 	s_fdf fdf;
// 	s_img img;

// 	if (keyhook == 123)
// 		mlx->xshift = mlx->xshift - 1;
// 	if (keyhook == 124)
// 		mlx->xshift = mlx->xshift + 1;
// 	if (keyhook == 125)
// 		mlx->yshift = mlx->yshift + 1;
// 	if (keyhook == 126)
// 		mlx->yshift = mlx->yshift - 1;
// 	if (keyhook == 53)
// 	{
// 		mlx_destroy_window(mlx->mlx, mlx->win);
// 		exit(0);
// 	}
// 	new_image_hook(&fdf, mlx, &img);
// 	return (0);
// }

// int close_window(s_mlx *mlx)
// {
// 	mlx_destroy_window(mlx->mlx, mlx->win);
// 	exit(0);
// }

// int mlx_hooks_ready(s_mlx *mlx)
// {
// 	mlx_mouse_hook(mlx->win, mouse, mlx);
// 	mlx_key_hook(mlx->win, move, mlx);
// 	mlx_hook(mlx->win, 17, 0, close_window, mlx);
// 	return (0);
// }

// void	initilaztion(s_mlx *mlx)
// {
// 	mlx->zoom = 10;
// 	mlx->xshift = 20;
// 	mlx->yshift = 20;
// 	mlx->yangle = 0;
// 	mlx->xangle = 0;
// 	mlx->zangle = 0;
// 	mlx->str = "Defualt: ISOMATRIC PROJECTION";
// }

// int main(int argn, char *argv[])
// {
// 	s_fdf fdf;
// 	s_mlx mlx;
// 	s_img img;

// 	initilaztion(&mlx);
// 	if (argn == 2)
// 	{
// 		mlx.filename = fdf.filename= argv[1];  
// 		mlx_ready(&mlx, &img);
// 		map_ready(&fdf);
// 		extract(&fdf);
// 		drawdata(&mlx, &fdf, &img);
// 		mlx.matrix = fdf.matrix;
// 		mlx.intmatrix =fdf.intmatrix;
// 		mlx.xwd = fdf.xwd;
// 		mlx.yln = fdf.yln;
// 		mlx_hooks_ready(&mlx);
// 		mlx_strings(&mlx);
// 		mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 100, 100);
// 		mlx_loop(mlx.mlx);
// 	}
// }
