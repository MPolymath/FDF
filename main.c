/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:05 by mdiouf            #+#    #+#             */
/*   Updated: 2015/02/12 02:14:31 by mdiouf           ###   ########.fr       */
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

void	cr_frst(t_main **m, t_list **elem, t_list **elem2)
{
	(*elem)->prev = NULL;
	(*elem)->next = NULL;
	(*m)->start = *elem;
	(*elem2)->prev = NULL;
	(*elem2)->next = NULL;
	(*m)->start2 = *elem2;
}

void	if_nt_frst(t_list **elem, t_list **elem2, t_list **temp, t_main **m)
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

	*temp = (*m)->start2;
	if ((*temp)->next == NULL)
	{
		(*temp)->next = *elem2;
		(*temp)->prev = *elem2;
		(*elem2)->next = *temp;
		(*elem2)->prev = *temp;
	}
	else
	{
		*temp = (*temp)->next;
		while ((*temp)->next != (*m)->start2)
			*temp = (*temp)->next;
		(*temp)->next = *elem2;
		(*elem2)->prev = *temp;
		(*elem2)->next = (*m)->start2;
		(*m)->start->prev = *elem2;
	}
}

void	create_new_elem(t_info *inf, t_main **m)
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*temp;

	elem = malloc(sizeof(t_list));
	elem2 = malloc(sizeof(t_list));
	elem->x_1.x = (inf->x * inf->x_incr);
	elem->x_1.y = (inf->y * inf->y_incr);
	elem->x_2.x = ((inf->x + 1) * inf->x_incr);
	elem->x_2.y = (inf->y * inf->y_incr);
	elem->x_3.x = (inf->x  * inf->x_incr);
	elem->x_3.y = ((inf->y + 1) * inf->y_incr);
	elem->x_4.x = ((inf->x + 1)  * inf->x_incr);
	elem->x_4.y = ((inf->y + 1) * inf->y_incr);
	elem->height = inf->height;
	elem->x_1.height = inf->height;
	elem->x_2.height = inf->height;
	elem->x_3.height = inf->height;
	elem->x_4.height = inf->height;

	elem2->x_1.x = (inf->x * inf->x_incr);
	elem2->x_1.y = (inf->y * inf->y_incr);
	elem2->x_2.x = ((inf->x + 1) * inf->x_incr);
	elem2->x_2.y = (inf->y * inf->y_incr);
	elem2->x_3.x = (inf->x  * inf->x_incr);
	elem2->x_3.y = ((inf->y + 1) * inf->y_incr);
	elem2->x_4.x = ((inf->x + 1)  * inf->x_incr);
	elem2->x_4.y = ((inf->y + 1) * inf->y_incr);
	elem2->height = inf->height;
	elem2->x_1.height = inf->height;
	elem2->x_2.height = inf->height;
	elem2->x_3.height = inf->height;
	elem2->x_4.height = inf->height;
	if (inf->x == 0 && inf->y == 0)
		cr_frst(m, &elem, &elem2);
	else
		if_nt_frst(&elem, &elem2, &temp, m);
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
	x_incr = ((SCR_X - 1) / (m->nb));
	y_incr = (SCR_Y - 1) / (m->lines);
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

t_pos		rot(t_pos *t, int a, int height)
{
	t_pos	temp;

	temp = *t;
	temp.x = (int)((temp.x * acos(a)) - (temp.y * asin(a)));
	temp.y = (int)(temp.x * asin(a) + temp.y * acos(a));
	temp.height = height;
	return (temp);
}

int			sx(int x, int height)
{
	x = ((640 * (x - 160)) / (640 + height)) + 160;
	return (x);
}

int			sy(int y, int height)
{
	y = ((640 * (y - 100)) / (640 + height)) + 100;
	return (y);
}

