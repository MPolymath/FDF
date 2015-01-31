/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:05 by mdiouf            #+#    #+#             */
/*   Updated: 2015/01/31 15:42:22 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#include <math.h>
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

void	cr_frst(t_main **m, t_list **elem)
{
	(*elem)->prev = NULL;
	(*elem)->next = NULL;
	(*m)->start = *elem;
}

void	if_nt_frst(t_list **elem, t_list **temp, t_main **m)
{
	*temp = (*m)->start;
	if ((*temp)->next == NULL)
	{
		(*temp)->next = *elem;
		(*temp)->prev = *elem;
		(*elem)->next = *temp;
		(*elem)->prev = *temp;
	}
	else
	{
		*temp = (*temp)->next;
		while ((*temp)->next != (*m)->start)
			*temp = (*temp)->next;
		(*temp)->next = *elem;
		(*elem)->prev = *temp;
		(*elem)->next = (*m)->start;
		(*m)->start->prev = *elem;
	}
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
		cr_frst(m, &elem);
	else
		if_nt_frst(&elem, &temp, m);
}

void		print_xs_b(t_list **temp)
{
	ft_putstr("x_3.x ");
	ft_putnbr((*temp)->x_1.x);
	ft_putstr(" ");
	ft_putstr("x_3.y ");
	ft_putnbr((*temp)->x_3.y);
	ft_putstr(" ");
	ft_putstr("x_4.x ");
	ft_putnbr((*temp)->x_4.y);
	ft_putstr(" ");
	ft_putstr("x_4.y ");
	ft_putnbr((*temp)->x_4.y);
	ft_putstr(" ");
	ft_putstr("height ");
	ft_putnbr((*temp)->height);
	ft_putstr("\n");
}

void		print_xs(t_list **temp)
{
	ft_putstr("x_1.x ");
	ft_putnbr((*temp)->x_1.x);
	ft_putstr(" ");
	ft_putstr("x_1.y ");
	ft_putnbr((*temp)->x_1.y);
	ft_putstr(" ");
	ft_putstr("x_2.x ");
	ft_putnbr((*temp)->x_2.x);
	ft_putstr(" ");
	ft_putstr("x_2.y ");
	ft_putnbr((*temp)->x_2.y);
	ft_putstr(" ");
	print_xs_b(temp);
}

void		print_list(t_main **m)
{
	t_list	*temp;

	temp = (*m)->start;
	print_xs(&temp);
	temp = temp->next;
	while (temp != (*m)->start)
	{
		print_xs(&temp);
		temp = temp->next;
	}
}

void	create_list(t_main *m, t_gfx *g)
{
	int		x;
	int		y;
	int		x_incr;
	int		y_incr;
	t_info	inf;

	x = 0;
	y = 0;
	x_incr = (SCR_X / (m->nb));
	y_incr = SCR_Y / (m->lines);
	while (y != m->lines)
	{
		while (x != m->nb)
		{
			inf.x = x;
			inf.y = y;
			inf.x_incr = x_incr;
			inf.y_incr = y_incr;
			inf.height = (m->data_int)[y][x];
			create_new_elem(&inf , &m);
			x++;
		}
		x = 0;
		y++;
	}
//	print_list(&m);
}

void		draw_lines(t_color *col, t_gfx **g, t_pos *t, t_pos *t2)
{
	int		x;
	int		y;
	int		i;
	char	*temp;

	i = 0;
	x = t->x;
	printf("TOTO\n");
	if ((t->x <= t2->x) && ((t2->x - t->x) >= fabs((double)(t2->y - t->y))))
	{
		while (1)
		{
			if ((t->y - t2->y) < 0)
			{
//				x = t2->x;
				printf("case1\n");
				while (x <= t2->x)
				{
					temp = (*g)->add_img;
					i = (*((*g)->bpx) / 8) * ((x)) + ((*(*g)->sz_ln) * (((t2->y - t->y) / (t2->x - t->x)) * (x - t->x) + t->y)); // only change
					temp = temp += i;
					*temp = col->b;
					temp++;
					*temp = col->g;
					temp++;
					*temp = col->r;
					temp = (*g)->add_img;
					x++;
					mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//					sleep(1);
				}

			}
			else
			{
				printf("case2\n");
				while (x <= t2->x)
				{
					temp = (*g)->add_img;
					i = (*((*g)->bpx) / 8) * ((x)) + ((*(*g)->sz_ln) * (((t2->y - t->y) / (t2->x - t->x)) * (x - t->x) + t->y)); // only change
//					i = (*((*g)->bpx) / 8) * ((x)) + (((*(*g)->sz_ln)) * ((t->y + ((t2->y) - (t->y)) * (x - t2->x))/((t2->x) - (t->x)))); // only change
					printf("i2: %d\n", i);
					temp = temp += i;
					*temp = col->b;
					temp++;
					*temp = col->g;
					temp++;
					*temp = col->r;
					temp = (*g)->add_img;
					x++;
					mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//					sleep(1);
				}

			}
			sleep(200);
		}
	}
	else if ((t->x > t2->x) && ((t->x - t2->x) >= fabs((double)(t->y - t2->y))))
	{
		printf("caseeeeee 2\n");
		while (1)
		{
			if ((t->y - t2->y) < 0)
			{
//				x = t2->x;
				while (x > t2->x)
				{
					temp = (*g)->add_img;
					i = (*((*g)->bpx) / 8) * ((x)) + ((*(*g)->sz_ln) * (((t2->y - t->y) / (t2->x - t->x)) * (x - t->x) + t->y)); // only change
					printf("i: %d\n", i);
					temp = temp += i;
					*temp = col->b;
					temp++;
					*temp = col->g;
					temp++;
					*temp = col->r;
					temp = (*g)->add_img;
					x--;
					mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//					sleep(1);
				}

			}
			else
			{
				while (x > t2->x)
				{
					temp = (*g)->add_img;
					i = (*((*g)->bpx) / 8) * ((x)) + (((*(*g)->sz_ln)) * ((t->y + ((t2->y) - (t->y)) * (x - t2->x))/((t2->x) - (t->x)))); // only change
					printf("i2: %d\n", i);
					temp = temp += i;
					*temp = col->b;
					temp++;
					*temp = col->g;
					temp++;
					*temp = col->r;
					temp = (*g)->add_img;
					x--;
					mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//					sleep(1);
				}

			}
			sleep(200);
		}
	}
	else
	{
		printf("ERROR101\n");
		y = t->y;
		while (y > t2->y)
		{
			temp = (*g)->add_img;
//			i = (*((*g)->bpx) / 8) * (((t2->x - t->x) / (t2->y - t->y)) * (y - t->y) + t->x) + ((*(*g)->sz_ln) * (y)); // only change
//			i = (*((*g)->bpx) / 8) * ((y)) + ((*(*g)->sz_ln) * (((t2->x - t->x) / (t2->y - t->y)) * (y - t->y) + t->x)); // only change
			i = (*((*g)->bpx) / 8) * ((y)) + ((*(*g)->sz_ln) * (((t2->x - t->x) / (t2->y - t->y)) * (y - t->y) + t->x)); // only change
			printf("%d\n", i);
			temp = temp += i;
			*temp = col->b;
			temp++;
			*temp = col->g;
			temp++;
			*temp = col->r;
			temp = (*g)->add_img;
			y--;
			mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
		}
		sleep(100);
	}
}

void		tile_dots(t_main **m, t_gfx **g, t_color **col, t_list **node)
{
	char	*temp;
	int		i;
	int		sx;
	int		sy;

	sx = (500 * (((*node)->x_1.x) - 500)) / (500 + (10) + 500);
	sx += 253;
	sy = (500 * (((*node)->x_1.y) - 500)) / (500 + ((*node)->x_1.y) + 500);
	sy += 250;
	printf("sx: %d sy: %d\n", sx, sy);
	if (sx < 0 || sy < 0)
		return;
//	temp = (*g)->add_img;
//	i = (*((*g)->bpx) / 8) * ((x->x)) + (((*(*g)->sz_ln)) * ((x->y)));
//	temp = temp += i;
//	*temp = (*col)->b;
//	temp++;
//	*temp = (*col)->g;
//	temp++;
//	*temp = (*col)->r;
//	temp = (*g)->add_img;
}


void	corners(t_main **m, t_gfx **g, t_list **node, t_color **col)
{
	if ((*node)->height == 0)
	{
		(*col)->r = 255;
		(*col)->g = 0;
		(*col)->b = 255;
	}
	else
	{
		(*col)->r = 0;
		(*col)->g = 0;
		(*col)->b = 255;
	}
//	tile_dots(m, g, col, node);
	*node = (*node)->next;
}

void	draw(t_main **m, t_gfx **g, t_list **node, t_color *col)
{
	int	i;

	i = 0;
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
//		while (i != 9)
//		{
//			(*node) = (*node)->next;
//			i++;
//			if (i == 9)
//				break;
//		}
//		printf("x_1: %d,%d x_2: %d,%d x_3: %d,%d x_4: %d,%d\n", (*node)->x_1.x, (*node)->x_1.y, (*node)->x_2.x, (*node)->x_2.y, (*node)->x_3.x, (*node)->x_3.y, (*node)->x_4.x, (*node)->x_4.y);
		corners(m, g, node, &col);
		while (*node != (*m)->start)
//		{
			corners(m, g, node, &col);
//		}
		mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//		printf("m->j - (sz_ln * 2): %d\n", m->j - (*(g->sz_ln) * 2));
		sleep(100);
	}
}

void	init_gfx(t_main *m, t_gfx *g)
{
	int		x = m->nb * 10;
	int		y = m->lines * 10;
	int		i = 0;
	t_color	color1;
	char 	*temp;
	t_list	*node;
	t_pos	tst;
	t_pos	tst2;

	tst.x = 125;
	tst.y = 500;
	tst2.x = 250;
	tst2.y = 250;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, SCR_X , SCR_Y, "mywindow");
	g->img = mlx_new_image(g->mlx, SCR_X, SCR_Y);
//	printf("x: %d, y: %d \n", x, y);
	g->add_img = mlx_get_data_addr(g->img, g->bpx, g->sz_ln, g->ndian);
	temp = g->add_img;
	node = m->start;
	color1.r = 255;
	color1.g = 0;
	color1.b = 255;
	draw_lines(&color1, &g, &tst, &tst2);
//	draw(&m, &g, &node, &color1);
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
