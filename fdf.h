/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 20:06:54 by mdiouf            #+#    #+#             */
/*   Updated: 2015/01/28 18:06:57 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
#define	FDF_H
#define SCR_X 500
#define SCR_Y 500

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_info
{
	int				x;
	int				y;
	int				x_incr;
	int				y_incr;
	int				height;
}				t_info;
typedef struct	s_pos
{
	int				x;
	int				y;
}				t_pos;

typedef struct	s_list
{
	t_pos			x_1;
	t_pos			x_2;
	t_pos			x_3;
	t_pos			x_4;
	int				height;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_main
{
	int				fd;
	int				nb;
	int				i;
	int				j;
	int				**data_int;
	char			**data_char;
	char			**data_nb;
	char			lines;
	char			*line;
	char			*join_lines;
	t_list			*start;
}				t_main;

typedef struct	s_gfx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bit_pp;
	int				*bpx;
	int				size;
	int				*sz_ln;
	int				endian;
	int				*ndian;
	int				k;
	int				n;
	unsigned int	color;
	char			*add_img;
}				t_gfx;
#endif