void		rot_mat_fill(t_rmat *m_final, double ax, double ay, double az)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	f;
	double	ad;
	double	bd;

	a = cos(ax);
	b = sin(ax);
	c = cos(ay);
	d = cos(ay);
	e = cos(az);
	f = sin(az);
	ad = a * d;
	bd = b * d;
	(*m_final).mt[0][0] = c * e;
	(*m_final).mt[0][1] = (c * -1) * f;
	(*m_final).mt[0][2] = d;
	(*m_final).mt[0][3] = 0;
	(*m_final).mt[1][0] = bd * e + (a * f);
	(*m_final).mt[1][1] = (-1 * bd) * f + (a * e);
	(*m_final).mt[1][2] = (-1 * b) * c;
	(*m_final).mt[1][3] = 0;
	(*m_final).mt[2][0] = (-1 * ad) * e + (b * f);
	(*m_final).mt[2][1] = ad * f + (b * e);
	(*m_final).mt[2][2] = a * c;
	(*m_final).mt[2][3] = 0;
	(*m_final).mt[3][0] = 0;
	(*m_final).mt[3][1] = 0;
	(*m_final).mt[3][2] = 0;
	(*m_final).mt[3][3] = 1;

}

void		conv_pos(t_pos *pos, t_gfx **g)
{
	int	x;
	int	y;
	int z;

	x = (int)(((m_final.mt[0][0]) * pos->x) + (m_final.mt[0][1] * pos->y) + (m_final.mt[0][2] * pos->height));
	y = (int)(((m_final.mt[1][0]) * pos->x) + (m_final.mt[1][1] * pos->y) + (m_final.mt[1][2] * pos->height));
	z = (int)(((m_final.mt[2][0]) * pos->x) + (m_final.mt[2][1] * t->y) + (m_final.mt[2][2] * pos->height));
	pos->x = x;
	pos->y = y;
	pos->height = z;
}

void		convert_list2(t_main **m, t_gfx **g)
{
	t_list	*temp;
	t_list	*temp2;
	int		cycle;

	cycle = 0;
	temp = (*m)->start;
	temp2 = (*m)->start2;
	temp = temp->next;
	while (temp != (*m)->start)
	{
		*temp2 = *temp;
		if (cycle == 0)
		{
			temp = (*m)->start;
			cycle = 1;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	cycle = 0;
	temp2 = (*m)->start2;
	temp2 = temp2->next;
	rot_mat_fill(&m_final, 25, 0, 0);
	while (temp2 != (*m)->start2)
	{
		if (cycle == 0)
		{
			temp2 = (*m)->start2;
			cycle = 1;
		}
		conv_pos(&(temp2->x_1), g));
		conv_pos(&(temp2->x_2), g));
		conv_pos(&(temp2->x_3), g));
		conv_pos(&(temp2->x_4), g));
		temp2 = temp2->next;
	}
}

