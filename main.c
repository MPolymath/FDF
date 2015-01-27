/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:05 by mdiouf            #+#    #+#             */
/*   Updated: 2015/01/27 15:29:13 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

int			free_split_line(char ***split, char **line)
{
	free(*split);
	free(*line);
	return (-1);
}

int			ft_valid_number(char **line, int *nb)
{
	int		i;
	int		j;
	char	**split;

	split = ft_strsplit(*line, ' ');
	i = 0;
	j = 0;
	while (split[i] != NULL)
	{
		while (split[i][j] != '\0')
		{
			if (split[i][j] != ' ' && split[i][j] != '\n' &&
				(split[i][j] < 48 || split[i][j] > 57))
				return (free_split_line(&split, line));
			j++;
		}
		j = 0;
		i++;
	}
	if ((*nb != 0) && *nb != i)
		return (free_split_line(&split, line));
	*nb = i;
	return (0);
}

void	array_creation(t_main *m)
{
	m->i = 0; //	create data_int to store double array of table converted to int
	(m->data_int) = malloc(sizeof(int*) * m->lines);
	while (m->i != m->lines)
	{
		(m->data_int)[m->i] = malloc(sizeof(int) * m->nb);
		(m->i)++;
	}
	(m->data_int)[m->i] = NULL;
	(m->data_char) = ft_strsplit(m->join_lines, '\n'); // split join_lines
	m->i = 0;
	while ((m->data_char)[m->i] != NULL) //	split individual numbers and stick em into new data_int array
	{
		(m->data_nb) = ft_strsplit((m->data_char)[m->i], ' ');
		while ((m->data_nb)[m->j] != NULL)
		{
			(m->data_int)[m->i][m->j] = ft_atoi((m->data_nb)[m->j]);
			(m->j)++;
		}
		m->j = 0;
		free((m->data_nb));
		(m->data_nb) = NULL;
		(m->i)++;
	}
}

void	init_main(t_main *m, t_gfx *g)
{
	m->fd = open("test", O_RDONLY);
	m->nb = 0;
	m->i = 0;
	m->j = 0;
	m->lines = 0;
	m->start = NULL;
	m->line = NULL;
	m->join_lines = NULL;
	m->data_nb = NULL;
	m->data_int = NULL;
	m->data_char = NULL;
	g->mlx = NULL;
	g->win = NULL;
	g->img = NULL;
	g->add_img = NULL;
	g->bit_pp = 0;
	g->size = 0;
	g->endian = 0;
	g->k = 0;
	g->bpx = &(g->bit_pp);
	g->sz_ln = &(g->size);
	g->ndian = &(g->endian);
	g->n = 128;
	g->color = 0;
}

void	create_new_elem(t_info *inf, t_main **m)
{
	t_list	*elem;
	t_list	*temp;

	elem = malloc(sizeof(t_list));
	elem->x_1.x = (inf->x * inf->x_incr);
	elem->x_1.y = (inf->y * inf->y_incr);
	elem->x_2.x = ((inf->x + 1) * inf->x_incr);
	elem->x_2.y = (inf->y * inf->y_incr);
	elem->x_3.x = (inf->x  * inf->x_incr);
	elem->x_3.y = ((inf->y + 1) * inf->y_incr);
	elem->x_4.x = ((inf->x + 1)  * inf->x_incr);
	elem->x_4.y = ((inf->y + 1) * inf->y_incr);
	elem->height = inf->height;
	if (inf->x == 0 && inf->y == 0)
	{
		elem->prev = NULL;
		elem->next = NULL;
		(*m)->start = elem;
	}
	else
	{
		temp = (*m)->start;
		if (temp->next == NULL)
		{
			temp->next = elem;
			temp->prev = elem;
			elem->next = temp;
			elem->prev = temp;
		}
		else
		{
			temp = temp->next;
			while (temp->next != (*m)->start)
				temp = temp->next;
			temp->next = elem;
			elem->prev = temp;
			elem->next = (*m)->start;
			(*m)->start->prev = elem;
		}
	}
}

void	create_list(t_main *m, t_gfx *g)
{
	int		x;
	int		y;
	int		x_incr;
	int		y_incr;
	t_info	inf;
	t_list	*temp;

	x = 0;
	y = 0;
	x_incr = SCR_X / m->nb;
	y_incr = SCR_Y / m->lines;
//x1 = pos = x * xincrement, y * yincrement
//x2 = pos = (x + 1) * xincrement, y * yincrement
//x3 = pos = x * xincrement, (y + 1) * yincrement
//x4 = pos = (x + 1) * xincrement, y * yincrement
	printf("lines: %d  nb: %d\n", m->lines, m->nb);
	while (y != m->lines)
	{
		while (x != m->nb)
		{
			inf.x = x;
			inf.y = y;
			inf.x_incr = x_incr;
			inf.y_incr = y_incr;
			inf.height = (m->data_int)[y][x];
			printf("X: %d Y: %d Height: %d\n", x, y, inf.height);
			create_new_elem(&inf , &m);
			x++;
		}
		x = 0;
		y++;
	}
	temp = m->start;
	printf("x_1.x %d\n", temp->x_1.x);
	printf("x_1.y %d\n", temp->x_1.y);
	printf("x_2.x %d\n", temp->x_2.x);
	printf("x_2.y %d\n", temp->x_2.y);
	printf("x_3.x %d\n", temp->x_3.x);
	printf("x_3.y %d\n", temp->x_3.y);
	printf("x_4.x %d\n", temp->x_4.x);
	printf("x_4.y %d\n", temp->x_4.y);
	printf("height %d\n", temp->height);
	temp = temp->next;
	while (temp != m->start)
	{
		printf("x_1.x %d\n", temp->x_1.x);
		printf("x_1.y %d\n", temp->x_1.y);
		printf("x_2.x %d\n", temp->x_2.x);
		printf("x_2.y %d\n", temp->x_2.y);
		printf("x_3.x %d\n", temp->x_3.x);
		printf("x_3.y %d\n", temp->x_3.y);
		printf("x_4.x %d\n", temp->x_4.x);
		printf("x_4.y %d\n", temp->x_4.y);
		printf("height %d\n", temp->height);
		temp = temp->next;
	}
}

void	init_gfx(t_main *m, t_gfx *g)
{
	int	x = m->nb * 10;
	int	y = m->lines * 10;
	int	i = 0;
	char *temp;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, SCR_X , SCR_Y, "mywindow");
	g->img = mlx_new_image(g->mlx, SCR_X, SCR_Y);
//	printf("x: %d, y: %d \n", x, y);
	g->add_img = mlx_get_data_addr(g->img, g->bpx, g->sz_ln, g->ndian);
	temp = g->add_img;
//	printf("lines: %d, nb: %d bpx: %d, sz_ln: %d, size: %d\n", m->lines, m->nb, *g->bpx, *g->sz_ln, g->size);
	while (1)
	{
// print tiles
//calculate x1 x2 x3 x4
//x1 = pos = x * xincrement, y * yincrement
//x2 = pos = (x + 1) * xincrement, y * yincrement
//x3 = pos = x * xincrement, (y + 1) * yincrement
//x4 = pos = (x + 1) * xincrement, y * yincrement
//if first tile first row
//print x1 x2 x3 x4
//if first tile not first row
//print x3 x4
// else
//print x2 x4
		printf("x_1.x: %d, x_1.y: %d, x_2.x: %d, x_2.y: %d, x_3.x: %d x_4.x: %d x_4.y: %d\n", m->start->x_1.x, m->start->x_1.y, m->start->x_2.x, m->start->x_2.y, m->start->x_3.x, m->start->x_3.y, m->start->x_4.x, m->start->x_4.y);
		i = (*(g->bpx) * (m->start->x_1.x)) + (*(g->sz_ln) * (m->start->x_1.y));
		temp = temp += i;
		*temp = 255;
		temp++;
		*temp = 0;
		temp++;
		*temp = 255;
		temp = g->add_img;
		i = (*(g->bpx) * (m->start->x_2.x / 4)) + (*(g->sz_ln) * (m->start->x_2.y));
		temp = temp += i;
		*temp = 255;
		temp++;
		*temp = 0;
		temp++;
		*temp = 255;
		temp = g->add_img;
		i = (*(g->bpx) * (m->start->x_3.x / 4)) + (*(g->sz_ln) * (m->start->x_3.y));
		temp = temp += i;
		*temp = 255;
		temp++;
		*temp = 0;
		temp++;
		*temp = 255;
		temp = g->add_img;
		i = (*(g->bpx) * (m->start->x_4.x / 4)) + (*(g->sz_ln) * (m->start->x_4.y));
		temp = temp += i;
		*temp = 255;
		temp++;
		*temp = 0;
		temp++;
		*temp = 255;
//		printf("%d\n", (g->bpx * start->x_1.x) + (g->sz_ln * start->x_1.y));
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
//		printf("m->j - (sz_ln * 2): %d\n", m->j - (*(g->sz_ln) * 2));
		sleep(100);
	}
//	while (m->i != 25000)
//	{
//		if (m->j - (g->sz_ln * 2) >= 0)
//			if (data_int[m->j - (sz_ln * 2)]
//		*(g->add_img) = 255;
//		(g->add_img)++;
//		(m->i)++;
//			printf("%d\n", *bgn_img);
//	}
}

int	main(int argc, char **argv)
{
/*	void*			mlx;
	void*			win;
	void*			img;
	int				bit_pp = 0;
	int				size = 0;
	int				endian = 0;
	int				i = 0;
	int				j = 0;
	int				k = 0;
	int*			bpx = &bit_pp;
	int*			sz_ln = &size;
	int*			ndian = &endian;
	int				n = 128;
	unsigned int	color;
	char*			bgn_img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mywindow");
	img = mlx_new_image(mlx, 500, 500);
	bgn_img = mlx_get_data_addr(img, bpx, sz_ln, ndian);
	color = mlx_get_color_value(mlx, 65280);
	printf("color:%d  bgn_img:%p  bit_pp: %d   size: %d  endian: %d\n", color, bgn_img, bit_pp, size, endian);
	while (k != 7)

	while (i != 1000)
	{
		if (j == 0)
			*bgn_img = 255;
		else if (j == 1)
			*bgn_img = 0;
		else if (j == 2)
			*bgn_img = 255;
		bgn_img++;
		i++;
		j++;
		if (j == 2)
			j = 0;
//			printf("%d\n", *bgn_img);
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	printf("\n", *bgn_img);
	while (1)
	{
	}*/

