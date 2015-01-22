/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:05 by mdiouf            #+#    #+#             */
/*   Updated: 2015/01/22 18:30:37 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

//#include <mlx.h>
//#include <stdio.h>
int			ft_valid_number(char **line, int *nb)
{
	int		i;
	int		j;
	char	**split;

	split = NULL;
	split = ft_strsplit(*line, ' ');
	i = 0;
	j = 0;
	while (split[i] != NULL)
	{
		while (split[i][j] != '\0')
		{
			if (split[i][j] != ' ' && split[i][j] != '\n' &&
				(split[i][j] < 48 || split[i][j] > 57))
			{
				free(*line);
				free(split);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if ((*nb != 0) && *nb != i)
	{
		free(*line);
		free(split);
		return (-1);
	}
	*nb = i;
	return (0);
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
	int			fd;
	int			nb;
	int			i;
	int			j;
	int			**data_int;
	char		**data_char;
	char		**data_nb;
	char		lines;
	char		*line;
	char		*join_lines;

	fd = open("test", O_RDONLY);
	nb = 0;
	j = 0;
	lines = 0;
	line = NULL;
	join_lines = NULL;
	data_nb = NULL;
//	read entire file check if same amount of int per lines and store all that is read
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_valid_number(&line, &nb) != -1)
		{
			join_lines = ft_strjoin(join_lines, "\n");
			join_lines = ft_strjoin(join_lines, line);
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		lines++;
		if (line != NULL)
			free(line);
	}
//	create data_int to store double array of table converted to int
	i = 0;
	data_int = malloc(sizeof(int*) * lines);
	while (i != lines)
	{
		data_int[i] = malloc(sizeof(int) * nb);
		i++;
	}
	data_int[i] = NULL;
// split join_lines
	data_char = ft_strsplit(join_lines, '\n');
	i = 0;
//	split individual numbers and stick em into new data_int array
	while (data_char[i] != NULL)
	{
		data_nb = ft_strsplit(data_char[i], ' ');
		while (data_nb[j] != NULL)
		{
			data_int[i][j] = ft_atoi(data_nb[j]);
			j++;
		}
		j = 0;
		free(data_nb);
		data_nb = NULL;
		i++;
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
	return (0);
}