void		draw_lines(t_color *col, t_gfx **g, t_pos *t, t_pos *t2)
{
	int		x;
	int		y;
	int		i;
	int		ch;
	t_pos	*tpos;
	t_pos	coord;
	t_pos	coord2;
	t_rmat	m_final;
//	t_rmat	xyz;
//	t_rmat	my;
//	t_rmat	mz;
	char	*temp;
	i = 0;
//	tpos = t;
//	t = t2;
//	t2 = tpos;
//	ch = 0;
//	coord = rot(t, .2, t->height);
//	coord2 = rot(t2, .2, t->height);
//	printf("%d,%d\n", coord.x, coord.y);
//	printf("%d,%d\n", coord2.x, coord2.y);
	coord = *t;
	coord2 = *t2;
	x = coord.x;
    rot_mat_fill(&m_final, 25, 0, 0);
    coord.x = (int)(((m_final.mt[0][0]) * t->x) + (m_final.mt[0][1] * t->y) + (m_final.mt[0][2] * t->height\
						));
    coord.y = (int)(((m_final.mt[1][0]) * t->x) + (m_final.mt[1][1] * t->y) + (m_final.mt[1][2] * t->height\
						));
    coord.height = (int)(((m_final.mt[2][0]) * t->x) + (m_final.mt[2][1] * t->y) + (m_final.mt[2][2] * t->h\
																					eight));
    coord2.x = (int)(((m_final.mt[0][0]) * t2->x) + (m_final.mt[0][1] * t2->y) + (m_final.mt[0][2] * t2->he\
																				  ight));
    coord2.y = (int)(((m_final.mt[1][0]) * t2->x) + (m_final.mt[1][1] * t2->y) + (m_final.mt[1][2] * t2->he\
																				  ight));
    coord2.height = (int)(((m_final.mt[2][0]) * t2->x) + (m_final.mt[2][1] * t2->y) + (m_final.mt[2][2] * t\
																					   2->height));
/*	i = ((*(*g)->sz_ln) * (((coord2.y - coord.y) / (coord2.x - coord.x)) * (x - coord.x) + coord.y)) + (((*(*g)->bpx) / 8) * x);
	if (i >= 0)
	{
		temp = temp += i;
		*temp = col->b;
		temp++;
		*temp = col->g;
		temp++;
		*temp = col->r;
		temp = (*g)->add_img;
	}
	x = coord2.x;
	i = ((*(*g)->sz_ln) * (((coord2.y - coord.y) / (coord2.x - coord.x)) * (x - coord.x) + coord.y)) + (((*(*g)->bpx) / 8) * x);
	if (i >= 0)
	{
		temp = temp += i;
		*temp = col->b;
		temp++;
		*temp = col->g;
		temp++;
		*temp = col->r;
		temp = (*g)->add_img;
		}*/
//	coord.x = sx(coord.x, t->height);
//	coord.y = sy(coord.y, t->height);
//	coord2.x = sx(coord2.x, t2->height);
//	coord2.y = sy(coord2.y, t2->height);
//	return;
//	sx = (500 * (((*nodes)->x_1.x) - 500)) / (500 + (10) + 500);
//	sx += 253;
//	sy = (500 * (((*node)->x_1.y) - 500)) / (500 + ((*node)->x_1.y) + 500);
//	sy += 250;
//	if ((t->x <= t2->x) && ((t2->x - t->x) >= fabs((double)(t2->y) - t->y)))
//	{
		printf("t->y: %d t->x: %d\n", t->y, t->x);
		printf("t2->y: %d t2->x: %d\n", t2->y, t2->x);
//		while (1)
//		{
			if ((coord2.y - coord.y) > 0)
			{
				if (coord2.x > coord.x)
				{
					while (x <= coord2.x)
					{
						printf("test\n");
//						if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//							break;
//						printf("case1\n");x
//						printf("t->y: %d t->x: %d\n", t->y, t->x);
//						printf("t2->y: %d t2->x: %d\n", t2->y, t2->x);
						temp = (*g)->add_img;
						i = ((*(*g)->sz_ln) * (((coord2.y - coord.y) / (coord2.x - coord.x)) * (x - coord.x) + coord.y)) + (((*(*g)->bpx) / 8) * x);
//						printf("%d\n", i);
						if (i >= 0)
						{
							temp = temp += i;
							*temp = col->b;
							temp++;
							*temp = col->g;
							temp++;
							*temp = col->r;
							temp = (*g)->add_img;
						}
						x++;
//					i = i + ((*(*g)->sz_ln));
//						mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//					sleep(1);
					}
				}
				else if (coord2.x < coord.x)
				{
					printf("test1\n");
					while (x >= coord2.x)
					{
//						if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//							break;
//						printf("case1\n");x
//						printf("t->y: %d t->x: %d\n", t->y, t->x);
//						printf("t2->y: %d t2->x: %d\n", t2->y, t2->x);
						temp = (*g)->add_img;
						i = ((*(*g)->sz_ln) * (((coord2.y - coord.y) / (coord2.x - coord.x)) * (x - coord.x) + coord.y)) + (((*(*g)->bpx) / 8) * x);
//						printf("%d\n", i);
						if (i >= 0)
						{
							temp = temp += i;
							*temp = col->b;
							temp++;
							*temp = col->g;
							temp++;
							*temp = col->r;
							temp = (*g)->add_img;
						}
						x--;
//					i = i + ((*(*g)->sz_ln));
//					mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//					sleep(1);
					}
				}
				else
				{
					x = coord.y;
					printf("test2\n");
					if (coord.y > coord2.y)
					{
						printf("one\n");
						while (x >= coord2.y)
						{
//							if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//								break;
//							printf("case1\n");x
//							printf("t->y: %d t->x: %d\n", t->y, t->x);
//							printf("t2->y: %d t2->x: %d\n", t2->y, t2->x);
							temp = (*g)->add_img;
							i = (((*(*g)->sz_ln)) * (((0) * (x - coord.y) + coord.x)) + (((*(*g)->bpx) / 8) * x));
//							i = ((*(*g)->sz_ln) * (((t2->y - t->y) / (t2->x - t->x)) * (x - t->x) + t->y)) + (((*(*g)->bpx) / 8) * x);
//							printf("%d\n", i);
							if (i >= 0)
							{
								temp = temp += i;
								*temp = col->b;
								temp++;
								*temp = col->g;
								temp++;
								*temp = col->r;
								temp = (*g)->add_img;
							}
							x--;
//							i = i + ((*(*g)->sz_ln));
//							mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//							sleep(1);
						}
					}
					else
					{
						printf("two\n");
						x = coord.y;
						while (x <= coord2.y)
						{
//							if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//								break;
//							printf("case1\n");x
//							printf("t->y: %d t->x: %d\n", t->y, t->x);
//							printf("t2->y: %d t2->x: %d\n", t2->y, t2->x);
							temp = (*g)->add_img;
							i = (((*(*g)->bpx / 8)) * (((0) * (x - coord.y) + coord.x)) + (((*(*g)->sz_ln)) * x));
//							i = ((*(*g)->sz_ln) * (((t2->y - t->y) / (t2->x - t->x)) * (x - t->x) + t->y)) + (((*(*g)->bpx) / 8) * x);
//							printf("%d\n", i);
							if (i >= 0)
							{
								temp = temp += i;
								*temp = col->b;
								temp++;
								*temp = col->g;
								temp++;
								*temp = col->r;
								temp = (*g)->add_img;
							}
							x++;
//							i = i + ((*(*g)->sz_ln));
//							mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
//							sleep(1);
						}
					}
				}
			}
			else
			{
//				x = t->y;
				x = coord.y;
//				i = ((*(*g)->bpx / 8) * (((t2->y - t->y) / (t2->x - t->x)) * (x - t->y) + t->x)) + ((*(*g)->sz_ln) * x);
//				x = t->x;
//				printf("case2\n");
//				printf("t->y: %d t->x: %d\n", t->y, t->x);
//				printf("t2->y: %d t2->x: %d\n", t2->y, t2->x);
				if (coord2.y > coord.y)
				{
//					printf("test11\n");
					while (x <= coord2.y)
					{
//						if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//							break;
						temp = (*g)->add_img;
						i = (((*(*g)->bpx) / 8) * (((coord2.x - coord.x) / (coord2.y - coord.y)) * (x - coord.y) + coord.x)) + ((*(*g)->sz_ln) * x);
//						printf("%d\n", i);
						if (i >= 0)
						{
							temp = temp += i;
							*temp = col->b;
							temp++;
							*temp = col->g;
							temp++;
							*temp = col->r;
							temp = (*g)->add_img;
						}
						x++;
//						i = i + ((*(*g)->bpx) / 8);
//						mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
					}
				}
				else if (coord2.y < coord.y)
				{
					printf("test22\n");
					x = coord.y;
					while (x >= coord2.y)
					{
//						if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//							break;
						temp = (*g)->add_img;
						i = (((*(*g)->bpx / 8)) * (((coord2.x - coord.x) / (coord2.y - coord.y)) * (x - coord.y) + coord.x)) + ((*(*g)->sz_ln) * x);
//						printf("%d\n", i);
						if (i >= 0)
						{
							temp = temp += i;
							*temp = col->b;
							temp++;
							*temp = col->g;
							temp++;
							*temp = col->r;
							temp = (*g)->add_img;
						}
						x--;
//						i = i + ((*(*g)->bpx) / 8);
//						mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
					}

				}
				else
				{
					x = coord.x;
					printf("test33\n");
					if (coord2.x > coord.x)
					{
						while (x <= coord2.x)
						{
//							if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//								break;
							temp = (*g)->add_img;
							i = (((*(*g)->sz_ln)) * (((0) * (x - coord.x) + (coord.y))) + (((*(*g)->bpx) / 8) * x));
//							printf("%d\n", i);
							if (i >= 0)
							{
								temp = temp += i;
								*temp = col->b;
								temp++;
								*temp = col->g;
								temp++;
								*temp = col->r;
								temp = (*g)->add_img;
							}
							x++;
//							i = i + ((*(*g)->bpx) / 8);
//							mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
						}
					}
					else
					{
						printf("TOTO\n");
						while (x >= coord2.x)
						{
//							if (x > SCR_X || coord.x > SCR_X || coord.y > SCR_Y)
//								break;
							temp = (*g)->add_img;
							i = (((*(*g)->sz_ln)) * (((0) * (x - coord.x) + (coord.y))) + (((*(*g)->bpx) / 8) * x));
//							printf("%d\n", i);
							if (i >= 0)
							{
								temp = temp += i;
								*temp = col->b;
								temp++;
								*temp = col->g;
								temp++;
								*temp = col->r;
								temp = (*g)->add_img;
							}
							x--;
//							i = i + ((*(*g)->bpx) / 8);
//							mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->img, 0, 0);
						}
					}
//				}
//				printf("%d\n", t->y);
				}
		printf("%d %d %d %d\n", m_final.mt[0][0], m_final.mt[0][1], m_final.mt[0][2], m_final.mt[0][3]);
		printf("%d %d %d %d\n", m_final.mt[1][0], m_final.mt[1][1], m_final.mt[1][2], m_final.mt[1][3]);
		printf("%d %d %d %d\n", m_final.mt[2][0], m_final.mt[2][1], m_final.mt[2][2], m_final.mt[2][3]);
		printf("%d %d %d %d\n", m_final.mt[3][0], m_final.mt[3][1], m_final.mt[3][2], m_final.mt[3][3]);
		printf("coord.x: %d  coord.y: %d coord.z: %d\n", coord.x, coord.y, coord.height);
		printf("coord2.x: %d  coord2.y: %d coord2.z: %d\n", coord2.x, coord2.y, coord2.height);
		}
//	}
}

