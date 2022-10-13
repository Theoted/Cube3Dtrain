/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/07 12:09:01 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# define PI 3.14159265359

typedef struct	s_pos		t_pos;
typedef struct  s_char		t_char;
typedef struct  s_mlx_data	t_mlx_data;

struct t_pos
{
	int	x;
	int	y;	
};

struct  t_char
{
	int		px;
	int		py;
	int		pdx;
	int		pdy;
	int		pa;
};

struct  s_mlx_data
{
	void            *mlx_win;
	void            *mlx_ptr;
	char            **matrix;
	int				init;
	struct t_char   char_pos;
};


// INIT
void	init_mlx(t_mlx_data *data);

// DRAW
void    draw_map(t_mlx_data *data);
void    draw_player1(t_mlx_data *data, int x, int y);
int 	_bresenham(t_mlx_data *data, int x0, int y0, int x1, int y1);

// TESTS
char    **init_matrix_test(char **matrix);

#endif