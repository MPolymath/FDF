/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 20:06:54 by mdiouf            #+#    #+#             */
/*   Updated: 2015/01/22 21:11:29 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
#define	FDF_H
typedef struct	s_main
{
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
	char			*bng_img;
}				t_gfx;
#endif