void		tile_dots(t_main **m, t_gfx **g, t_color **col, t_list **node)
{
	char	*temp;
	int		i;
	int		sx;
	int		sy;

//	sx = (500 * (((*node)->x_1.x) - 500)) / (500 + (10) + 500);
//	sx += 253;
//	sy = (500 * (((*node)->x_1.y) - 500)) / (500 + ((*node)->x_1.y) + 500);
//	sy += 250;
//	printf("sx: %d sy: %d\n", sx, sy);
//	if (sx < 0 || sy < 0)
//		return;
//	printf("x_1: %d,%d x_2: %d,%d x_3: %d,%d x_4: %d,%d\n", (*node)->x_1.x,(*node)->x_1.y,(*node)->x_2.x,(*node)->x_2.y,(*node)->x_3.x,(*node)->x_3.y, (*node)->x_4.x,(*node)->x_4.y);
	draw_lines(*col, g, &(*node)->x_1, &(*node)->x_2);
	draw_lines(*col, g, &(*node)->x_2, &(*node)->x_4);
	draw_lines(*col, g, &(*node)->x_1, &(*node)->x_3);
	draw_lines(*col, g, &(*node)->x_3, &(*node)->x_4);
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
	tile_dots(m, g, col, node);
}

void	draw(t_main **m, t_gfx **g, t_list **node, t_color *col)
{
	int	i;
	t_list	temp;
	t_list	*ptr = &temp;

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
		*node = (*node)->next;
		while (*node != (*m)->start)
		{
//			if ((*node)->next != (*m)->start  /*&& (((*node)->next->height > (*node)->height) ||*//*((*node)->next->height < (*node)->height))*/)
//			{
//				temp.x_1 = (*node)->x_1;
//				temp.x_2 = (*node)->next->x_2;
//				temp.x_3 = (*node)->x_3;
//				temp.x_4 = (*node)->next->x_4;
//				temp.height = (*node)->height;
//				corners(m, g, &ptr, &col);
//				*node = (*node)->next;
//			}
//			else
				corners(m, g, node, &col);
			*node = (*node)->next;
		}
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

	tst.x = 0;
	tst.y = 250;
	tst2.x = 500;
	tst2.y = 0;
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
//	while (1)
//	{
//		draw_lines(&color1, &g, &tst, &tst2);
//		mlx_put_image_to_window((g)->mlx, (g)->win, (g)->img, 0, 0);
//		sleep(1000);
//	}
	draw(&m, &g, &node, &color1);
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
