/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:05 by mdiouf            #+#    #+#             */
/*   Updated: 2015/01/22 21:12:07 by mdiouf           ###   ########.fr       */
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
	m->line = NULL;
	m->join_lines = NULL;
	m->data_nb = NULL;
	m->data_int = NULL;
	m->data_char = NULL;
	g->mlx = NULL;
	g->win = NULL;
	g->img = NULL;
	g->bng_img = NULL;
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