/*
 [][]*struct

while (map[y])
{
	x = 0;
	while (map[y][x])
	{
		if (x > 0)
			drawline(e, map[y][x], e[y][x - 1]);
		if (y > 0)
			drawline(e, map[y][x], e[y - 1][x]);
		x++;
	}
	y++;
}
 */
	t_main		m;
	t_gfx		g;

	init_main(&m, &g); //	read entire file check if same amount of int per lines and store all that is read
	while (get_next_line(m.fd, &m.line) != 0)
	{
		if (ft_valid_number(&m.line, &(m.nb)) != -1)
		{
			m.join_lines = ft_strjoin(m.join_lines, "\n");
			m.join_lines = ft_strjoin(m.join_lines, m.line);
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		m.lines++;
		if (m.line != NULL)
			free(m.line);
	}
	array_creation(&m);
	m.i = 0;
	while ((m.data_int)[m.i] != NULL)
	{
		printf("Data_int[%d]: ", m.i);
		while (m.j != m.nb)
		{
			printf("%d ", (m.data_int)[m.i][m.j]);
			(m.j)++;
		}
		m.j = 0;
		printf("\n");
		(m.i)++;
	}
	create_list(&m, &g);
	init_gfx(&m, &g);
	return (0);
}
/* test data_int
	i = 0;
	while (data_int[i] != NULL)
	{
		printf("Data_int[%d]: ", i);
		while (j != nb)
		{
			printf("%d ", data_int[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
*/
